#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=5e5+10,V=(1<<('v'-'a'+1))+10;
int n,col[N],hgt[V],ans[N];
inline void up(int&x,int y){if(y>x)x=y;}
struct Memory{
	int tot,*val[N],old[N];
	void modify(int&x,int y){val[++tot]=&x;old[tot]=x;x=y;}
	void roll(){*val[tot]=old[tot];--tot;}
}mem;
struct Graph{
	int tot,head[N],to[N],next[N],size[N],st[N],ed[N],clo,ver[N],dep[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	int getsize(int k,int pre){
		size[k]=1;ver[st[k]=++clo]=k;dep[k]=dep[pre]+1;
		for(int p=head[k];p;p=next[p])size[k]+=getsize(to[p],k);
		ed[k]=clo;
		return size[k];
	}
	void dfs(int k,bool keep){
		int mx=0;
		for(int p=head[k];p;p=next[p])if(size[to[p]]>size[mx])mx=to[p];
		for(int p=head[k];p;p=next[p])if(to[p]!=mx)dfs(to[p],0),up(ans[k],ans[to[p]]);
		int ma=mem.tot;
		if(mx)dfs(mx,1),up(ans[k],ans[mx]);
		if(hgt[col[k]])up(ans[k],hgt[col[k]]-dep[k]);
		rep(i,0,'v'-'a')if(hgt[col[k]^(1<<i)])up(ans[k],hgt[col[k]^(1<<i)]-dep[k]);
		if(dep[k]>hgt[col[k]])mem.modify(hgt[col[k]],dep[k]);
		static int tmp[V];
		for(int p=head[k];p;p=next[p])if(to[p]!=mx){
			rep(i,st[to[p]],ed[to[p]])up(tmp[col[ver[i]]],dep[ver[i]]);
			rep(i,st[to[p]],ed[to[p]]){
				if(hgt[col[ver[i]]])up(ans[k],hgt[col[ver[i]]]+tmp[col[ver[i]]]-2*dep[k]);
				rep(j,0,'v'-'a')if(hgt[col[ver[i]]^(1<<j)])up(ans[k],hgt[col[ver[i]]^(1<<j)]+tmp[col[ver[i]]]-2*dep[k]);
			}
			rep(i,st[to[p]],ed[to[p]]){if(tmp[col[ver[i]]]>hgt[col[ver[i]]])mem.modify(hgt[col[ver[i]]],tmp[col[ver[i]]]);tmp[col[ver[i]]]=0;}
		}
		if(!keep)while(mem.tot>ma)mem.roll();
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		int p;char c;scanf("%d %c",&p,&c);
		G.ins(p,i);col[i]=col[p]^(1<<(c-'a'));
	}
	G.getsize(1,0);
	G.dfs(1,1);
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}
