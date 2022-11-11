#include <stdio.h>
void main()

{
    int count = 0, start, end;
    printf("Enter the starting range: ");
    scanf("%d", &start);
    printf("Enter the final range: ");
    scanf("%d", &end);
    for (int i=start; i<end; i++)
    {
        for (int j=2; j<=i; j++)
        {
            if (i == j)
                {printf("%d\n",i);
                count +=1;
                }
            else if (i%j == 0)
                break;
        }
    }
    printf("\nThere are %d prime numbers between %d and %d", count,start,end);
}
