#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=5e5+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,m,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	scanf("%d",&m);
	while(m--){
		int op,l,r;scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			int x;scanf("%d",&x);
			rep(i,l,r)a[i]+=x;
		}else if(op==2){
			int x;scanf("%d",&x);
			rep(i,l,r)up(a[i],x);
		}else if(op==3){
			int x;scanf("%d",&x);
			rep(i,l,r)dn(a[i],x);
		}else if(op==4){
			int ret=0;
			rep(i,l,r)ret+=a[i];
			printf("%d\n",ret);
		}else if(op==5){
			int ret=-1e9;
			rep(i,l,r)up(ret,a[i]);
			printf("%d\n",ret);
		}else{
			int ret=1e9;
			rep(i,l,r)dn(ret,a[i]);
			printf("%d\n",ret);
		}
	}
	return 0;
}
