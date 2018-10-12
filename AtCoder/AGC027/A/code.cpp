#include<cstdio>
#include<algorithm>

using namespace std;

const int N=200+10;
int n,x,a[N];

int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<n;++i)if(x>=a[i]){
        x-=a[i];
        ++ans;
    }
    if(x==a[n])++ans;
    printf("%d",ans);
    return 0;
}
