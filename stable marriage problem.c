#include<stdio.h>
#define n 4

int men[n+1][n+1]={0};
int women[n+1][n+1]={0};
int mMark[n]={0};
int wMark[n]={0};
int mc[n]={0};
int wc[n]={0};

inline int inp()
{ int x=0;
int ch=getchar();
while(!(ch >= '0' && ch <= '9') )ch=getchar();
while( ch >= '0' && ch <= '9' )
x = (x<<3)+(x<<1) + ch-'0', ch=getchar();
return x;
}

int check_stability()
{
    int i;
    for(i=1;i<n;i++)
      {
          if(wc[i]!=mc[i])
          {
            return 0;
          }
      }
    return 1;
}
int better_boy(int m,int w,int w1)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(men[m][i]==w)
            return 1;
        else if(men[m][i]==w1)
            return 0;
    }
}

int better_girl(int w,int m,int m1)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(women[w][i]==m)
            return 1;
        else if(women[w][i]==m1)
            return 0;
    }
}

void men_optimal()
{
    int i,c;
    for(i=0;i<=n;i++)
    {
        wMark[i]=0;
        mc[i]=-1;
    }
    c=n;
    while(c>0)
    {
        int w;
        for(w=1;w<=n;w++)
        for(i=1;i<=n && wMark[w]==0;i++)
        {
            int m=women[w][i];
            if(mc[m]==-1)
            {
                mc[m]=w;
                wMark[w]=1;
                c--;
            }
            else
            {
                int w1=mc[m];
                if(better_boy(m,w,w1))
                {
                    mc[m]=w;
                    wMark[w]=1;
                    wMark[w1]=0;
                }
            }
        }
    }
}

void women_optimal()
{
    int i,c;
    for(i=0;i<=n;i++)
    {
        mMark[i]=0;
        wc[i]=-1;
    }
    c=n;
    while(c>0)
    {
        int m;
        for(m=1;m<=n;m++)
        for(i=1;i<=n && mMark[m]==0;i++)
        {
            int w=men[m][i];
            if(wc[w]==-1)
            {
                wc[w]=m;
                mMark[m]=1;
                c--;
            }
            else
            {
                int m1=wc[w];
                if(better_girl(w,m,m1))
                {
                    wc[w]=m;
                    mMark[m]=1;
                    mMark[m1]=0;
                }
            }
        }
    }
}
int main()
{
    int i,j;
    printf("\n Enter Girl and her choices:\n");
    for(i=1;i<=n;i++)
      for(j=0;j<=n;j++)
          women[i][j]=inp();
    printf("\nEnter Boy and his choices:\n");
    for(i=1;i<=n;i++)
      for(j=0;j<=n;j++)
          men[i][j]=inp();
    women_optimal();
    for(i=1;i<=n;i++)
        {
          mc[wc[i]]=i;
        }
    men_optimal();
    for(i=1;i<=n;i++)
      {
          wc[mc[i]]=i;
      }
    printf("\n\t\tWomen optimal solution\t\t\tMen optimal solution");
    printf("\n\n\t\tMen\t\tWomen\t\t\tWomen\t\tMen\n");
    for(i=1;i<=n;i++)
        printf("\t\t%d\t\t%d\t\t\t%d\t\t%d\n",i,mc[i],wc[i],i);
    if(check_stability())
          printf("\n\n\t\tThe problem is stable");
    else
         printf("\n\n\t\tThe problem is not stable");
    return 0;
}