#include "seamcarving.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void calc_energy(struct rgb_img *im, struct rgb_img **grad) {
    int height = im->height;
    int width = im->width;
    
    create_img(grad, height, width);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int x_left = (x == 0) ? width - 1 : x - 1;
            int x_right = (x == width - 1) ? 0 : x + 1;
            
            int rx_diff = get_pixel(im, y, x_right, 0) - get_pixel(im, y, x_left, 0);
            int gx_diff = get_pixel(im, y, x_right, 1) - get_pixel(im, y, x_left, 1);
            int bx_diff = get_pixel(im, y, x_right, 2) - get_pixel(im, y, x_left, 2);
            
            int y_up = (y == 0) ? height - 1 : y - 1;
            int y_down = (y == height - 1) ? 0 : y + 1;
            
            int ry_diff = get_pixel(im, y_down, x, 0) - get_pixel(im, y_up, x, 0);
            int gy_diff = get_pixel(im, y_down, x, 1) - get_pixel(im, y_up, x, 1);
            int by_diff = get_pixel(im, y_down, x, 2) - get_pixel(im, y_up, x, 2);
            
            double delta_x = rx_diff * rx_diff + gx_diff * gx_diff + bx_diff * bx_diff;
            double delta_y = ry_diff * ry_diff + gy_diff * gy_diff + by_diff * by_diff;
            double energy = sqrt(delta_x + delta_y);
            
            uint8_t energy_val = (uint8_t)(energy / 10);
            
            set_pixel(*grad, y, x, energy_val, energy_val, energy_val);
        }
    }
}

void dynamic_seam(struct rgb_img *grad, double **best_arr) {
    int height = grad->height;
    int width = grad->width;
    
    *best_arr = (double *)malloc(height * width * sizeof(double));
    
    for (int x = 0; x < width; x++) {
        (*best_arr)[0 * width + x] = get_pixel(grad, 0, x, 0);
    }
    
    for (int y = 1; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double current_energy = get_pixel(grad, y, x, 0);
            
            double min_energy;
            
            min_energy = (*best_arr)[(y-1) * width + x];
            
            if (x > 0) {
                double left_energy = (*best_arr)[(y-1) * width + (x-1)];
                if (left_energy < min_energy) {
                    min_energy = left_energy;
                }
            }
            
            if (x < width - 1) {
                double right_energy = (*best_arr)[(y-1) * width + (x+1)];
                if (right_energy < min_energy) {
                    min_energy = right_energy;
                }
            }
            
            (*best_arr)[y * width + x] = current_energy + min_energy;
        }
    }
}

void recover_path(double *best, int height, int width, int **path) {
    *path = (int *)malloc(height * sizeof(int));
    
    double min_energy = best[(height-1) * width];
    int min_index = 0;
    
    for (int x = 1; x < width; x++) {
        if (best[(height-1) * width + x] < min_energy) {
            min_energy = best[(height-1) * width + x];
            min_index = x;
        }
    }
    
    (*path)[height-1] = min_index;
    
    for (int y = height - 2; y >= 0; y--) {
        int x = (*path)[y+1];
        int min_index = x;
        double min_energy;
        
        if (x > 0) {
            min_energy = best[y * width + (x-1)];
            min_index = x - 1;
        } else {
            min_energy = best[y * width + x];
        }
        
        if (best[y * width + x] < min_energy) {
            min_energy = best[y * width + x];
            min_index = x;
        }
        
        if (x < width - 1 && best[y * width + (x+1)] < min_energy) {
            min_energy = best[y * width + (x+1)];
            min_index = x + 1;
        }
        
        (*path)[y] = min_index;
    }
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path) {
    int height = src->height;
    int width = src->width;
    
    create_img(dest, height, width - 1);
    
    for (int y = 0; y < height; y++) {
        int seam_x = path[y];
        
        for (int x = 0; x < seam_x; x++) {
            uint8_t r = get_pixel(src, y, x, 0);
            uint8_t g = get_pixel(src, y, x, 1);
            uint8_t b = get_pixel(src, y, x, 2);
            
            set_pixel(*dest, y, x, r, g, b);
        }
        
        for (int x = seam_x + 1; x < width; x++) {
            uint8_t r = get_pixel(src, y, x, 0);
            uint8_t g = get_pixel(src, y, x, 1);
            uint8_t b = get_pixel(src, y, x, 2);
            
            set_pixel(*dest, y, x - 1, r, g, b);
        }
    }
}

struct rgb_img *im;
struct rgb_img *cur_im;
struct rgb_img *grad;
double *best;
int *path;

int main(void){
    read_in_img(&im, "HJoceanSmall.bin");
    
    for(int i = 0; i < 100; i++){
        printf("i = %d\n", i);
        calc_energy(im,  &grad);
        dynamic_seam(grad, &best);
        recover_path(best, grad->height, grad->width, &path);
        remove_seam(im, &cur_im, path);

        char filename[200];
        sprintf(filename, "img%d.bin", i);
        write_img(cur_im, filename);


        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
    }
    destroy_image(im);
}