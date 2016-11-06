#include<iostream>
#include<cstdio>
#include<algorithm>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=2e5+10,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,K;
struct orz{
	int dis,dep,id;
	orz(){}
	orz(int d1,int d2,int d3){dis=d1;dep=d2;id=d3;}
};
bool operator<(const orz&a,const orz&b){
	return a.dis<b.dis||a.dis==b.dis&&a.dep<b.dep;
}
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],len[N<<1],size[N],maxs[N],cut[N];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	int getsize(int k,int pre){
		size[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!cut[to[p]])size[k]+=getsize(to[p],k);
		return size[k];
	}
	int findG(int k,int pre,int s){
		int ret=k;
		maxs[k]=s-size[k];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!cut[to[p]]){
			up(maxs[k],size[to[p]]);
			int t=findG(to[p],k,s);
			if(maxs[t]<maxs[ret])ret=t;
		}
		return ret;
	}
	int cnt;
	orz a[N];
	void getlen(int k,int pre,int dis,int dep,int id,orz*a,int&cnt){
		a[++cnt]=orz(dis,dep,id);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!cut[to[p]])getlen(to[p],k,dis+len[p],dep+1,id,a,cnt);
	}
	int solve(int k){
		int ret=inf;
		cut[k]=1;
		cnt=0;
		a[++cnt]=orz(0,0,k);
		for(int p=head[k];p;p=next[p])if(!cut[to[p]])getlen(to[p],k,len[p],1,to[p],a,cnt);
		sort(a+1,a+1+cnt);
		for(int i=1,j=cnt,nx=1;j>=1;--j){
			while(i<cnt&&a[i].dis+a[j].dis<K)++i;
			if(a[i].dis+a[j].dis==K){
				if(a[i].id!=a[j].id)dn(ret,a[i].dep+a[j].dep);
				else{
					if(nx<=i){
						nx=i;
						while(nx<cnt&&a[nx].dis==a[i].dis&&a[nx].id==a[i].id)++nx;
					}
					if(a[i].id!=a[nx].id&&a[i].dis==a[nx].dis)dn(ret,a[nx].dep+a[j].dep);
				}
			}
		}
		getsize(k,0);
		for(int p=head[k];p;p=next[p])if(!cut[to[p]])dn(ret,solve(findG(to[p],k,size[to[p]])));
		return ret;
	}
}G;
int main(){
	scanf("%d%d",&n,&K);
	rep(i,1,n-1){int u,v,w;scanf("%d%d%d",&u,&v,&w);G.addedge(u,v,w);}
	int ans=G.solve(1);
	if(ans==inf)puts("-1");else printf("%d",ans);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
