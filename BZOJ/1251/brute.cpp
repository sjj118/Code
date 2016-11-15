#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=5e4+10;
int n,m,a[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int op;scanf("%d",&op);
		if(op==1){
			int l,r,v;scanf("%d%d%d",&l,&r,&v);
			rep(i,l,r)a[i]+=v;
		}else if(op==2){
			int l,r;scanf("%d%d",&l,&r);
			rep(i,l,r)if(i<r-i+l)swap(a[i],a[r-i+l]);
		}else{
			int l,r;scanf("%d%d",&l,&r);
			int ret=-1e9;
			rep(i,l,r)if(a[i]>ret)ret=a[i];
			printf("%d\n",ret);
		}
	}
	return 0;
}
