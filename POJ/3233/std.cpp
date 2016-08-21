#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int NN=32;

typedef struct node{
    int matrix[NN][NN];
}Matrix;
Matrix a,sa,unit;
int n,m,k;

Matrix Add(Matrix a,Matrix b)  //矩阵加法(%m)
{
    Matrix c;
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
      {
          c.matrix[i][j]=a.matrix[i][j]+b.matrix[i][j];
          c.matrix[i][j]%=m;
      }
    return c;
}

Matrix Mul(Matrix a,Matrix b) //矩阵乘法(%m)
{
    Matrix c;
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
      {
          c.matrix[i][j]=0;
          for (k=0; k<n; k++)
             c.matrix[i][j]+=a.matrix[i][k]*b.matrix[k][j];
          c.matrix[i][j]%=m;
      }
    return c;
}

Matrix Cal(int exp)  //矩阵快速幂
{
    Matrix p,q;
    p=a;
    q=unit;
    while (exp!=1)
    {
        if (exp&1)
        {
            exp--;
            q=Mul(p,q);
        }
        else
        {
            exp>>=1;
            p=Mul(p,p);
        }
    }
    return Mul(p,q);
}

Matrix MatrixSum(int k)
{
    if (k==1) return a;
    Matrix tmp,tnow;
    tmp=MatrixSum(k/2);
    if (k&1)    //k为奇数时sum(k)=(1+A^(k/2+1))*sum(k/2)+A^(k/2+1);
    {
        tnow=Cal(k/2+1);
        tmp=Add(tmp,Mul(tmp,tnow));
        tmp=Add(tnow,tmp);
    }   
    else        //k为偶数时sum(k)=(1+A^(k/2))*sum(k/2)
    {
        tnow=Cal(k/2);
        tmp=Add(tmp,Mul(tmp,tnow));
    }
    return tmp;
}

int main()
{
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
    scanf("%d%d%d",&n,&k,&m);
    for (int i=0; i<n; i++)
       for (int j=0; j<n; j++)
       {
           scanf("%d",&a.matrix[i][j]);
           a.matrix[i][j]%=m;
           unit.matrix[i][j]=(i==j);
       }
    sa=MatrixSum(k);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
             printf("%d ",sa.matrix[i][j]);
        printf("\n");
    }
    return 0;
}
