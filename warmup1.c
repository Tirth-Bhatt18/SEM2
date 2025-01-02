#include<stdio.h>

void main()
{
    char str[50];
    int n;

    printf("\nEnter the String: ");
    gets(str);

    for(n=0; str[n]!='\0'; n++){}
    
    printf("Length of entered string is %d\n\n",n);
}