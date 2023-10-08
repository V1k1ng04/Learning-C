#include <stdio.h>
#include <string.h>

void sortStrings(char *strings[], int n) {
    int i, j;
    char *temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

void main()
{
    char input[100][50];
    char *strings[50];
    int n, i;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", input[i]);

        // Point to the input string
        strings[i] = input[i];
    }

    sortStrings(strings, n);

    printf("\nSorted strings:\n");

    for (i = 0; i < n; i++)
    {
        printf("%s\n", strings[i]);
    }
}



