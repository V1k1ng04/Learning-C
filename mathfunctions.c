#include<stdio.h>
#include<math.h>
void main()
{
    float num;
    int x,a,y;
    printf("Enter the value of x and y: ");
    scanf("%d%d",&x,&y);

    printf("%f\n", sqrt(x));
    printf("%f\n", exp(x));
    printf("%f\n", log(x));
    printf("%f\n", log10(x));
    printf("%f\n", fabs(x));
    printf("%f\n", ceil(x));
    printf("%f\n", floor(x));
    printf("%f\n", pow(x,y));
    printf("%f\n", fmod(x,y));
    printf("%f\n", sin(x));
    printf("%f\n", cos(x));
    printf("%f\n", tan(x));
}
