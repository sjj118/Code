#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define maxp 100
#define maxv 20000
#define inf 1e9
#define eps 1e-8

using namespace std;

int n;

struct Graph{
	int tot,head[maxp],next[maxv],to[maxv],mark[maxp];
	double len[maxv],dis[maxp];
	void clear(){tot=0;cls(head);}
	void ins(int a,int b,double c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,double c){ins(a,b,c);ins(b,a,c);}
	double Dijkstra(int s,int t){
		for(int i=0;i<=4*n+1;++i)dis[i]=inf,mark[i]=0;dis[s]=0;
		for(int i=1;i<=4*n+1;++i){
			int k=-1;
			for(int j=0;j<=4*n+1;++j)if(!mark[j]&&(k==-1||dis[j]<dis[k]))k=j;
			mark[k]=1;
			for(int p=head[k];p;p=next[p])dis[to[p]]=min(dis[to[p]],dis[k]+len[p]);
		}
		return dis[t];
	}
}G;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
}p[maxp];
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
int fab(double x){
	if(abs(x)<eps)return 0;
	return x>0?1:-1;
}
double dis(Point a,Point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
bool hasIn(Point a,Point b,Point c,Point d){
	return fab((c-a)^(b-a))*fab((b-a)^(d-a))==1&&fab((a-d)^(c-d))*fab((c-d)^(b-d))==1;
}

int main(){
	while(scanf("%d",&n)>0&&n>=0){
		G.clear();
		p[0]=Point(0,5);p[1]=Point(10,5);
		for(int i=1;i<=n;++i){
			double x,a,b,c,d;scanf("%lf%lf%lf%lf%lf",&x,&a,&b,&c,&d);
			p[i*4-2]=Point(x,a);p[i*4-1]=Point(x,b);p[i*4]=Point(x,c);p[i*4+1]=Point(x,d);
		}
		for(int i=0;i<=4*n+1;++i)for(int j=i+1;j<=4*n+1;++j){
			bool flag=0;
			for(int k=1;k<=n;++k){
				flag|=hasIn(Point(p[4*k-2].x,0),p[4*k-2],p[i],p[j]);
				flag|=hasIn(p[4*k-1],p[4*k],p[i],p[j]);
				flag|=hasIn(p[4*k+1],Point(p[4*k+1].x,10),p[i],p[j]);
				if(flag)break;
			}
			if(!flag)G.addedge(i,j,dis(p[i],p[j]));
		}
		printf("%.2lf\n",G.Dijkstra(0,1));
	}
	return 0;
}
