#include <stdio.h> 
  
// Returns modulo inverse of a with respect  to m using extended Euclid Algorithm 
// Assumption: a and m are coprimes, i.e., gcd(a, m) = 1 

int modInverse(int a, int modulo) 
{ 
    int m0 = modulo; 
    int y = 0, x = 1; 
  
    if (modulo== 1) 
      return 0; 
  
    while (a > 1) 
    {  
        int quotient = a / modulo; 
        int t = modulo; 
  
        // m is remainder now, process same as Euclid's algorithm 
        modulo = a % modulo, a = t; 
        t = y; 
        y = x - quotient * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 

    return x; 
} 

int euclid_algo(int a,int b)         //to calculate gcd
{
    if(b==0)
       return a;
    else
       return euclid_algo(b,a%b);
}
  
int main() 
{ 
    int a, m;
    printf("\n\t\tMultiplicative inverse for (a modulo m)\n");
    printf("\nEnter a number to find its multiplicative inverse : ");
    scanf("%d",&a);
    printf("\nEnter modulo : ");
    scanf("%d",&m); 
    
    //if gcd is 1, then only we can find multiplicative inverse
    if(euclid_algo(a,m)==1)              
       printf("Modular multiplicative inverse is %d\n",modInverse(a, m)); 
    else
       printf("\nGCD of (%d,%d) is not 1, cannot find muliplicative inverse",a,m);
    return 0; 
}