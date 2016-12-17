#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int n,q,a[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		rep(i,1,n)scanf("%d",&a[i]);
		while(q--){
			int op,x,y;scanf("%d%d%d",&op,&x,&y);
			if(op==1){
				rep(i,1,n)if(a[i]==x)a[i]=y;
			}else{
				int ans=1;
				rep(i,x+1,y)ans+=a[i]!=a[i-1];
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
