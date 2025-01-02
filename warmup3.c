#include<stdio.h>
#include<math.h>
#include<string.h>

void main()
{
    int n1,n3;
    int num[10]; 
    int i, n=0, chekc=0;

    printf("\nEnter number: ");
    scanf("%d",&n1);
    n3 = n1;

    while(n3 != 0)
    {
        num[n] = n3%10; //puts each digit in array
        n3/=10;
        n++; //calculates number of digits
    }

    for(i=0; i<n; i++)
        chekc += round(pow(num[i], n)); //calculates number to check

    if(n1 == chekc)
        printf("The given number IS an armstrong number\n\n");
    else
        printf("The given number IS NOT an armstrong number\n\n");
}