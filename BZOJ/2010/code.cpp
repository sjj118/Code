#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],tot;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int x,y;scanf("%d%d",&x,&y);
		rep(j,tot+1,tot+y)a[j]=x;
		tot+=y;
	}
	tot=0;
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		rep(j,tot+1,tot+y)b[j]=x;
		tot+=y;
	}
	return 0;
}
