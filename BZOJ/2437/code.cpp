#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=40+5,M=N*N,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
inline bool vaild(char c){return c=='O'||c=='X'||c=='.';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n,m,q,del[M],vis[M],match[M],ans[M],tot;
inline int cw(int x,int y){return (x-1)*m+y;}
char a[N][N];
struct Graph{
	int tot,head[M],to[M<<2],next[M<<2];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	bool find(int k){
		vis[k]=1;
		for(int p=head[k];p;p=next[p])if(!del[to[p]]&&!vis[to[p]]){
			vis[to[p]]=1;
			if(!match[to[p]]||find(match[to[p]]))return match[to[p]]=k,match[k]=to[p],1;
		}
		return 0;
	}
	bool dfs(int k,int t){
		vis[k]=1;
		if(t){
			if(!match[k])return 0;
			return dfs(match[k],t^1);
		}else{
			int ret=1;
			for(int p=head[k];p;p=next[p])if(!del[to[p]]&&!vis[to[p]])ret&=dfs(to[p],t^1);
			return ret;
		}
	}
}G;
bool vaild(int x,int y){return 1<=x&&x<=n&&1<=y&&y<=m;}
int main(){
	//freopen("code.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)a[i][j]=gc();
	int sx,sy;
	rep(i,1,n)rep(j,1,m){
		if(a[i][j]=='.')sx=i,sy=j;
		else if(a[i][j]=='O'){
			rep(k,0,3)if(vaild(i+dx[k],j+dy[k])&&a[i+dx[k]][j+dy[k]]!='O')G.addedge(cw(i,j),cw(i+dx[k],j+dy[k]));
		}
	}
	rep(i,1,n)rep(j,1,m)if(a[i][j]!='O'){
		cls(vis);
		G.find(cw(i,j));
	}
	del[cw(sx,sy)]=1;
	scanf("%d",&q);
	rep(i,1,q){
		cls(vis);
		match[match[cw(sx,sy)]]=0;
		G.find(match[cw(sx,sy)]);
		cls(vis);
		int w1=1;
		rep(j,0,3)if(vaild(sx+dx[j],sy+dy[j])&&!del[cw(sx+dx[j],sy+dy[j])]&&a[sx+dx[j]][sy+dy[j]]=='O')w1&=G.dfs(cw(sx+dx[j],sy+dy[j]),1);
		int x,y;scanf("%d%d",&x,&y);
		del[cw(x,y)]=1;
		sx=x;sy=y;
		scanf("%d%d",&x,&y);
		cls(vis);
		match[match[cw(sx,sy)]]=0;
		G.find(match[cw(sx,sy)]);
		int w2=1;
		cls(vis);
		rep(j,0,3)if(vaild(sx+dx[j],sy+dy[j])&&!del[cw(sx+dx[j],sy+dy[j])]&&a[sx+dx[j]][sy+dy[j]]=='X')w2&=G.dfs(cw(sx+dx[j],sy+dy[j]),1);
		if(w1==0&&w2==0)ans[++tot]=i;
		del[cw(x,y)]=1;
		sx=x;sy=y;
	}
	printf("%d\n",tot);
	rep(i,1,tot)printf("%d\n",ans[i]);
	return 0;
}
