#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long 
#define mod 1000000007
using namespace std;
int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
ll ans;
int n,m,k;
int sum;
struct data{
	int pos,val;
}a[100005];
bool operator<(data a,data b)
{
	if(a.pos==b.pos)return a.val<b.val;
	return a.pos<b.pos;
}
int qpow(ll a,ll b)
{
	ll ans=1;
	for(int i=b;i;i>>=1,a=a*a%mod)
		if(i&1)ans=ans*a%mod;
	return ans;
}
int main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=k;i++)
		a[i].pos=read(),a[i].val=read();
	sort(a+1,a+k+1);
	int tot=m;
	int sum=(ll)n*(n+1)/2%mod,tmp=sum;
	ans=1;
	for(int i=1;i<=k;i++)
	{
		if(a[i].pos!=a[i-1].pos&&i!=1)
		 ans=ans*tmp%mod,tmp=sum,tot--;
		if(a[i].pos!=a[i-1].pos||a[i].val!=a[i-1].val)
		{
			tmp-=a[i].val;
			if(tmp<0)tmp+=mod;
		}
	}
	tot--;ans=ans*tmp%mod;
	printf("%lld\n",ans*qpow(sum,tot)%mod);
	return 0;
}
