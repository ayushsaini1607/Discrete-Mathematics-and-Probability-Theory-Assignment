#include<stdio.h>
#include<math.h>

int main()
{
    int m,n;
    printf("\nEnter no of pigeonholes : ");
    scanf("%d",&m);
    printf("\nEnter no of pigeons : ");
    scanf("%d",&n);
    printf("\nOne pigeonhole must contain at least %d pigeons",((n-1)/m)+1);
    return 0;
}