#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::sort;
const int N=2e5+10,inf=1e9;
int n,ans,dis[N];
bool cmp(int a,int b){return dis[a]<dis[b];}
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],del[N];
	Graph(){tot=1;}
	int mark;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		if(pre==0)mark=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!del[to[p]])dfs(to[p],k);
		static int a[N];
		int cnt=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!del[to[p]])a[++cnt]=to[p];
		sort(a+1,a+1+cnt,cmp);
		per(i,cnt,2)if(dis[a[i]]==dis[a[i-1]])ans-=dis[a[i]],--cnt,del[a[i]]=1;
		if(cnt>1){
			dis[k]=inf;
		}
		if(!mark){
			if(cnt>2||(pre&&cnt>1))mark=k;
		}
		if(cnt==1)dis[k]=dis[a[1]]+1;
		if(cnt==0)dis[k]=1;
	}
	int getlen(int k,int pre){
		int ret=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!del[to[p]])ret+=getlen(to[p],k);
		return ret;
	}
	int work(int rt){
		dfs(rt,0);
		if(mark)dfs(mark,0);
		if(mark)return -1;
		--ans;
		while((ans&1)==0)ans>>=1;
		return ans;
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	ans=n;
	printf("%d",G.work(1));
	return 0;
}
