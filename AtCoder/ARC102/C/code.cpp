#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long LL;
int n,k;

int main(){
    scanf("%d%d",&n,&k);
    LL t=n/k;
    LL ans=t*t*t;
    if(k%2==0){
        if(n%k>=k/2)++t;
        ans+=t*t*t;
    }
    printf("%lld",ans);
    return 0;
}
