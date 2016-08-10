#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 20
#define eps 1e-8
#define min(a,b) (a)<(b)?(a):(b)
#define inf 1e9

using namespace std;

int n;
struct Ans{
	bool cut[maxn];
	int num;
	double len,val;
}ans,tmp;
bool operator<(Ans a,Ans b){
	return a.val<b.val||a.val==b.val&&a.num<b.num;
}
struct Point{
	double x,y;
	double v,l;
	Point(double _x=0,double _y=0){x=_x;y=_y;}
}p[maxn],pp[maxn],q[maxn];
int qr,m;
int fab(double x){
	if(abs(x)<eps)return 0;
	return x>0?1:-1;
}
Point operator-(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
double operator^(Point a,Point b){return a.x*b.y-a.y*b.x;}
bool comp(Point a,Point b){return a.y<b.y||a.y==b.y&&a.x<b.x;}
double dis(Point a,Point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double getLen(){
	double len=0;
	qr=m=0;for(int i=1;i<=n;++i)if(!tmp.cut[i])pp[++m]=p[i];
	sort(pp+1,pp+1+m,comp);
	for(int i=1;i<=m;++i){
		while(qr>1&&fab((pp[i]-q[qr-1])^(q[qr]-q[qr-1]))>=0)--qr;
		q[++qr]=pp[i];
	}
	for(int i=2;i<=qr;++i)len+=dis(q[i-1],q[i]);
	qr=0;
	for(int i=m;i;--i){
		while(qr>1&&fab((pp[i]-q[qr-1])^(q[qr]-q[qr-1]))>=0)--qr;
		q[++qr]=pp[i];
	}
	for(int i=2;i<=qr;++i)len+=dis(q[i-1],q[i]);
	return len;
}
void dfs(int k){
	if(k==n+1){
		tmp.val=tmp.num=tmp.len=0;
		for(int i=1;i<=n;++i)tmp.val+=tmp.cut[i]?p[i].v:0,tmp.num+=tmp.cut[i],tmp.len+=tmp.cut[i]?p[i].l:0;
		tmp.len-=getLen();
		if(tmp.len>=0)ans=min(ans,tmp);
		return;
	}
	tmp.cut[k]=0;dfs(k+1);
	tmp.cut[k]=1;dfs(k+1);
}

int main(){
	int T;while(scanf("%d",&n)>0&&n){
		for(int i=1;i<=n;++i)scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&p[i].v,&p[i].l);
		ans.val=inf;
		dfs(1);
		if(T)puts("");
		printf("Forest %d\n",++T);
		printf("Cut these trees:");
		for(int i=1;i<=n;++i)if(ans.cut[i])printf(" %d",i);
		printf("\nExtra wood: %.2lf\n",ans.len);
	}
	return 0;
}
