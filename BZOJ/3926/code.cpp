#include<iostream>
#include<cstdio>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10,alp=10,P=20*N*2;
int n,c;
struct SAM{
	int tot,son[P][alp],pr[P],step[P];
	SAM(){tot=1;}
	int ins(int p,int c){
		if(son[p][c]){
			int q=son[p][c];
			if(step[q]==step[p]+1)return q;
			int nq=++tot;step[nq]=step[p]+1;
			memcpy(son[nq],son[q],sizeof(son[q]));
			pr[nq]=pr[q];pr[q]=nq;
			while(p&&son[p][c]==q)son[p][c]=nq,p=pr[p];
			return nq;
		}
		int k=++tot;step[k]=step[p]+1;
		while(p&&son[p][c]==0)son[p][c]=k,p=pr[p];
		if(p){
			int q=son[p][c];
			if(step[q]==step[p]+1)pr[k]=q;
			else{
				int nq=++tot;step[nq]=step[p]+1;
				memcpy(son[nq],son[q],sizeof(son[q]));
				pr[nq]=pr[q];pr[q]=pr[k]=nq;
				while(p&&son[p][c]==q)son[p][c]=nq,p=pr[p];
			}
		}else pr[k]=1;
		return k;
	}
	LL count(){
		LL ret=0;
		rep(i,1,tot)ret+=step[i]-step[pr[i]];
		return ret;
	}
}sam;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],val[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void build(int k,int pre,int lst){
		lst=sam.ins(lst,val[k]);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)build(to[p],k,lst);
	}
	void dfs(int k,int pre){
		int son=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)++son,dfs(to[p],k);
		if(son==0||(son==1&&!pre))build(k,0,1);
	}
}G;
int main(){
	scanf("%d%d",&n,&c);
	rep(i,1,n)scanf("%d",&G.val[i]);
	rep(i,1,n-1){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
	G.dfs(1,0);
	printf("%lld",sam.count());
	return 0;
}
