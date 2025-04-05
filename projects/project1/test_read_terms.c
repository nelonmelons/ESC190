#include "autocomplete.h"

void print_terms(struct term *terms, int nterms) {
    printf("Number of terms: %d\n", nterms);
    for (int i = 0; i < nterms; i++) {
        printf("Term %d: weight = %f, term = '%s'\n", i, terms[i].weight, terms[i].term);
    }
}
void test_lowest_match() {
    struct term *terms;
    int nterms;
    read_in_terms(&terms, &nterms, "cities.txt");

    // Test cases
    printf("\nTesting lowest_match:\n");
    
    // Test case 1: Common prefix
    char *substr1 = "To";
    int result1 = lowest_match(terms, nterms, substr1);
    printf("Lowest match for '%s': %s (index: %d)\n", 
           substr1, terms[result1].term, result1);

    // Test case 2: Single character
    char *substr2 = "B";
    int result2 = lowest_match(terms, nterms, substr2);
    printf("Lowest match for '%s': %s (index: %d)\n", 
           substr2, terms[result2].term, result2);

    // Test case 3: Longer prefix
    char *substr3 = "San";
    int result3 = lowest_match(terms, nterms, substr3);
    printf("Lowest match for '%s': %s (index: %d)\n", 
           substr3, terms[result3].term, result3);

    free(terms);
}

int main() {
    struct term *terms = NULL;
    int nterms = 0;
    
    // Test with a small sample file
    read_in_terms(&terms, &nterms, "test_cities.txt");
    
    // Print results
    print_terms(terms, nterms);
    test_lowest_match();
    // Free allocated memory
    free(terms);
    
    return 0;
} 