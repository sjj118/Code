#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long 
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct data{ll a[10];};
ll a,b,t[25];
data f[25][10];
data operator+(data a,data b)
{
	data t;
	for(int k=0;k<=9;k++)
		t.a[k]=a.a[k]+b.a[k];
	return t;
}
data cal(ll x)
{
	data ans;for(int i=0;i<=9;i++)ans.a[i]=0;
	if(!x)
	{
		ans.a[0]=1;
		return ans;
	}
	int len=15;
	while(t[len]>x)len--;
	for(int i=1;i<len;i++)
		for(int j=1;j<=9;j++)
			ans=ans+f[i][j];
	ans.a[0]++;
	int cur=x/t[len];
	for(int i=1;i<cur;i++)
		ans=ans+f[len][i];
	x%=t[len];
	ans.a[cur]+=x+1;
	for(int i=len-1;i;i--)
	{
		cur=x/t[i];
		for(int j=0;j<cur;j++)
			ans=ans+f[i][j];
		x%=t[i];
		ans.a[cur]+=x+1;
	}
	return ans;
}
int main()
{
	t[1]=1;for(int i=2;i<=15;i++)t[i]=t[i-1]*10;
    for(int i=0;i<=9;i++)f[1][i].a[i]=1;
	for(int i=2;i<=12;i++)
	    for(int x=0;x<=9;x++)
			for(int y=0;y<=9;y++)
			{
				f[i][y]=f[i][y]+f[i-1][x];
				f[i][y].a[y]+=t[i-1];
			}
	a=read();b=read();
	data t1=cal(b),t2=cal(a-1);
	for(int i=0;i<=9;i++)
	{
		printf("%lld",t1.a[i]-t2.a[i]);
		if(i!=9)printf(" ");
	}
	return 0;
}
