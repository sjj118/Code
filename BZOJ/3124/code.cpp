#include<iostream>
#include<cstdio>
#include<assert.h>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=2e5+10;
inline void up(LL&x,LL y){if(y>x)x=y;}
int n;
LL dis[N],far[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],len[N<<1];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	void getdis(int k,int pre){
		far[k]=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dis[to[p]]=dis[k]+len[p],getdis(to[p],k),up(far[k],far[to[p]]+len[p]);
	}
	pii getmid(LL l,int k,int pre){
		if(far[k]*2<=l)return mp(k,pre);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&far[to[p]]+len[p]==far[k])return getmid(l,to[p],k);
		assert(0);return mp(0,0);
	}
	int calc(int k,int pre){
		int cnt=0,t;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)if(far[to[p]]+len[p]==far[k])++cnt,t=to[p];
		if(cnt!=1)return 0;
		return 1+calc(t,k);
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){int a,b,c;scanf("%d%d%d",&a,&b,&c);G.addedge(a,b,c);}
	dis[1]=0;G.getdis(1,0);
	int u=1;
	LL len=0;
	rep(i,1,n)if(dis[i]>dis[u])u=i;
	dis[u]=0;G.getdis(u,0);
	len=far[u];
	printf("%lld\n",len);
	pii mid=G.getmid(len,u,0);
	int ans=0;
	if(far[mid.fi]*2==len){
		dis[mid.fi]=0;G.getdis(mid.fi,0);
		int cnt=0,s1,s2;
		for(int p=G.head[mid.fi];p;p=G.next[p])if(far[G.to[p]]+G.len[p]==far[mid.fi])++cnt,s2=s1,s1=G.to[p];
		if(cnt==2)ans=2+G.calc(s1,mid.fi)+G.calc(s2,mid.fi);
	}else{
		dis[mid.fi]=dis[mid.se]=0;
		G.getdis(mid.fi,mid.se);G.getdis(mid.se,mid.fi);
		ans=1+G.calc(mid.fi,mid.se)+G.calc(mid.se,mid.fi);
	}
	printf("%d",ans);
	return 0;
}
