#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=5e5+10;
inline void up(double&x,double y){if(y>x)x=y;}
int n,k;
double f[N],ans;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],size[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void dfs(int k){
		size[k]=1;
		for(int p=head[k];p;p=next[p])dfs(to[p]),size[k]+=size[to[p]];
		for(int p=head[k];p;p=next[p]){
			up(f[k],min(1.0*size[to[p]]/(size[k]-1),f[to[p]]));
			up(f[k],1.0/(size[k]-1));
		}
	}
}G;
int main(){
	scanf("%d%d",&n,&k);
	rep(i,2,n){int f;scanf("%d",&f);G.ins(f,i);}
	G.dfs(1);
	rep(i,1,n)if(G.size[i]>k)up(ans,f[i]);
	printf("%.12lf",ans);
	return 0;
}
