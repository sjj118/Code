#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=2000+10,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
inline void up(int&x,int y){if(y>x)x=y;}
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int nl,nr,m,n,w[N][N],vy[N],slk[N],lx[N],ly[N],ans[N],match[N],prev[N];
int main(){
	scanf("%d%d%d",&nl,&nr,&m);
	n=max(nl,nr);
	rep(i,1,m){int u=read(),v=read(),c=read();w[u][v]=c;}
	rep(i,1,n)rep(j,1,n)up(lx[i],w[i][j]);
	rep(i,1,n){
		cls(vy);
		rep(j,1,n)slk[j]=inf;
		int py=0;
		match[py]=i;
		while(match[py]){
			vy[py]=1;
			int d=inf,yy,x=match[py];
			rep(y,1,n)if(!vy[y]){
				if(lx[x]+ly[y]-w[x][y]<slk[y])slk[y]=lx[x]+ly[y]-w[x][y],prev[y]=py;
				if(slk[y]<d)d=slk[y],yy=y;
			}
			rep(y,0,n)if(vy[y])ly[y]+=d,lx[match[y]]-=d;
			else slk[y]-=d;
			py=yy;
		}
		while(py){
			match[py]=match[prev[py]];
			py=prev[py];
		}
	}
	LL sum=0;
	rep(i,1,n)sum+=lx[i]+ly[i];
	printf("%lld\n",sum);
	rep(i,1,nr)ans[match[i]]=w[match[i]][i]?i:0;
	rep(i,1,nl)printf("%d ",ans[i]);
	return 0;
}
