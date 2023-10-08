#include <stdio.h>
#include <stdlib.h>

int main() {
    // Demonstrate calloc
    int *callocArr = (int *)calloc(5, sizeof(int));
    printf("Demonstrating calloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", callocArr[i]);
    }
    printf("\n\n");

    // Demonstrate malloc
    int *mallocArr = (int *)malloc(3 * sizeof(int));
    printf("Demonstrating malloc:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", mallocArr[i]);
    }
    printf("\n\n");

    // Demonstrate realloc
    int *reallocArr = (int *)realloc(mallocArr, 5 * sizeof(int));
    printf("Demonstrating realloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", reallocArr[i]);
    }
    printf("\n\n");

    // Demonstrate free
    free(callocArr);
    free(reallocArr);

    printf("Memory freed.\n");

    return 0;
}
