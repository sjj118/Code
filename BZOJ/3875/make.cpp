#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10,M=1e6+10;
struct LinkMap{
	int tot,head[N],to[M],next[M],deg[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;++deg[a];}
}G;
int n=2e5,m=1e6;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d\n",n);
	rep(i,1,m)G.ins(rand()%n+1,rand()%n+1);
	rep(i,1,n){
		printf("%d %d %d",rand()*rand()+1,rand()*rand()+1,G.deg[i]);
		for(int p=G.head[i];p;p=G.next[p])printf(" %d",G.to[p]);
		puts("");
	}
	return 0;
}
