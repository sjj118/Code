//如果都没有后继，那么大的在后面一定更优
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef priority_queue<int> Heap;
const int N=1e5+10;
int n,m,a[N],cnt;
Heap h;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],deg[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;++deg[b];}
	void clear(){tot=0;cls(head);cls(deg);}
	int q[N],ql,qr;
	void topsort(){
		ql=qr=0;cnt=0;
		rep(i,1,n)if(!deg[i])h.push(i);
		while(h.size()){
			int k=h.top();h.pop();
			a[++cnt]=k;
			for(int p=head[k];p;p=next[p]){
				if(--deg[to[p]]==0)h.push(to[p]);
			}
		}
	}
}G;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		G.clear();
		scanf("%d%d",&n,&m);
		rep(i,1,m){int a,b;scanf("%d%d",&a,&b);G.ins(b,a);}
		G.topsort();
		if(cnt==n)per(i,n,1)printf("%d ",a[i]);
		else printf("Impossible!");
		puts("");
	}
	return 0;
}
