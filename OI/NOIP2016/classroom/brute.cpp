#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2000+10,V=300+10,inf=1e8;
template<class T>inline void dn(T&x,T y){if(y<x)x=y;}
int n,m,v,e,c[N],d[N],dis[N][N];
double p[N],ans=inf;
bool sel[N];
double calc(int k,int pos){
	if(k==n+1)return 0;
	if(sel[k])return (1-p[k])*(calc(k+1,c[k])+dis[pos][c[k]])+p[k]*(calc(k+1,d[k])+dis[pos][d[k]]);
	else return calc(k+1,c[k])+dis[pos][c[k]];
}
void dfs(int k,int last){
	dn(ans,calc(1,0));
	if(k==m+1)return;
	rep(i,last+1,n)sel[i]=1,dfs(k+1,i),sel[i]=0;
}
int main(){
	freopen("classroom.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&v,&e);
	rep(i,1,n)scanf("%d",&c[i]);
	rep(i,1,n)scanf("%d",&d[i]);
	rep(i,1,n)scanf("%lf",&p[i]);
	rep(i,1,v)rep(j,1,v)if(i==j)dis[i][j]=0;else dis[i][j]=inf;
	rep(i,1,e){
		int a,b,w;scanf("%d%d%d",&a,&b,&w);
		dn(dis[a][b],w);dn(dis[b][a],w);}
	rep(k,1,v)rep(i,1,v)rep(j,1,v)dn(dis[i][j],dis[i][k]+dis[k][j]);
	dfs(1,0);
	printf("%.10lf",ans);
	return 0;
}
