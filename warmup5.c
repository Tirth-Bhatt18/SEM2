#include<stdio.h>
#include<math.h>

void main()
{
    double a,b,c,x1,x2,d;

    printf("\n\nRoots of a Quadratic equation of the type ax2+bx+c=0");
    
    printf("\n\nEnter the coefficient of x2, a: ");
    scanf("%lf", &a);
    printf("Enter the coefficient of x, b: ");
    scanf("%lf", &b);
    printf("Enter the constant term, c: ");
    scanf("%lf", &c);

    d= pow(b,2)-4*a*c;
    x1= (-b + sqrt(d))/(2*a);
    x2= (-b - sqrt(d))/(2*a);

    printf("\nThe roots of the equation %.2lfx2 + %.2lfx + %lf =0 are %lf and %lf\n\n",a,b,c,x1,x2);
}