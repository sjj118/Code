#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int T=10,N=300,M=300;
struct Edge{
	int u,v;
	Edge(){}
	Edge(int u,int v):u(u),v(v){}
}e[300+10],p[300*300+10];
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	printf("%d\n",T);
	while(T--){
		int n=rand()%N+1,m=rand()%M+1,k=0;
		rep(i,1,m)e[i]=Edge(rand()%n+1,rand()%n+1);
		rep(i,1,m)rep(j,1,m)if(e[i].v==e[j].u)p[++k]=Edge(i,j);
		printf("%d\n%d\n",m,k);
		rep(i,1,k)printf("%d %d\n",p[i].u-1,p[i].v-1);
	}
	return 0;
}
