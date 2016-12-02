#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=200+10,M=40000+10;
int n,m,d[N],match[N],used[N],ans[N];
struct Graph{
	int tot,head[N],to[M],next[M];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void clear(){tot=0;cls(head);}
	bool find(int k){
		if(k==-1)return 0;
		for(int p=head[k];p;p=next[p])if(d[k]!=d[to[p]]&&!used[to[p]]){
			used[to[p]]=1;
			if(!match[to[p]]||find(match[to[p]])){
				match[to[p]]=k;
				match[k]=to[p];
				return 1;
			}
		}
		return 0;
	}
}G;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n)scanf("%d",&d[i]);
		G.clear();
		cls(match);
		cls(ans);
		int num=0;
		rep(i,1,m){int u,v;scanf("%d%d",&u,&v);G.addedge(u+1,v+1);}
		rep(i,1,n)if(!match[i]){
			cls(used);
			num+=G.find(i);
		}
		rep(i,1,n){
			cls(used);
			used[i]=1;
			if(!match[i]||G.find(match[i]))match[i]=0;
			else{match[match[i]]=0;match[i]=-1;ans[i]=1;}
		}
		printf("%d",num);
		rep(i,1,n)if(ans[i])printf(" %d",i-1);puts("");
	}
	return 0;
}
