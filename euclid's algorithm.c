#include<stdio.h>

int euclid_algo(int a,int b)
{
    if(b==0)
       return a;
    else
       return euclid_algo(b,a%b);
}

int main()
{
   int a,b,gcd;
   printf("\nEnter two numbers to find their GCD : ");
   scanf("%d %d",&a,&b);
   if(a>b)
     gcd=euclid_algo(a,b);
   else
     gcd=euclid_algo(b,a);
   printf("GCD of (%d,%d) is %d",a,b,gcd);
   return 0;
}