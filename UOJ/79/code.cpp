#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=500+10,M=3e5;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,m,ans;
struct Graph{
	int tot,head[N],to[M],next[M],mat[N],nxt[N],vis[N],pa[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	int clo,v[N];
	int lca(int a,int b){
		for(++clo;v[a]!=clo;swap(a,b))if(a)v[a]=clo,a=find(nxt[mat[a]]);
		return a;
	}
	void blossom(int a,int b,int f){
		while(find(a)!=f){
			nxt[a]=b;b=mat[a];
			if(vis[b]==2)vis[q[qr++]=b]=1;
			pa[a]=pa[b]=f;a=nxt[b];
		}
	}
	int q[N],ql,qr;
	bool match(int s){
		ql=qr=0;cls(vis);vis[s]=1;q[qr++]=s;
		rep(i,1,n)pa[i]=i;
		while(ql!=qr){int k=q[ql++];
			for(int p=head[k];p;p=next[p]){int g=to[p];
				if(vis[g]==0){
					vis[g]=2;nxt[g]=k;
					if(!mat[g]){
						for(int last;k;k=nxt[g=last])last=mat[k],mat[k]=g,mat[g]=k;
						return 1;
					}
					vis[q[qr++]=mat[g]]=1;
				}
				if(vis[g]==1&&find(g)!=find(k)){
					int f=lca(find(g),find(k));
					blossom(k,g,f);blossom(g,k,f);
				}
			}
		}
		return 0;
	}
}G;
int main(){
	n=read();m=read();
	rep(i,1,m){int a=read(),b=read();G.addedge(a,b);}
	rep(i,1,n)ans+=!G.mat[i]&&G.match(i);
	printf("%d\n",ans);
	rep(i,1,n)printf("%d ",G.mat[i]);
	return 0;
}
