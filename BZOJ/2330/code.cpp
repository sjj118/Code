#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10,M=2*N;
int n,k,a[N];
struct Graph{
	int tot,head[N],to[M],next[M],len[M],dis[N];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	int q[N],ql,qr,inq[N],step[N];
	bool spfa(){
		rep(i,1,n)q[qr++]=a[i],step[a[i]]=0,dis[a[i]]=1;
		while(ql!=qr){
			int k=q[ql++];inq[k]=0;if(ql==N)ql=0;
			for(int p=head[k];p;p=next[p])if(dis[k]+len[p]>dis[to[p]]){
				dis[to[p]]=dis[k]+len[p];
				step[to[p]]=step[k]+1;
				if(step[to[p]]==n)return 0;
				if(inq[to[p]])continue;
				inq[to[p]]=1;
				if(dis[to[p]]>dis[q[ql]]){
					if(ql==0)ql=N;
					q[--ql]=to[p];
				}else{
					q[qr++]=to[p];
					if(qr==N)qr=0;
				}
			}
		}
		return 1;
	}
}G;
int main(){
	srand(20000107);
	scanf("%d%d",&n,&k);
	rep(i,1,n)a[i]=i;random_shuffle(a+1,a+1+n);
	rep(i,1,k){
		int x,a,b;scanf("%d%d%d",&x,&a,&b);
		if(x==1)G.ins(a,b,0),G.ins(b,a,0);
		if(x==2)G.ins(a,b,1);
		if(x==3)G.ins(b,a,0);
		if(x==4)G.ins(b,a,1);
		if(x==5)G.ins(a,b,0);
	}
	if(G.spfa()){
		LL ans=0;
		rep(i,1,n)ans+=G.dis[i];
		printf("%lld",ans);
	}else puts("-1");
	return 0;
}
