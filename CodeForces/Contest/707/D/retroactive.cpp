#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e3+10,maxq=1e5+10;
int n,m,q;
struct Operation{
	int*var,val;
	void work(){*var=val;}
};
Operation newnode(int&a,int b){Operation x;x.var=&a;x.val=b;return x;}
struct LinkMap{
	int head[maxq],next[maxq<<2],tot;
	Operation val[maxq<<2];
	void ins(int a,Operation b){val[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void roll(int k){for(int p=head[k];p;p=next[p])val[p].work();}
}lp;
void modify(int k,int&x,int y){lp.ins(k,newnode(x,x));x=y;}
struct Query{
	int kind,x,y,ans;
}Q[maxq];
int position[maxn][maxn],shelf[maxn],rev[maxn],sum;
struct VersionTree{
	int tot,head[maxq],next[maxq<<1],to[maxq<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void apply(int k){
		int kind=Q[k].kind,x=Q[k].x,y=Q[k].y;
		if(kind==1){
			if(rev[x]==0&&position[x][y]==0){
				modify(k,position[x][y],1);
				modify(k,shelf[x],shelf[x]+1);
				modify(k,sum,sum+1);
			}else if(rev[x]==1&&position[x][y]==1){
				modify(k,position[x][y],0);
				modify(k,shelf[x],shelf[x]+1);
				modify(k,sum,sum+1);
			}
		}else if(kind==2){
			if(rev[x]==0&&position[x][y]==1){
				modify(k,position[x][y],0);
				modify(k,shelf[x],shelf[x]-1);
				modify(k,sum,sum-1);
			}else if(rev[x]==1&&position[x][y]==0){
				modify(k,position[x][y],1);
				modify(k,shelf[x],shelf[x]-1);
				modify(k,sum,sum-1);
			}
		}else if(kind==3){
			modify(k,rev[x],rev[x]^1);
			modify(k,sum,sum+m-shelf[x]-shelf[x]);
			modify(k,shelf[x],m-shelf[x]);
		}
	}
	void roll(int k){
		lp.roll(k);
	}
	void dfs(int k){
		apply(k);
		Q[k].ans=sum;
		for(int p=head[k];p;p=next[p])dfs(to[p]);
		roll(k);
	}
}T;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,q){
		int op;scanf("%d",&op);
		int x,y;
		if(op<=2)scanf("%d%d",&x,&y);else scanf("%d",&x);
		if(op<=3)T.ins(i-1,i);else T.ins(x,i);
		Q[i].kind=op;Q[i].x=x;Q[i].y=y;
	}
	T.dfs(0);
	rep(i,1,q)printf("%d\n",Q[i].ans);
	return 0;
}
