#include<cstdio>

using namespace std;

const int N=300000+10;
typedef long long LL;

int n,a[N];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    LL ans=0;
    for(int i=0,j=1;i<n;++i){
        ans+=a[i]/3;
        a[i]%=3;
        while(a[i]&&j<n){
            if(j<=i)j=i+1;
            while(j<n&&a[j]<2)++j;
            if(j<n){
                --a[i];
                a[j]-=2;
                ++ans;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
