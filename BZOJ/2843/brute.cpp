#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace Brute{
	
const int N=3e4+10,M=1e5+10;
int n,m,c[N];
struct Graph{
	int tot,head[N],next[N<<1],to[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	bool link(int k,int tar,int pre){
		if(k==tar)return 1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			if(link(to[p],tar,k))return 1;
		}
		return 0;
	}
	int sumup(int k,int tar,int pre,bool&flag){
		if(k==tar){flag=1;return c[k];}
		int ret=0;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			ret+=sumup(to[p],tar,k,flag);
			if(flag)return ret+c[k];
		}
		return 0;
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&c[i]);
	scanf("%d",&m);
	rep(i,1,m){
		char op[20];scanf("\n%s",op);
		int a,b;scanf("%d%d",&a,&b);
		if(op[0]=='b'){
			if(G.link(a,b,0))puts("no");
			else{puts("yes");G.addedge(a,b);}
		}else if(op[0]=='p'){
			c[a]=b;
		}else{
			if(G.link(a,b,0)){
				bool flag=0;
				printf("%d\n",G.sumup(a,b,0,flag));
			}else puts("impossible");
		}
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return Brute::main();
}
