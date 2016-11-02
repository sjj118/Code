#include<iostream>
#include<cstdio>
#define ls son[k][0]
#define rs son[k][1]
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int N=4e5+10;
int n;
struct Tree{
	int tot,son[N][2],val[N];
	void input(int&k){
		if(!k)k=++tot;
		scanf("%d",&val[k]);
		if(!val[k])input(ls),input(rs);
	}
	int a[N],b[N],ta,tb;
	void search(int k,int*a,int&t){
		if(val[k]){a[++t]=val[k];return;}
		search(ls,a,t);search(rs,a,t);
	}
	LL dfs(int k){
		if(val[k])return 0;
		LL ret=dfs(ls)+dfs(rs);
		LL t=0,tmp=0;
		ta=tb=0;
		search(ls,a,ta);search(rs,b,tb);
		rep(i,1,ta)rep(j,1,tb)if(a[i]>b[j])++t;else ++tmp;
		return ret+min(t,tmp);
	}
}G;
int main(){
	scanf("%d",&n);
	int rt=0;
	G.input(rt);
	printf("%lld",G.dfs(1));
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
