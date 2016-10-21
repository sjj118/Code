#include<iostream>
#include<cstdio>
#include<queue>
#define pli pair<LL,int>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=2e5+10,M=1e6+10;
int n;
struct Heap{
	priority_queue<pli,vector<pli>,greater<pli> >A,B;
	int size(){return A.size()-B.size();}
	void update(){while(B.size()&&A.top()==B.top())A.pop(),B.pop();}
	void push(pli x){A.push(x);}
	void del(pli x){B.push(x);}
	pli top(){update();return A.top();}
	void pop(){update();A.pop();}
}heap;
struct Graph{
	int tot,head[N],to[M],next[M];
	LL dis[N],mag[N],com[N],tmp[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void update(){
		rep(i,1,n)tmp[i]=com[i];
		rep(i,1,n)for(int p=head[i];p;p=next[p])tmp[to[p]]+=dis[i];
		rep(i,1,n)dis[i]=min(dis[i],tmp[i]);
	}
}G;
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		LL s,k,r;scanf("%lld%lld%lld",&s,&k,&r);
		G.mag[i]=k;G.com[i]=s;
		rep(j,1,r){int x;scanf("%d",&x);G.ins(x,i);}
	}
	rep(i,1,n)G.dis[i]=G.mag[i];
	rep(i,1,n)G.update();
	printf("%lld",G.dis[1]);
	return 0;
}
