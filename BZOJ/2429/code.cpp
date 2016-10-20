#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1000+10,maxm=500+10,maxv=1000000+10,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
int n,m,a[maxm];
struct Point{
	int x,y;
	Point(){x=0;y=0;}
	Point(int x,int y){this->x=x;this->y=y;}
}p[maxn];
int sqr(int x){return x*x;}
int dis(Point a,Point b){return sqr(a.x-b.x)+sqr(a.y-b.y);}
struct Graph{
	int tot,head[maxn],to[maxv],next[maxv],len[maxv],dis[maxn],vis[maxn];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	int Prim(){
		int ret=0;rep(i,1,n)dis[i]=inf;dis[1]=0;
		while(1){
			int k=0;
			rep(i,1,n)if(!vis[i]&&(k==0||dis[i]<dis[k]))k=i;
			if(k==0)break;
			up(ret,dis[k]);
			vis[k]=1;
			for(int p=head[k];p;p=next[p])if(dis[to[p]]>len[p])dis[to[p]]=len[p];
		}
		return ret;
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d",&m);
	rep(i,1,m)scanf("%d",&a[i]);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&p[i].x,&p[i].y);
	rep(i,1,n)rep(j,i+1,n)G.addedge(i,j,dis(p[i],p[j]));
	int l=G.Prim();
	int ans=0;
	rep(i,1,m)if(sqr(a[i])>=l)++ans;
	printf("%d",ans);
	return 0;
}
