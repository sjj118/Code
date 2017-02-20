#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=1e5+10;
struct Edge{
	int u,v;
	Edge(){}
	Edge(int u,int v):u(u),v(v){}
	void output(){printf("%d %d\n",u,v);}
}e[N];
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	int n=100000,m=1000;
	printf("%d %d\n",n,m);
	rep(i,1,n-1)(e[i]=Edge(rand()%i+1,i+1)).output();
	rep(i,1,m){
		int t=1000;
		printf("%d\n",t);
		rep(j,1,t)e[rand()%(n-1)+1].output();
	}
	return 0;
}
