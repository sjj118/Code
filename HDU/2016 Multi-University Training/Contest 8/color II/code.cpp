#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef unsigned int UI;
inline void dn(int&x,int y){if(y<x)x=y;}
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){char c=gc();return c-'0';}
inline int lowbit(int x){return x&(-x);}
const int maxn=20,maxv=262154,inf=1e9;
int n,v,w[maxn][maxn];
int g[maxv],f[maxv],lg[maxv];
int main(){
    int T;scanf("%d",&T);
    lg[0]=0;rep(i,1,maxv-1)lg[i]=lg[i>>1]+1;
    while(T--){
        scanf("%d",&n);
        rep(i,1,n)rep(j,1,n)w[i][j]=read();
        v=1<<n;
        f[0]=1;
        rep(i,1,v-1){
            int j=lowbit(i);f[i]=0;
            if(!f[i-j])continue;f[i]=1;
            rep(k,1,n)if((i&(1<<(k-1)))&&w[lg[j]][k]){f[i]=0;break;}
        }
        g[0]=0;
        rep(i,1,v-1){
            g[i]=inf;
            for(int j=i;j;j=(j-1)&i){
                if(f[j])dn(g[i],g[j^i]+1);
            }
        }
        UI ans=0;
        per(i,v-1,1)ans=(ans+g[i])*233;
        cout<<ans<<endl;
    }
    return 0;
}
