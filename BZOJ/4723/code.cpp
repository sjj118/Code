#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
const int N=5e5+10,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,p[N],l[N],r[N],x;
int main(){
	scanf("%d%d",&n,&x);
	rep(i,1,n){
		scanf("%d%d%d",&p[i],&l[i],&r[i]);
		++l[i],--r[i];
		if((p[i]&1)!=(l[i]&1))++l[i];
		if((p[i]&1)!=(r[i]&1))--r[i];
	}
	p[n+1]=x;
	l[n+1]=-inf;
	r[n+1]=inf;
	rep(i,0,n){
		if(l[i]>r[i]){puts("NIE");return 0;}
		up(l[i+1],l[i]-p[i+1]+p[i]);
		dn(r[i+1],r[i]+p[i+1]-p[i]);
	}
	if(l[n+1]>r[n+1])puts("NIE");
	else printf("%d",(l[n+1]+x)>>1);
	return 0;
}
}
int main(){
	//freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
