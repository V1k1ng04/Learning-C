#include <stdio.h>
void main()

{
    int count = 0;
    for (int i=2; i<100; i++)
    {
        for (int j=2; j<=i; j++)   
        {
            if (i == j)  
                {printf("%d\n",i);
                count += 1;}
            else if (i%j == 0)
                break;
        }
    }
    printf("\nThere are %d prime numbers between 1 and 100.", count);
}
