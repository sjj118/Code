#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#include<algorithm>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int maxn=55,mo=998244353,maxm=2500;
using namespace std;
inline char gc(){char c=getchar();while(!(c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0;char c=gc();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
LL dp[maxn][maxn][maxn];
int n,m,K,q,w[maxn];
int head[maxn],to[maxm],next[maxm],tot;
void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
LL get(int x,int y,int z){
    int minw=min(min(w[x],w[y]),w[z]),maxw=max(max(w[x],w[y]),w[z]);
    if(maxw-minw>K)return 0;
    if(dp[x][y][z])return dp[x][y][z];
    dp[x][y][z]=1;
    for(int px=head[x];px;px=next[px])
        for(int py=head[y];py;py=next[py])
            for(int pz=head[z];pz;pz=next[pz])dp[x][y][z]=(dp[x][y][z]+get(to[px],to[py],to[pz]))%mo;
    return dp[x][y][z];
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
    int T=read();
    while(T--){
        n=read();m=read();K=read();q=read();
        rep(i,1,n)w[i]=read();tot=0;cls(head);cls(dp);
        rep(i,1,m){int u=read(),v=read();ins(u,v);}
        rep(i,1,q){
            int x=read(),y=read(),z=read();
            if(i%1000==0)cerr<<i<<endl;
            printf("%I64d\n",get(x,y,z));
        }
    }
    return 0;
}
