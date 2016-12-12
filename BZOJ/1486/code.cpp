#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long double LB;
const int N=3000+10,M=10000+10;
const LB eps=1e-10;
int n,m;
int a[N];
struct Edge{
	int u,v;
	LB w;
}e[M];
struct Graph{
	int tot,head[N],to[M],next[M];
	LB len[M],dis[N];
	void ins(int a,int b,LB c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void clear(){tot=0;cls(head);}
	int q[N],ql,qr,step[N],inq[N];
	bool spfa(){
		ql=qr=0;
		rep(j,1,n){int i=a[j];dis[i]=0,q[qr++]=i,inq[i]=1,step[i]=0;}
		while(ql!=qr){
			int k=q[ql++];if(ql==N)ql=0;inq[k]=0;
			for(int p=head[k];p;p=next[p])if(dis[to[p]]<dis[k]+len[p]){
				dis[to[p]]=dis[k]+len[p];
				step[to[p]]=step[k]+1;
				if(step[to[p]]==n)return 1;
				if(inq[to[p]])continue;
				inq[to[p]]=1;
				if(dis[to[p]]>=dis[q[ql]]){
					if(ql==0)ql=N;
					q[--ql]=to[p];
				}else{
					q[qr++]=to[p];
					if(qr==N)qr=0;
				}
			}
		}
		return 0;
	}
}G;
int main(){
	srand(20000107);
	scanf("%d%d",&n,&m);
	rep(i,1,n)a[i]=i;random_shuffle(a+1,a+1+n);
	rep(i,1,m){double w;scanf("%d%d%lf",&e[i].u,&e[i].v,&w);e[i].w=w;}
	LB l=-1e7,r=1e7;
	while(r-l>eps){
		LB mid=(l+r)/2;
		G.clear();
		rep(i,1,m)G.ins(e[i].u,e[i].v,mid-e[i].w);
		if(G.spfa())r=mid;else l=mid;
	}
	printf("%.8lf",(double)l);
	return 0;
}
