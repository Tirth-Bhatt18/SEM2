#include<stdio.h>

void main()
{
    int n1, n2, lcm=1;

    printf("\nEnter number 1: ");
    scanf("%d",&n1);

    printf("Enter number 2: ");
    scanf("%d",&n2);

    while(1)
    {
        if(lcm%n1==0 && lcm%n2==0)
        {break;}
        else
        {lcm++;}
    }

    printf("LCM of %d and %d is %d\n\n",n1 ,n2, lcm);
}