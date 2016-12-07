#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=5000+10,P=N*2;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,ps,nps,nid[P];
bool w[N][N];
struct Graph{
	int tot,head[P];
	bool w[P][P];
	void ins(int a,int b){w[a][b]=1;}
	void addedge(int a,int b){ins(a,b);ins(b^1,a^1);}
	int dfn[P],lowlink[P],clo,insta[P],sta[P],top;
	void dfs(int k){
		dfn[k]=lowlink[k]=++clo;
		insta[sta[++top]=k]=1;
		rep(i,2,ps)if(w[k][i]){
			if(!dfn[i])dfs(i),dn(lowlink[k],lowlink[i]);
			else if(insta[i])dn(lowlink[k],dfn[i]);
		}
		if(lowlink[k]==dfn[k]){
			nid[k]=++nps;
			while(sta[top]!=k){
				nid[sta[top]]=nps;
				insta[sta[top--]]=0;
			}insta[sta[top--]]=0;
		}
	}
	bool sat2(){
		rep(i,2,ps)if(!dfn[i])dfs(i);
		rep(i,2,ps)if(nid[i]==nid[i^1])return 0;
		return 1;
	}
}G;
int d[N],pos[N],num[2];
int main(){
	scanf("%d",&n);ps=2*n+1;
	rep(i,1,n){
		int k;scanf("%d",&k);
		rep(j,1,k){
			int x;scanf("%d",&x);
			w[i][x]=1;
		}
	}
	rep(i,1,n)rep(j,i+1,n)if(w[i][j])G.addedge(i*2+1,j*2);else G.addedge(i*2,j*2+1);
	if(!G.sat2()){puts("0");return 0;}
	int ans=0;
	rep(i,1,n)pos[i]=nid[i*2+1]<nid[i*2];
	rep(i,1,n)++num[pos[i]];
	ans=num[0]&&num[1];
	rep(i,1,n){
		rep(j,1,n)if(pos[i]!=pos[j]&&w[i][j]==pos[j])d[i]=d[i]?-1:j;
	}
	rep(i,1,n)if(d[i]==0&&num[pos[i]]>1)++ans;
	rep(i,1,n)rep(j,i+1,n)if(pos[i]!=pos[j]){
		if((d[i]==0||d[i]==j)&&(d[j]==0||d[j]==i))++ans;
	}
	printf("%d",ans);
	return 0;
}
