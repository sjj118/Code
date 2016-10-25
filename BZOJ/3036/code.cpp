#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n,m;
struct Graph{
	int tot;
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int a,b,c;scanf("%d%d%d",&a,&b,&c);G.ins(a,b,c);}
	return 0;
}
