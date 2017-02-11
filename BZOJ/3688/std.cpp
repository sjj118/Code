#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 100000000
#define mod 100007 
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,ans;
int t[15][2][100005];
int f[100005][15][2];
struct data{int x,y;}p[100005];
inline bool operator<(data a,data b)
{return a.x<b.x;}
inline int lowbit(int x)
{return x&(-x);}
inline void add(int x,int v,int j,int k)
{
	for(int i=x;i<=100000;i+=lowbit(i))
	    t[j][k][i]=(t[j][k][i]+v)%mod;
}
inline int que(int x,int j,int k)
{
	int sum=0;
	for(int i=x;i;i-=lowbit(i))
	    sum=(sum+t[j][k][i])%mod;
	return sum;
}
void solve1()
{
	for(int i=1;i<=n;i++)
	{
	    f[i][0][0]=f[i][0][1]=1;
	    for(int j=1;j<i;j++)
		    for(int k=1;k<=m;k++)
		    {
            	if(p[j].y<p[i].y)f[i][k][0]+=f[j][k][0]+f[j][k-1][1];
             	else f[i][k][1]+=f[j][k][1]+f[j][k-1][0];
             	f[i][k][0]%=mod;f[i][k][1]%=mod;
            }
	}
	for(int i=1;i<=n;i++)
	{
	    ans=(ans+f[i][m][0])%mod;
		ans=(ans+f[i][m][1])%mod;
	}
	printf("%d",ans);
}
void solve2()
{   
	for(int i=1;i<=n;i++)
	{
	    f[i][0][0]=f[i][0][1]=1;
	    add(p[i].y,1,0,0);add(p[i].y,1,0,1);
		for(int j=1;j<=m;j++)
		{
            f[i][j][0]+=que(p[i].y-1,j,0)+que(p[i].y-1,j-1,1);
            f[i][j][1]+=que(100000,j,1)-que(p[i].y,j,1)+que(100000,j-1,0)-que(p[i].y,j-1,0);
            f[i][j][0]%=mod;f[i][j][1]%=mod;
            if(f[i][j][1]<0)f[i][j][1]+=mod;
            add(p[i].y,f[i][j][0],j,0);add(p[i].y,f[i][j][1],j,1);
        }
	}
	for(int i=1;i<=n;i++)
	{
	    ans=(ans+f[i][m][0])%mod;
		ans=(ans+f[i][m][1])%mod;
	}
	printf("%d",ans);
}
int main()
{
	//freopen("line.in","r",stdin);
	//freopen("line.out","w",stdout);
	freopen("code.in","r",stdin);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	    p[i].x=read(),p[i].y=read();
	sort(p+1,p+n+1);
    if(n<=1000)solve1();
	else solve2();
	return 0;
}
