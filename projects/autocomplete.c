#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if !defined(AUTOCOMPLETE_H)
#define AUTOCOMPLETE_H

typedef struct term{
    char term[200]; // assume terms are not longer than 200
    double weight;
} term;

//comparison function for qsort
int compare_terms(const void *a, const void *b) {
    const struct term *term_a = (const struct term *)a;
    const struct term *term_b = (const struct term *)b;
    
    // Compare the term strings lexicographically using strcmp
    return strcmp(term_a->term, term_b->term);
}
//allocate memory for all terms in file 
// store pointer to block in *terms
// 2. store number of terms in *pnterms
//read in all terms from the file given, then place in block pointed to by *terms
// terms shoupld be sorted in lexocographic order (i.e. alphabetical)
void read_in_terms(struct term **terms, int *pnterms, char *filename){
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int line_count = 0; //number of lines tracker
    while (fgets(line, sizeof(line), file)) {
        if (strchr(line, '\t') != NULL) {  // Check if line contains a tab
            line_count++;
        }
    }

    //store count in pnterms
    *pnterms = line_count;

    //allocate memory for terms
    *terms = (term *)malloc(line_count * sizeof(term));

    //now populate terms block
    rewind(file);
    int index = 0;
    
    while (fgets(line, sizeof(line), file)){
        char *tab = strchr(line, '\t');
        if (tab != NULL){
            *tab = '\0';
            tab++;

            double weight = atof(line);
            char *newline = strchr(tab, '\n');
            if (newline != NULL){
                *newline = '\0';
            }

            (*terms)[index].weight = weight;
            strncpy((*terms)[index].term, tab, 200);

            index++;
        }
    }
    fclose(file);
    //sort lexigrahpically/alphabetically
    qsort(*terms, *pnterms, sizeof(term), compare_terms);
}
// The function returns the index in terms of the first term in lexicographic ordering that matches the
// string substr.
// This function must run in O(log(nterms)) time, where nterms is the number of terms in terms.
// You can assume that terms is sorted in ascending lexicographic order
int lowest_match(struct term *terms, int nterms, char *substr){
    int L = 0;
    int R = nterms - 1;
    while (L <= R){
        int mid = (L + R)/2;
        if (strncmp(terms[mid].term, substr, strlen(substr)) == 0){
            if (mid == 0 || strncmp(terms[mid-1].term, substr, strlen(substr)) != 0){
                return mid;
            }
            R = mid - 1;
        }
        else if (strncmp(terms[mid].term, substr, strlen(substr)) > 0){
            R = mid - 1;
        }
        else if (strncmp(terms[mid].term, substr, strlen(substr)) < 0){
            L = mid + 1;
        }
    }
    return -1;
}
//binary search (Olog(n))
int highest_match(struct term *terms, int nterms, char *substr){
    int L = 0;
    int R = nterms - 1;
    while (L <= R){
        int mid = (L + R)/2;
        if (strncmp(terms[mid].term, substr, strlen(substr)) == 0){
            if (mid == nterms - 1 || strncmp(terms[mid+1].term, substr, strlen(substr)) != 0){
                return mid;
            }
            L = mid + 1;
        }
        else if (strncmp(terms[mid].term, substr, strlen(substr)) > 0){
            R = mid - 1;
        }
        else if (strncmp(terms[mid].term, substr, strlen(substr)) < 0){
            L = mid + 1;
        }
    }
    return -1;
}

int compare_weight(const void *a, const void *b){
    const struct term *term_a = (const struct term *)a;
    const struct term *term_b = (const struct term *)b;

    if (term_a->weight > term_b->weight){
        return 1;
    }
    else if (term_b->weight > term_a->weight){
        return -1;
    }
    else {
        return 0;
    }
}
//The answers should be sorted by weight in non-decreasing order.
void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr){
    int first = lowest_match(terms, nterms, substr);
    int last = highest_match(terms, nterms, substr);

    if (first == -1 || last == -1){
        *n_answer = 0;
        *answer = NULL;
        return;
    }

    *n_answer = last - first + 1;
    *answer = (term *)malloc(*n_answer * sizeof(term));
    for (int i = 0; i < *n_answer; i++){
        (*answer)[i] = terms[first + i];
    }
    qsort(*answer, *n_answer, sizeof(term), compare_weight);
}
#endif