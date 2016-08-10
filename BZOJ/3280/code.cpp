#include<iostream>
#include<cstdio>
#include<cstring>
#define clear(x) memset(x,0,sizeof(x))
#define inf 1e9
#define maxn 55
#define maxp 1000
#define maxv 100000

using namespace std;

int n,m,k;
struct Graph{
	int tot,head[maxp],to[maxv],next[maxv],c[maxv],w[maxv],dis[maxp],vis[maxp],sign;
	int s,t,pointsize,cost;
	void getp(int&x){if(!x)x=++pointsize;}
	void ins(int a,int b,int f,int p){to[++tot]=b;c[tot]=f;w[tot]=p;next[tot]=head[a];head[a]=tot;}
	void addedge(int&a,int&b,int f,int p){getp(a);getp(b);ins(a,b,f,p);ins(b,a,0,-p);}
	int q[maxp],inq[maxp],ql,qr;
	bool spfa(){
		for(int i=1;i<=pointsize;++i)dis[i]=inf;dis[t]=0;++sign;
		ql=qr=0;q[qr++]=t;inq[t]=1;
		while(ql!=qr){
			int k=q[ql++];inq[k]=0;if(ql==maxp)ql=0;
			for(int p=head[k];p;p=next[p])if(c[p^1]&&dis[k]+w[p^1]<dis[to[p]]){
				dis[to[p]]=dis[k]+w[p^1];
				if(!inq[to[p]]){
					inq[to[p]]=1;
					q[qr++]=to[p];
					if(qr==maxp)qr=0;
				}
			}
		}
		return dis[s]<inf;
	}
	int dfs(int k,int maxflow){
		if(k==t)return cost+=maxflow*dis[s],maxflow;
		int flow=0,tflow;vis[k]=sign;
		for(int p=head[k];p&&maxflow;p=next[p])
			if(c[p]&&vis[to[p]]!=sign&&dis[k]==dis[to[p]]+w[p]&&(tflow=dfs(to[p],min(maxflow,c[p]))))
			c[p]-=tflow,c[p^1]+=tflow,maxflow-=tflow,flow+=tflow;
		return flow;
	}
	int zkwflow(int start,int end,int&c){
		s=start;t=end;
		int flow=0,tflow;
		while(spfa())while(tflow=dfs(s,inf))flow+=tflow,++sign;
		return c=cost,flow;
	}
	void init(){
		cost=sign=pointsize=0;tot=1;
		clear(head);clear(to);clear(next);clear(c);clear(w);clear(dis);clear(vis);
	}
}G;
int start,end,ex[maxn],coll[maxn],hosi[maxn];
void init(){
	G.init();
	start=0;end=0;
	clear(ex);clear(coll);clear(hosi);
}

int main(){
	int T;scanf("%d",&T);
	for(int Case=1;Case<=T;++Case){
		init();
		int sum=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;++i){
			int x;scanf("%d",&x);sum+=x;
			G.addedge(ex[i],end,x,0);G.addedge(start,hosi[i],x,0);
			if(i<n)G.addedge(ex[i],ex[i+1],inf,0);
		}
		for(int i=1;i<=m;++i){
			int f,p;scanf("%d%d",&f,&p);
			G.addedge(start,coll[i],f,p);
		}
		for(int i=1;i<=m;++i)for(int j=1;j<=n;++j)G.addedge(coll[i],ex[j],inf,0);
		for(int i=1;i<=k;++i){
			int d,q;scanf("%d%d",&d,&q);
			for(int j=1;j+d+1<=n;++j)G.addedge(hosi[j],ex[j+d+1],inf,q);
		}
		int ans=0;
		printf("Case %d: ",Case);
		if(sum==G.zkwflow(start,end,ans))printf("%d\n",ans);
		else printf("impossible\n");
	}
	return 0;
}
