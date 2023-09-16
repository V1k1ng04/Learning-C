#include <stdio.h>

void main() {
    int a;
    int *ptr = NULL;
    //ptr = &a;
    printf("%d, %d\n", ptr, &ptr);
    printf("%p, %p\n", ptr, &ptr);
    //(*ptr)++;
    printf("%d", *&a);


}
