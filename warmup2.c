#include<stdio.h>
#include<ctype.h>

void main()
{
    char str[50];
    int n;

    printf("\nEnter the String: ");
    gets(str);

    for(n=0; str[n]!='\0'; n++)
    {
        if(str[n]>64 && str[n]<91)
            str[n]+=32;
        else if(str[n]>96 && str[n]<123)
            str[n]-=32;
        else
            str[n]=' ';
        
    }
    
    printf("tOOGLED sTRING IS: ");
    puts(str);
}