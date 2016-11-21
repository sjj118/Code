#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=250+10,inf=1e9,P=N*2,M=2*(N*N+2*N);
int n,m,k;
struct Block{
	int x,y,a;
}a[N*N];
bool operator<(const Block&a,const Block&b){return a.a<b.a;}
struct Graph{
	int tot,head[P],next[M],to[M],c[M],dis[P],cur[P];
	int ps,s,t;
	void getp(int&x){if(!x)x=++ps;}
	void ins(int a,int b,int f){to[++tot]=b;next[tot]=head[a];head[a]=tot;c[tot]=f;}
	void addedge(int&a,int&b,int f){getp(a);getp(b);ins(a,b,f);ins(b,a,0);}
	void clear(){tot=1;cls(head);}
	int q[P],ql,qr;
	bool bfs(){
		rep(i,1,ps)dis[i]=0,cur[i]=head[i];
		ql=qr=0;q[qr++]=t;
		while(ql!=qr)
			for(int k=q[ql++],p=head[k];p;p=next[p])
			if(c[p^1]&&to[p]!=t&&!dis[to[p]])dis[q[qr++]=to[p]]=dis[k]+1;
		return dis[s];
	}
	int dfs(int k,int mf){
		if(k==t)return mf;
		int flow=0,tf;
		for(int&p=cur[k];p&&mf;p=next[p])
			if(c[p]&&dis[to[p]]+1==dis[k]&&(tf=dfs(to[p],min(c[p],mf))))
			c[p]-=tf,c[p^1]+=tf,mf-=tf,flow+=tf;
		return flow;
	}
	int Dinic(int start,int end){
		s=start;t=end;
		int flow=0;
		while(bfs())flow+=dfs(s,inf);
		return flow;
	}
}G;
int start,end,row[N],col[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);k=n+1-k;
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[(i-1)*m+j].a),a[(i-1)*m+j].x=i,a[(i-1)*m+j].y=j;
	sort(a+1,a+1+n*m);
	G.clear();
	rep(i,1,n)G.addedge(start,row[i],1);
	rep(i,1,m)G.addedge(col[i],end,1);
	int sum=0,ans=0,j=1;
	while((sum+=G.Dinic(start,end))<k){
		ans=a[j].a;
		while(j<=n*m&&a[j].a==ans)G.addedge(row[a[j].x],col[a[j].y],1),++j;
	}
	printf("%d",ans);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code2.out","w",stdout);
	return sjj118::main();
}

