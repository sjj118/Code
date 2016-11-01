#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e6+10,MO=104857601;
int n,a[N],A,B,f[N];
LL m;
int main(){
    scanf("%d%lld",&n,&m);
    scanf("%d%d%d",&a[1],&A,&B);
    rep(i,2,n)a[i]=(1ll*a[i-1]*A+B)%23333+1;
    f[0]=1;
    rep(i,1,m){
        rep(j,1,n)if(i>=a[j])f[i]=(f[i]+f[i-a[j]])%MO;
    }
    printf("%d",f[m]);
    return 0;
}
