#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=500+10,M=N*N;
int n,m,r,t,k,ans1,ans2,solver[N],tim[N],bad[N],used[N];
struct Graph{
	int tot,head[N],to[M],next[M];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	int find(int k){
		for(int p=head[k];p;p=next[p])if(!used[to[p]]){
			used[to[p]]=1;
			if(!solver[to[p]]||find(solver[to[p]])){
				solver[to[p]]=k;
				return to[p];
			}
		}
		return 0;
	}
}G;
int main(){
	scanf("%d%d%d%d%d",&n,&m,&r,&t,&k);
	rep(i,1,k){
		int a,b;scanf("%d%d",&a,&b);
		G.ins(a,b);
	}
	rep(i,1,t/r){
		rep(j,1,n)if(!bad[j]){
			cls(used);
			if(!G.find(j))bad[j]=1;
			else ++ans1,ans2+=i;
		}
		if(ans1==m)break;
	}
	printf("%d %d\n",ans1,ans2*r);
	rep(i,1,m)if(solver[i]){
		printf("%d %d %d\n",solver[i],i,r*tim[solver[i]]++);
	}
	return 0;
}
