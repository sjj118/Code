#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
inline void dn(int&x,int y){if(y<x)x=y;}
using std::sort;
typedef double real;
const real eps=1e-8;
namespace Graph{
	const int N=1000+10,M=9000+10,inf=1e9;
	int n,m;
	struct Edge{
		int a,b,c;
		Edge(){}
		Edge(int a,int b,int c):a(a),b(b),c(c){}
	}e[M];
	void addedge(int a,int b,int c){e[++m]=Edge(a,b,c);}
	int pa[N],dis[N],vis[N],nid[N];
	int dirmst(int rt){
		int ret=0;
		while(1){
			int tot=0;rep(i,1,m)if(e[i].a!=e[i].b)e[++tot]=e[i];m=tot;tot=0;
			rep(i,1,n)pa[i]=0,dis[i]=inf,vis[i]=0,nid[i]=0;
			rep(i,1,m)if(e[i].c<dis[e[i].b])dis[e[i].b]=e[i].c,pa[e[i].b]=e[i].a;
			rep(i,1,n)if(i!=rt&&!pa[i])return inf;
			rep(i,1,n)if(i!=rt){
				ret+=dis[i];
				int k=i;for(;k!=rt&&!vis[k];k=pa[k])vis[k]=i;
				if(vis[k]==i){
					nid[k]=++tot;
					for(int p=pa[k];p!=k;p=pa[p])nid[p]=tot;
				}
			}
			if(!tot)return ret;
			rep(i,1,n)if(!nid[i])nid[i]=++tot;
			rep(i,1,m){
				int tmp=dis[e[i].b];
				e[i].a=nid[e[i].a];e[i].b=nid[e[i].b];
				e[i].c-=tmp;
			}
			n=tot;rt=nid[rt];
		}
	}
	void solve(){
		++n;rep(i,1,n-1)addedge(n,i,(int)1e8);
		printf("%d",dirmst(n)-int(1e8));
	}
};
namespace Planar{
	const int N=3000+10,M=8000+10;
	struct Point{
		int x,y;
		Point(){}
		Point(int x,int y):x(x),y(y){}
		friend Point operator+(const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
		friend Point operator-(const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
		friend int operator*(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
		friend int operator%(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
		real atan2(){return std::atan2(y,x);}
		void input(){scanf("%d%d",&x,&y);}
	}p[N];
	struct Edge{
		int a,b,c;
		real k;
		Edge(){}
		Edge(int a,int b,int c):a(a),b(b),c(c){k=(p[b]-p[a]).atan2();}
		friend bool operator<(const Edge&a,const Edge&b){return a.a<b.a||(a.a==b.a&&a.k<b.k);}
	}e[M];
	bool cmp(int a,int b){return e[a]<e[b];}
	int s[M],pre[M],vis[M],lft[M],ps;
	void build(int n,int m){
		rep(i,1,n)p[i].input();
		rep(i,1,m){
			int p,q,v1,v2;scanf("%d%d%d%d",&p,&q,&v1,&v2);
			e[i<<1]=Edge(p,q,v1);
			e[i<<1|1]=Edge(q,p,v2);
		};
		rep(i,1,m<<1)s[i]=i+1;
		sort(s+1,s+1+(m<<1),cmp);
		for(int l=1,r=0;l<=(m<<1);l=r+1){
			while(r<(m<<1)&&e[s[r+1]].a==e[s[l]].a)++r;
			rep(i,l+1,r)pre[s[i]]=s[i-1];pre[s[l]]=s[r];
		}
		rep(i,2,(m<<1)+1)if(!vis[i]){
			++ps;
			for(int k=i;!vis[k];k=pre[k^1]){
				vis[k]=1;lft[k]=ps;
			}
		}
		Graph::n=ps;
		rep(i,2,(m<<1)+1)if(e[i].c)Graph::addedge(lft[i],lft[i^1],e[i].c);
	}
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	Planar::build(n,m);
	Graph::solve();
	return 0;
}
