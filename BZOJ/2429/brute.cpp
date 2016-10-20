#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1000+10,maxm=500+10;
int n,m,a[maxm],vis[maxn];
struct Point{
	int x,y;
	Point(){x=0;y=0;}
	Point(int x,int y){this->x=x;this->y=y;}
}p[maxn];
int sqr(int x){return x*x;}
int dis(const Point&a,const Point&b){return sqr(a.x-b.x)+sqr(a.y-b.y);}
int dfs(int k,int l){
	int ret=1;vis[k]=1;
	rep(i,1,n)if(!vis[i]&&l>=dis(p[k],p[i]))ret+=dfs(i,l);
	return ret;
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d",&m);
	rep(i,1,m)scanf("%d",&a[i]);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&p[i].x,&p[i].y);
	int ans=0;
	rep(i,1,m)cls(vis),ans+=(dfs(1,a[i]*a[i])==n);
	printf("%d",ans);
	return 0;
}
