#include<iostream>
#include<cstdio>
#include<queue>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef priority_queue<int,vector<int>,greater<int> > Heap;
typedef long long LL;
const int N=1e5+10;
int n;
Heap heap;
struct Graph{
	int tot,head[N],to[N],next[N],size[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	LL dfs(int k){
		LL ret=0;
		size[k]=1;
		for(int p=head[k];p;p=next[p])ret+=dfs(to[p]);
		for(int p=head[k];p;p=next[p])heap.push(size[to[p]]);
		while(heap.size()>1){
			int x=heap.top();heap.pop();x+=heap.top();heap.pop();
			ret+=x;
			heap.push(x);
		}
		if(heap.size())size[k]+=heap.top(),heap.pop();
		return ret;
	}
}G;
int main(){
	scanf("%d",&n);
	rep(i,2,n){int x;scanf("%d",&x);G.ins(x,i);}
	printf("%lld",G.dfs(1));
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
