#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::swap;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
const int N=500+10,M=N*N;
int n,m;
struct Graph{
	int tot,head[N],to[M],next[M];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int pa[N];
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	int v[N],clo;
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
	int mat[N],q[N],vis[N],ql,qr,nxt[N];
	bool match(int s){
		rep(i,1,n)vis[i]=0,pa[i]=i;
		ql=qr=0;q[qr++]=s;vis[s]=1;
		while(ql!=qr){
			for(int k=q[ql++],p=head[k],g=to[p];p;p=next[p],g=to[p]){
				if(vis[g]==0){
					vis[g]=2;nxt[g]=k;
					if(mat[g])vis[q[qr++]=mat[g]]=1;
					else{
						for(int lst;k;k=nxt[g=lst])lst=mat[k],mat[k]=g,mat[g]=k;
						return 1;
					}
				}else if(vis[g]==1){
					int f=lca(find(k),find(g));
					blossom(k,g,f);blossom(g,k,f);
				}
			}
		}
		return 0;
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)G.addedge(read(),read());
	int ans=0;
	rep(i,1,n)ans+=!G.mat[i]&&G.match(i);
	printf("%d\n",ans);
	rep(i,1,n)printf("%d ",G.mat[i]);
	return 0;
}
