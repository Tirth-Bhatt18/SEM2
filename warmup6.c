#include<stdio.h>
#include<string.h>

void main()
{
    int b1, b2, i=0, j=0, n=0,j1;
    int b[25],o[10];

    printf("\nEnter your binary number: ");
    scanf("%d",&b1);
    b2 = b1;

    while(b2 != 0)
    {
        b[n] = b2%10; //puts each digit in array
        b2/=10;
        n++; //calculates number of digits
    }

    if(n%3==1)
    {
        b[0] = 0;
        n=1;
        b2=b1;
        while(b2 != 0)
        {
            b[n] = b2%10; //puts each digit in array
            b2/=10;
            n++; //calculates number of digits
        }
    }
    else if(n%3==2)
    {
        b[0] = 0;
        b[1] = 0;
        n=2;
        b2=b1;
        while(b2 != 0)
        {
            b[n] = b2%10; //puts each digit in array
            b2/=10;
            n++; //calculates number of digits
        }
    }

    for(i=0; i<n; i+=3,j++)
    o[j] = b[i]+2*b[i+1]+4*b[i+2];

    printf("Octal form of binary number %d is:",b1);
    for(j1=j;j1>0;j1--)
    printf("%d ",o[j1]);

    printf("\n\n");
}