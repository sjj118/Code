#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000+10,inf=1e9+7;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,ans[N],ask[N],k;
int main(){
	scanf("%d",&n);
	rep(i,1,n)ans[i]=inf;
	rep(i,0,n){
		if((n>>i)==0)break;
		k=0;
		rep(j,1,n)if((j>>i)&1)ask[++k]=j;
		printf("%d\n",k);
		rep(j,1,k)printf("%d ",ask[j]);puts("");
		fflush(stdout);
		rep(j,1,n){
			int x;scanf("%d",&x);
			if(((j>>i)&1)==0)dn(ans[j],x);
		}
		k=0;
		rep(j,1,n)if(((j>>i)&1)==0)ask[++k]=j;
		printf("%d\n",k);
		rep(j,1,k)printf("%d ",ask[j]);puts("");
		fflush(stdout);
		rep(j,1,n){
			int x;scanf("%d",&x);
			if(((j>>i)&1))dn(ans[j],x);
		}
	}
	puts("-1");
	rep(i,1,n)printf("%d ",ans[i]);
	fflush(stdout);
	return 0;
}
