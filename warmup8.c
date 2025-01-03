#include<stdio.h>

void main()
{
    int n,i,sx=0,sy=0,sz=0;

    printf("\nEnter the number of forces: ");
    scanf("%d", &n);

    int x[n],y[n],z[n];

    for(i=0; i<n; i++)
    {
        scanf("%d",&x[i]);
        sx += x[i];
        scanf("%d",&y[i]);
        sy += y[i];
        scanf("%d",&z[i]);
        sz += z[i];
    }

    if(sx == 0 && sy == 0 && sz == 0)
    printf("YES");
    else
    printf("NO");
}