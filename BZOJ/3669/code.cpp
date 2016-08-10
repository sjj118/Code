#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 200000
#define lson son[k][0]
#define rson son[k][1]
#define ws(k) (son[pa[k]][1]==k)
#define canrot(k) (pa[k]&&(son[pa[k]][0]==k||son[pa[k]][1]==k))
#define inf 1e9

using namespace std;

int n,m,ans;
int read(){
	int tmp=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		tmp=tmp*10+c-'0';
		c=getchar();
	}
	return tmp;
}
struct Edge{
	int x,y,a,b;
}edge[maxn];
bool comp(Edge a,Edge b){return a.a<b.a;}
struct LCT{
	int pa[maxn],son[maxn][2],valb[maxn],line[maxn][2],maxb[maxn],maxbpos[maxn],rev[maxn];
	void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	void pushup(int k){
		maxb[0]=-inf;
		maxb[k]=max(valb[k],max(maxb[lson],maxb[rson]));
		if(maxb[k]==valb[k])maxbpos[k]=k;
		else if(maxb[k]==maxb[lson])maxbpos[k]=maxbpos[lson];
		else maxbpos[k]=maxbpos[rson];
	}
	void molify_rev(int k){
		rev[k]^=1;
		swap(lson,rson);
	}
	void pushdown(int k){
		if(rev[k])rev[k]=0,molify_rev(lson),molify_rev(rson);
	}
	void rot(int k){
		int f=pa[k],gf=pa[f],w=ws(k);
		if(canrot(f))set(k,gf,ws(f));else pa[k]=gf;
		set(son[k][!w],f,w);set(f,k,!w);
		pushup(f);
	}
	int stack[maxn],top;
	void splay(int k){
		int t=stack[top++]=k;
		while(canrot(t))stack[top++]=pa[t],t=pa[t];
		while(top)pushdown(stack[--top]);
		while(canrot(k)){
			if(canrot(pa[k])&&ws(k)==ws(pa[k]))rot(pa[k]);rot(k);
		}
		pushup(k);
	}
	int access(int k){
		int v=0;
		while(k){
			splay(k);
			son[k][1]=v;
			pushup(v=k);
			k=pa[k];
		}
		return v;
	}
	void makeroot(int k){
		molify_rev(access(k));
		splay(k);
	}
	int getroot(int k){
		for(k=access(k);pushdown(k),lson;k=lson);
		return k;
	}
	void link(int x,int y){
		makeroot(x);
		pa[x]=y;
	}
	void cut(int x,int y){
		makeroot(x);access(y);splay(y);
		pa[x]=0;son[y][0]=0;
		pushup(y);
	}
}T;
void addedge(Edge e,int pos){
	T.valb[n+pos+1]=e.b;
	T.line[n+pos+1][0]=e.x;T.line[n+pos+1][1]=e.y;
	T.pushup(n+pos+1);
	if(T.getroot(e.y)==T.getroot(e.x)){
		T.makeroot(e.x);
		T.access(e.y);
		T.splay(e.y);
		if(T.maxb[e.y]>e.b){
			int t=T.maxbpos[e.y];
			T.cut(t,T.line[t][0]);T.cut(t,T.line[t][1]);
			T.link(n+pos+1,e.x);T.link(n+pos+1,e.y);
		}
	}else{
		T.link(e.x,n+pos+1);
		T.link(e.y,n+pos+1);
	}
	if(T.getroot(1)==T.getroot(n)){
		T.makeroot(1);
		T.access(n);
		T.splay(n);
		ans=min(ans,e.a+T.maxb[n]);
	}
}

int main(){
	n=read();m=read();
	for(int i=0;i<m;++i)edge[i].x=read(),edge[i].y=read(),edge[i].a=read(),edge[i].b=read();
	sort(edge,edge+m,comp);
	ans=inf;
	for(int i=0;i<m;++i){
		addedge(edge[i],i);
	}
	if(ans==inf)printf("-1");else printf("%d",ans);
	return 0;
}
