#include<cstdio>
#include<algorithm>

using namespace std;

const int N=100000+10;
typedef long long LL;

int n;
LL s[N],d[N],sd[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%lld",&s[i]);
    sort(s+1,s+1+n);
    for(int i=1;i<n;++i)d[i]=s[i+1]-s[i];
    sort(d+1,d+n);
    for(int i=1;i<n;++i)sd[i]=sd[i-1]+d[i];
    int q;scanf("%d",&q);
    while(q--){
        LL l,r;scanf("%lld%lld",&l,&r);
        int p=upper_bound(d+1,d+n,r-l+1)-d-1;
        printf("%lld ",sd[p]+(r-l+1)*(n-p));
    }
    return 0;
}
