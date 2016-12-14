#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long double LB;
const int N=20+5,M=N*N;
int n,m;
LB p[N];
inline int id(int x,int y){return (x-1)*n+y;}
struct Matrix{
	int n,m;
	LB val[M][M];
	Matrix(){n=m=0;cls(val);}
	Matrix(int n,int m):n(n),m(m){cls(val);}
	LB* const operator[](const int x){return val[x];}
	void Gauss(){
		rep(i,1,n){
			int k=i;rep(j,i,n)if(fabs(val[j][i])>fabs(val[k][i]))k=j;
			rep(j,i,m)swap(val[i][j],val[k][j]);
			rep(j,i+1,n){
				double t=val[j][i]/val[i][i];
				rep(k,i,m)val[j][k]-=t*val[i][k];
			}
		}
		per(i,n,1){
			val[i][m]/=val[i][i];val[i][i]=1;
			rep(j,1,i-1)val[j][m]-=val[i][m]*val[j][i]/val[i][i],val[j][i]=0;
		}
	}
}f;
struct Graph{
	int tot,head[N],to[M],next[M],deg[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);++deg[a];++deg[b];}
	void build(int x,int y){
		if(x==y)return;
		f[id(x,y)][id(x,y)]+=p[x]*p[y];
		for(int p1=head[x];p1;p1=next[p1])f[id(to[p1],y)][id(x,y)]+=p[y]*(1-p[x])/deg[x];
		for(int p1=head[y];p1;p1=next[p1])f[id(x,to[p1])][id(x,y)]+=p[x]*(1-p[y])/deg[y];
		for(int p1=head[x];p1;p1=next[p1])for(int p2=head[y];p2;p2=next[p2])
			f[id(to[p1],to[p2])][id(x,y)]+=(1-p[x])*(1-p[y])/deg[x]/deg[y];
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	int s,t;scanf("%d%d",&s,&t);
	rep(i,1,m){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
	rep(i,1,n){double t;scanf("%lf",&t);p[i]=t;}
	f.n=n*n;f.m=n*n+1;
	rep(i,1,n*n)f[i][i]=-1;
	f[id(s,t)][n*n+1]=-1;
	rep(i,1,n)rep(j,1,n)G.build(i,j);
	f.Gauss();
	rep(i,1,n)printf("%.6lf ",(double)f[id(i,i)][n*n+1]);
	return 0;
}
