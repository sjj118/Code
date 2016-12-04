#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=3e5+10,maxq=5e5+10,maxm=15e5+10;
int n,m,now,last;
inline void swap(int&x,int&y){int t=x;x=y;y=t;}
struct UndoBoard{
	int tot,*var[maxm],val[maxm],head[maxq],next[maxm];
	void modify(int&x,int y){var[++tot]=&x;val[tot]=x;x=y;next[tot]=head[now];head[now]=tot;}
	void roll(){for(int p=head[now];p;p=next[p])*var[p]=val[p];}
}U;
struct LLUndoBoard{
	int tot,head[maxq],next[maxq];
	LL*var[maxq],val[maxq];
	void modify(LL&x,LL y){var[++tot]=&x;val[tot]=x;x=y;next[tot]=head[now];head[now]=tot;}
	void roll(){for(int p=head[now];p;p=next[p])*var[p]=val[p];}
}L;
struct UFS{
	int pa[maxn],rank[maxn];
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0;}
	int find(int k){return pa[k]==k?k:find(pa[k]);}
	bool unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return 0;
		if(rank[a]<rank[b])swap(a,b);
		U.modify(pa[b],a);
		if(rank[a]==rank[b])U.modify(rank[a],rank[a]+1);
		return 1;
	}
}S;
LL ans[maxq];
struct VersionTree{
	int tot,head[maxq],to[maxq],next[maxq],pa[maxq];
	int x[maxq],y[maxq];
	int cnt;
	LL sum;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){
		ins(a,b);pa[b]=a;
	}
	void apply(){
		if(S.unio(x[now],y[now]))U.modify(cnt,cnt+1),L.modify(sum,sum+now);
	}
	void roll(){U.roll();L.roll();}
	void dfs(int k){
		now=k;
		apply();
		ans[k]=(cnt==n-1)*sum;
		for(int p=head[k];p;p=next[p])dfs(to[p]);
		now=k;roll();
	}
}T;
int pa[2][maxq],num[2];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		char op[10];scanf("\n%s",op);
		if(op[0]=='A'){
			T.addedge(now,i);last=now;now=i;
			scanf("%d%d",&T.x[i],&T.y[i]);
			num[i&1]=0;
		}else if(op[0]=='D'){
			int k;scanf("%d",&k);
			pa[i&1^1][0]=now;
			while(num[i&1^1]<k)pa[i&1^1][num[i&1^1]+1]=T.pa[pa[i&1^1][num[i&1^1]]],++num[i&1^1];
			last=now;
			now=pa[i&1^1][k];
			T.head[i]=now;
			num[i&1]=0;
		}else{
			now=last;
			T.head[i]=now;
		}
	}
	S.clear();
	T.dfs(0);if(m)printf("%lld\n",ans[1]);
	rep(i,2,m)printf("%lld\n",T.pa[i]?ans[i]:ans[T.head[i]]);
	return 0;
}
