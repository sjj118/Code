#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
#define inf 1000000000 
using namespace std;
namespace brute{

inline ll read()
{
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
bool zero;
int T,n,m,tot;
ll bin[65],a[10005];
void gauss()
{
	tot=zero=0;
	for(ll i=bin[60];i;i>>=1)
	{
		int j=tot+1;
		while(!(i&a[j])&&j<=n)j++;
		if(j==n+1)continue;
		tot++;
		swap(a[tot],a[j]);
		for(int k=1;k<=n;k++)
			if(k!=tot&&(a[k]&i))
				a[k]^=a[tot];
	}
	if(tot!=n)zero=1;
}
ll query(ll x)
{
	ll ans=0;
	x-=zero;
	if(!x)return 0;
	if(x>=bin[tot])return -1;
	for(int i=1;i<=tot;i++)
		if(x&bin[tot-i])ans^=a[i];
	return ans;
}
int main()
{
	bin[0]=1;for(int i=1;i<=60;i++)bin[i]=bin[i-1]<<1;
	T=read();
	for(int cas=1;cas<=T;cas++)
	{
		memset(a,0,sizeof(a));
		printf("Case #%d:\n",cas);
		n=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		gauss();
		m=read();
		while(m--)
		{
			int x=read();
			printf("%lld\n",query(x));
		}
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return brute::main();
}
