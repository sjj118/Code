#include<iostream>
#include<cstdio>
#define inf 1e9
#define maxn 310
#define maxp 310
#define maxv 100000
 
using namespace std;
 
struct Graph{
    int tot,head[maxp],to[maxv],next[maxv],c[maxv],dis[maxp],cur[maxp];
    int pointsize,s,t;
    void getp(int&x){if(!x)x=++pointsize;}
    Graph(){tot=1;}
    void ins(int a,int b,int f){to[++tot]=b;c[tot]=f;next[tot]=head[a];head[a]=tot;}
    void addedge(int&a,int&b,int f,int f2=0){getp(a);getp(b);ins(a,b,f);ins(b,a,f2);}
    int q[maxp],ql,qr;
    bool bfs(){
        for(int i=1;i<=pointsize;++i)dis[i]=0,cur[i]=head[i];
        ql=1;qr=0;q[++qr]=t;
        while(ql<=qr)
            for(int k=q[ql++],p=head[k];p;p=next[p])
            if(c[p^1]&&!dis[to[p]]&&to[p]!=t)dis[q[++qr]=to[p]]=dis[k]+1;
        return dis[s];
    }
    int dfs(int k,int maxflow){
        if(k==t)return maxflow;
        int flow=0,tflow;
        for(int&p=cur[k];p&&maxflow;p=next[p])
            if(c[p]&&dis[to[p]]+1==dis[k]&&(tflow=dfs(to[p],min(maxflow,c[p]))))
            c[p]-=tflow,c[p^1]+=tflow,maxflow-=tflow,flow+=tflow;
        return flow;
    }
    int Dinic(int start,int end){
        s=start;t=end;
        int flow=0;
        while(bfs())flow+=dfs(s,inf);
        return flow;
    }
}G;
int n,m;
int start,end,guy[maxn];
 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int t;scanf("%d",&t);
		if(t)G.addedge(start,guy[i],1);
		else G.addedge(guy[i],end,1);
	}
	for(int i=1;i<=m;++i){
		int x,y;scanf("%d%d",&x,&y);
		G.addedge(guy[x],guy[y],1,1);
	}
	printf("%d",G.Dinic(start,end));
    return 0;
}
