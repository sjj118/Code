#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e6+10;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,m,f1[N],f2[N],cnt[N*3],ps,vis[N*3],nxt[N*3],clo;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void trans(int&x){
		--cnt[x];
		if(vis[x]!=clo)vis[x]=clo,nxt[x]=++ps;
		++cnt[x=nxt[x]];
	}
	void work(int k){
		++clo;
		for(int p=head[k];p;p=next[p]){
			trans(f1[to[p]]);
			if(f2[to[p]])trans(f2[to[p]]);
		}
		f2[k]=f1[k];++cnt[f2[k]];
		trans(f2[k]);
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){G.addedge(read(),read());}
	rep(i,1,n)f1[i]=1;cnt[1]=n;ps=1;
	rep(i,1,n)G.work(i);
	LL ans=0;
	rep(i,1,ps)ans+=(LL)cnt[i]*(cnt[i]-1)/2;
	printf("%lld",ans);
	return 0;
}
