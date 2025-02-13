#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if !defined(AUTOCOMPLETE_H)
#define AUTOCOMPLETE_H

typedef struct term{
    char term[200]; // assume terms are not longer than 200
    double weight;
} term;

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

            terms[index]->weight = weight;
            strncpy(terms[index]->term, tab, 200);

            index++;
        }
    }
    fclose(file);
    //sort lexigrahpically/alphabetically
}

int lowest_match(struct term *terms, int nterms, char *substr);
//binary search (Olog(n))

int highest_match(struct term *terms, int nterms, char *substr);


void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr);

#endif