#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int caseid,n,r[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],len[N<<1];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	int dfs(int k,int pre,int st,int l){
		int ret=0;
		if(k!=st&&r[k]+r[st]>=l)++ret;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)ret+=dfs(to[p],k,st,l+len[p]);
		return ret;
	}
}G;
int main(){
	scanf("%d",&caseid);
	scanf("%d",&n);
	int ans=0;
	rep(i,1,n){
		int a,c;scanf("%d%d%d",&a,&c,&r[i]);
		//a^=ans;
		if(a)G.addedge(i,a,c);
		ans+=G.dfs(i,0,i,0);
		printf("%d\n",ans);
	}
	return 0;
}
