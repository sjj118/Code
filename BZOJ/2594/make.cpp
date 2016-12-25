#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,M=1e6+10;
struct Edge{
	int u,v,t;
}e[M];
set<int> s[N];
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	//int n=rand()%1000+1,m=min(rand()%10000+1,n*(n-1)/2),q=rand()%1000+1;
	int n=1e5,m=1e6,q=1e5;
	printf("%d %d %d\n",n,m,q);
	rep(i,1,m){
		e[i].u=rand()%n+1;
		e[i].v=rand()%n+1;
		e[i].t=rand();
		while(s[e[i].u].count(e[i].v)||s[e[i].v].count(e[i].u)){
			e[i].u=rand()%n+1;
			e[i].v=rand()%n+1;
		}
		s[e[i].u].insert(e[i].v);
		printf("%d %d %d\n",e[i].u,e[i].v,e[i].t);
	}
	int j=0;
	rep(i,1,q){
		int op=rand()%2+1;
		if(op==1){
			printf("%d %d %d\n",op,rand()%n+1,rand()%n+1);
		}else{
			++j;
			printf("%d %d %d\n",op,e[j].v,e[j].u);
		}
	}
	return 0;
}
