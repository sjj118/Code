#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
typedef long long LL;
using std::cerr;
using std::swap;
const int N=9+3,P=100,dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}},mo=1e9;
inline bool vaild(char c){return c=='.'||c=='*';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline LL abs(LL x){return x<0?-x:x;}
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
int n,m,a[N][N];
int id[N][N],ps;
bool inside(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m;}
struct Matrix{
	int n,m;
	LL val[P][P];
	LL*operator[](int x){return val[x];}
	const LL*operator[](int x)const{return val[x];}
	LL Determinant(){
		LL ret=1;
		bool mark=0;
		rep(i,1,n){
			if(val[i][i]==0)rep(j,i+1,n)if(val[j][i]){
				rep(k,i,m)swap(val[i][k],val[j][k]);
				ret=mo-ret;
				break;
			}
			rep(j,i+1,n){
				while(val[j][i]){
					rep(k,i,m)swap(val[i][k],val[j][k]);
					ret=mo-ret;
					LL t=val[j][i]/val[i][i];
					rep(k,i,m)ad(val[j][k],-val[i][k]*t%mo,mo);
				}
			}
		}
		rep(i,1,n)ret=ret*val[i][i]%mo;
		return ret;
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)a[i][j]=(gc()=='*');
	rep(i,1,n)rep(j,1,m)if(a[i][j]==0)id[i][j]=++ps;
	G.n=G.m=ps-1;
	rep(i,1,n)rep(j,1,m)if(id[i][j]){
		rep(p,0,3)if(inside(i+dir[p][0],j+dir[p][1])&&id[i+dir[p][0]][j+dir[p][1]])G[id[i][j]][id[i+dir[p][0]][j+dir[p][1]]]=mo-1,++G[id[i][j]][id[i][j]];
	}
	printf("%lld\n",G.Determinant());
	return 0;
}
