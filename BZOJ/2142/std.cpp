#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define mp make_pair
#define pa pair<ll,ll> 
#define fi first
#define se second
using namespace std ;
typedef long long ll;
ll p,n,m,w[N];
ll prime[N],mod[N],cnt[N],a[N];
int tot;
ll quick_my(ll a,ll b,ll M)
{
    ll ret=1;
    while(b)
    {
        if(b&1)ret=(ret*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ret;
}
void exgcd(ll a,ll b,ll &x,ll &y,ll &gcd)
{
    if(!b)
    {
        x=1,y=0,gcd=a;
        return ;
    }
    exgcd(b,a%b,x,y,gcd);
    ll t=y;
    y=x-a/b*y;x=t;
}
void get_factor(ll x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            prime[++tot]=i,cnt[tot]=0,mod[tot]=1;
            while(x%i==0){x/=i,cnt[tot]++,mod[tot]*=i;}
        }
    }
    if(x>1)prime[++tot]=x,cnt[tot]=1,mod[tot]=x;
}
ll inverse(ll a,ll b)
{
    ll xx,yy,d;
    exgcd(a,b,xx,yy,d);
    return (xx+b)%b; 
}
pa fact(ll k,ll n)
{
    if(n==0)return mp(0,1);
    int x=n/prime[k],y=n/mod[k];
    ll ans=1;
    if(y)
    {
        for(int i=2;i<mod[k];i++)
        {
            if(i%prime[k]!=0)ans=(ans*i)%mod[k];
        }
        ans=quick_my(ans,y,mod[k]);
    }
    for(int i=y*mod[k]+1;i<=n;i++)
    {
        if(i%prime[k]!=0)ans=ans*i%mod[k];
    }
    pa tmp=fact(k,x);
    return mp(x+tmp.fi,ans*tmp.se%mod[k]);
}
ll calc(int k,ll n,ll m)
{
    if(n<m)return 0;
    pa a=fact(k,n),b=fact(k,m),c=fact(k,n-m);
    return a.se%mod[k]*inverse(b.se,mod[k])%mod[k]*inverse(c.se,mod[k])%mod[k]*quick_my(prime[k],a.fi-b.fi-c.fi,mod[k])%mod[k];
}
ll china()
{
    ll gcd,y,x=0;
    for(int i=1;i<=tot;i++)
    {
        ll r=p/mod[i];
        exgcd(mod[i],r,gcd,y,gcd);
        x=(x+r*y*a[i])%p;
    }
    return (x+p)%p;
}
ll work(ll n,ll m)
{
    for(int i=1;i<=tot;i++)
	a[i]=calc(i,n,m);
    return china();
}
int main()
{
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
    scanf("%lld%lld%lld",&p,&n,&m);
    get_factor(p);
    int sum=0;
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]),sum+=w[i];
    if(sum>n){printf("Impossible\n");return 0;}
    ll ans=work(n,sum)%p;
    for(int i=1;i<=m;i++)
    {
        ans=ans*work(sum,w[i])%p;
        sum-=w[i];
    }
    printf("%lld\n",ans);
}
