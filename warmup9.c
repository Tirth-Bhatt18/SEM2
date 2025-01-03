#include<stdio.h>
#include<math.h>

void main()
{
    float h,l,x;
    printf("\nEnter H and L: ");
    scanf("%f %f",&h,&l);

    x = pow(l,2)/h - h;
    x/=2;

    printf("The depth of the lake is %.2f units\n\n",x);
}