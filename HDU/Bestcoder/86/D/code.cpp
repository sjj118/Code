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
LL dp[maxn][maxn][maxn][3];
bool vis[maxn][maxn][maxn][3];
int n,m,K,q,w[maxn];
struct Graph{
	int head[maxn],to[maxm],next[maxm],tot;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	LL get(int x,int y,int z,int t){
		int minw=min(min(w[x],w[y]),w[z]),maxw=max(max(w[x],w[y]),w[z]);
		if(t==0&&maxw-minw>K)return 0;
		if(vis[x][y][z][t])return dp[x][y][z][t];
		dp[x][y][z][t]=(t==0);
		if(t==0)for(int p=head[x];p;p=next[p])dp[x][y][z][t]=(dp[x][y][z][t]+get(to[p],y,z,1))%mo;
		if(t==1)for(int p=head[y];p;p=next[p])dp[x][y][z][t]=(dp[x][y][z][t]+get(x,to[p],z,2))%mo;
		if(t==2)for(int p=head[z];p;p=next[p])dp[x][y][z][t]=(dp[x][y][z][t]+get(x,y,to[p],0))%mo;
		vis[x][y][z][t]=1;
		return dp[x][y][z][t];
	}
}G;
int main(){
    int T=read();
    while(T--){
        n=read();m=read();K=read();q=read();
        rep(i,1,n)w[i]=read();G.tot=0;cls(G.head);cls(dp);cls(vis);
        rep(i,1,m){int u=read(),v=read();G.ins(u,v);}
        rep(i,1,q){
            int x=read(),y=read(),z=read();
            printf("%I64d\n",G.get(x,y,z,0));
        }
    }
    return 0;
}
