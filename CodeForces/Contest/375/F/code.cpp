#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=2e5+10,maxm=8e5+10;
int n,m,s,t,ds,dt,cnt,ls[maxn],lt[maxn];
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
}G;
struct Edge{
	int u,v;
	Edge(int _u=0,int _v=0){u=_u;v=_v;}
}e[maxm];
struct UFS{
	int pa[maxn],rank[maxn];
	void clear(){rep(i,1,n)pa[i]=i;}
	int find(int k){return ((pa[k]==k)?k:(pa[k]=find(pa[k])));}
	bool unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return 0;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;if(rank[a]==rank[b])++rank[b];
		return 1;
	}
}S;
int main(){
	scanf("%d%d",&n,&m);S.clear();
	rep(i,1,m){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	scanf("%d%d%d%d",&s,&t,&ds,&dt);
	rep(k,1,n)if(k!=s&&k!=t)for(int p=G.head[k];p;p=G.next[p])if(G.to[p]!=s&&G.to[p]!=t&&S.unio(k,G.to[p]))e[++cnt]=Edge(k,G.to[p]);
	for(int p=G.head[s];p;p=G.next[p])ls[S.find(G.to[p])]=G.to[p];
	for(int p=G.head[t];p;p=G.next[p])lt[S.find(G.to[p])]=G.to[p];
	bool link=0;
	rep(i,1,n)if(S.find(i)!=S.find(s)&&S.find(i)!=S.find(t)){
		if(ls[S.find(i)]&&lt[S.find(i)]){
			e[++cnt]=Edge(s,ls[S.find(i)]);
			e[++cnt]=Edge(t,lt[S.find(i)]);
			S.unio(s,i);S.unio(t,i);link=1;
			--ds;--dt;break;
		}
	}
	if(!link&&ls[t]){
		e[++cnt]=Edge(s,t);
		S.unio(s,t);
		link=1;--ds;--dt;
	}
	rep(i,1,n)if(S.find(i)!=S.find(s)&&S.find(i)!=S.find(t)){
		if(ls[S.find(i)]&&!lt[S.find(i)]&&ds){
			e[++cnt]=Edge(s,ls[S.find(i)]);
			S.unio(s,i);
			--ds;
		}else if(lt[S.find(i)]&&!ls[S.find(i)]&&dt){
			e[++cnt]=Edge(t,lt[S.find(i)]);
			S.unio(t,i);
			--dt;
		}
	}
	rep(i,1,n)if(S.find(i)!=S.find(s)&&S.find(i)!=S.find(t)&&ls[S.find(i)]&&lt[S.find(i)]){
		if(ds){
			e[++cnt]=Edge(s,ls[S.find(i)]);
			S.unio(s,i);
			--ds;
		}else if(dt){
			e[++cnt]=Edge(t,lt[S.find(i)]);
			S.unio(t,i);
			--dt;
		}
	}
	if(cnt==n-1){
		printf("Yes\n");
		rep(i,1,cnt)printf("%d %d\n",e[i].u,e[i].v);
	}else printf("No");
	return 0;
}
