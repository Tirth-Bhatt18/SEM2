#include<stdio.h>

void main()
{
    int a,m,n,i,j;

    printf("\nEnter both the side lenths m & n and the side length a:\n");
    scanf("%d",&m);
    scanf("%d",&n);
    scanf("%d",&a);

    if(m%a == 0)
    i = m/a;
    else
    i = m/a + 1;
    
    if(n%a == 0)
    j = n/a;
    else
    j = n/a + 1;

    printf("The number of tiles needed are: %d\n\n",i*j);
}