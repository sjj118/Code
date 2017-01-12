#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,M=1e6;
int n,f[N],sta[N],top,a[N],lst[N];
struct Graph{
	int tot,head[N],to[M],next[M],deg[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;++deg[b];}
	int q[N],ql,qr;
	void topsort(){
		ql=qr=0;
		rep(i,1,n)if(!deg[i])q[qr++]=i;
		int cnt=0;
		while(ql!=qr){
			int k=q[ql++];
			a[k]=++cnt;
			for(int p=head[k];p;p=next[p])if(--deg[to[p]]==0)q[qr++]=to[p];
		}
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&f[i]);
	rep(i,1,n){
		while(top&&f[sta[top]]>=f[i])G.ins(i,sta[top--]);
		if(lst[f[i]-1])G.ins(lst[f[i]-1],i);
		sta[++top]=i;
		lst[f[i]]=i;
	}
	G.topsort();
	rep(i,1,n)printf("%d ",a[i]);
	return 0;
}
