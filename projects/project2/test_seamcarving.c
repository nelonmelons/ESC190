#include <stdio.h>
#include "seamcarving.h"

int main() {
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "HJoceanSmall.bin");
    
    for(int i = 0; i < 400; i++){
        printf("i = %d\n", i);
        calc_energy(im, &grad);
        dynamic_seam(grad, &best);
        recover_path(best, grad->height, grad->width, &path);
        remove_seam(im, &cur_im, path);

        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
    }
    char filename[200];
    sprintf(filename, "out.bin");
    write_img(cur_im, filename);
    
    destroy_image(im);
    
    return 0;
}