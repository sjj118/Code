#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=1e5+10,inf=1e9+7;
inline void up(int&x,int y){x=y>x?y:x;}
inline void dn(int&x,int y){x=y<x?y:x;}
int n,d[N][4],h[4];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)rep(j,0,3)scanf("%d",&d[i][j]);
		h[0]=h[2]=inf;h[1]=h[3]=-inf;
		rep(i,1,n){
			dn(h[0],d[i][0]);
			up(h[1],d[i][1]);
			dn(h[2],d[i][2]);
			up(h[3],d[i][3]);
		}
		bool flag=0;
		rep(i,1,n)if(h[0]==d[i][0]&&h[1]==d[i][1]&&h[2]==d[i][2]&&h[3]==d[i][3])flag=1;
		if(flag)puts("TAK");else puts("NIE");
	}
	return 0;
}
