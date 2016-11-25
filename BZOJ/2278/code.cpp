#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,M=1e6+10;
int n,m,cnt;
struct LinkMap{
	int tot,head[M],next[M],to[M],len[M];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;++len[a];}
}path;
struct Graph{
	int tot,head[N],to[M<<1],next[M<<1],deg[N],insta[N],pass[M<<1];
	Graph(){tot=1;}
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);++deg[a];++deg[b];}
	int mark;
	void dfs(int k){
		insta[k]=1;
		for(int&p=head[k];p;p=next[p])if(!pass[p]){
			pass[p]=pass[p^1]=1;
			if(insta[to[p]]){
				path.ins(++cnt,k);
				insta[k]=0;
				mark=to[p];
				return;
			}else{
				dfs(to[p]);
				path.ins(cnt,k);
				if(k!=mark){
					insta[k]=0;
					return;
				}
			}
		}
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int x,y,z,w;scanf("%d%d%d%d",&x,&y,&z,&w);
		if(z!=w)G.addedge(x,y);
	}
	rep(i,1,n)if(G.deg[i]&1){puts("NIE");return 0;}
	rep(i,1,n)G.dfs(i);
	printf("%d\n",cnt);
	rep(i,1,cnt){
		printf("%d",path.len[i]);
		for(int p=path.head[i];p;p=path.next[p])printf(" %d",path.to[p]);
		printf(" %d\n",path.to[path.head[i]]);
	}
	return 0;
}
