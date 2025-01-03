//Check if number is a Perfect Number (sum of divisors equals the num)
//A Perfect Number is a positive integer that is equal to the sum of its proper
//divisors, excluding itself

#include<stdio.h>

void main()
{
    int n,i,j=0,sum=0;

    printf("\nEnter Number to check: ");
    scanf("%d",&n);

    int d[n];

    for(i=1;i<n;i++)
    {
        if(n%i == 0)
        {
            d[j] = i;
            j++;
        }
    }

    for(i=0;i<j;i++)
    {
        sum+=d[i];
    }

    if(sum == n)
    printf("%d IS a perfect number",n);
    else
    printf("%d IS NOT a perfect number",n);
}