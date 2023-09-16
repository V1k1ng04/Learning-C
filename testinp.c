#include<stdio.h>

void main()
{
    int a,b,c,d;
    int i,n;

    printf("Enter no. of strings: ");  //input the strings
    scanf("%d", &n);


    char arr[n][100];

    for(i=0; i<n; i++)
    {
        scanf("%99s", arr[i]);
    }
}
