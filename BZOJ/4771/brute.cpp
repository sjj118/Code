#include<iostream>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
const int N=1e5+10;
int n,m,c[N],col[N];
struct Graph{
	int tot,head[N],to[N],next[N];
	void clear(){tot=0;rep(i,1,n)head[i]=0;}
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void dfs(int k,int d){
		++col[c[k]];
		if(d==0)return;
		for(int p=head[k];p;p=next[p])dfs(to[p],d-1);
	}
}G;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n)scanf("%d",&c[i]);
		G.clear();
		rep(i,2,n)G.ins(read(),i);
		int ans=0;
		while(m--){
			int x,d;scanf("%d%d",&x,&d);
			//x^=ans;d^=ans;
			cls(col);
			G.dfs(x,d);
			ans=0;
			rep(i,1,n)if(col[i])++ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}
