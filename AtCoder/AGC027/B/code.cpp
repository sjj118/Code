#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N=2e5+10;
const LL inf=1e18;

LL n,x,a[N],d[N],sum[N];

int main(){
    scanf("%lld%lld",&n,&x);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
    for(int i=1,j=n;i<=n;++i){
        while((LL)(2*j+1-5)*a[i]>x)--j;
        d[i]=j;
    }
    LL ans=inf;
    for(int t=1;t<=n;++t){
        LL tmp=x*t+2ll*(sum[n]-sum[n-t]);
        bool flag=1;
        int p=1;
        for(int i=n;i>0;i-=t,++p){
            if(d[i]<p)flag=0;
            tmp+=(LL)(2*p+1)*(sum[i]-sum[max(0,i-t)]);
        }
        if(flag&&tmp<ans)ans=tmp;
    }
    ans+=n*x;
    printf("%lld",ans);
    return 0;
}
