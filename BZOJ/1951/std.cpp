#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define P 999911659
#define ll long long 
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int G,N,M[4];
int fac[4][40005];
int t[4]={2,3,4679,35617};
int qpow(ll a,int b,int p)
{
	int ans=1;
	for(int i=b;i;i>>=1,a=(a*a)%p)
		if(i&1)ans=(ans*a)%p;
	return ans;
}
int C(int n,int m,int x)
{
	if(n<m)return 0;
	return fac[x][n]*qpow(fac[x][n-m]*fac[x][m],t[x]-2,t[x])%t[x];
}
int lucas(int n,int m,int x)
{
	if(m==0)return 1;
	return C(n%t[x],m%t[x],x)*lucas(n/t[x],m/t[x],x)%t[x];
}
void exgcd(int a,int b,int &x,int &y)
{
	if(b==0){x=1;y=0;return;}
	exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
}
int solve()
{
	int a1,b1,a2,b2,a,b,c,x,y;
	a1=t[0],b1=M[0];
	for(int i=1;i<4;i++)
	{
		a2=t[i],b2=M[i];
		a=a1;b=a2;c=b2-b1;
		exgcd(a,b,x,y);
		x=((c*x)%b+b)%b;
		b1=b1+a1*x;
		a1=a1*b;
	}
	return b1;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("std.out","w",stdout);
	for(int i=0;i<4;i++)
	{
		fac[i][0]=1;
		for(int j=1;j<=t[i];j++)
			fac[i][j]=(fac[i][j-1]*j)%t[i];
	}
	N=read();G=read();
	if(G==P){puts("0");return 0;}
	G%=P;
	for(int i=1;i*i<=N;i++)
		if(N%i==0)
		{
			int tmp=N/i;
			for(int j=0;j<4;j++)
			{
				if(tmp!=i)
					M[j]=(M[j]+lucas(N,i,j))%t[j];
				M[j]=(M[j]+lucas(N,tmp,j))%t[j];
			}
		}
	printf("%d",qpow(G,solve(),P));
	return 0;
}
