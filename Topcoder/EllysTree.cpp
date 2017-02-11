#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<cstdlib>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
const int N=100+10;
int n;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],pa[N],vis[N],dep[N],in[N],out[N],ver[N],clo;
	void ins(int a,int b){pa[b]=a;to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void dfs(int k,int pre){
		in[k]=++clo;
		ver[clo]=k;
		dep[k]=dep[pre]+1;
		for(int p=head[k];p;p=next[p])dfs(to[p],k);
		out[k]=clo;
	}
	bool check(int k){
		vis[k]=1;
		int ret=0;
		for(int p=pa[k];p;p=pa[p])if(!vis[p]&&dep[p]>dep[ret])ret=p;
		rep(i,in[k]+1,out[k])if(!vis[ver[i]]&&dep[ver[i]]>dep[ret])ret=ver[i];
		bool flag,all=1;
		rep(i,1,n)if(!vis[i])all=0;
		if(ret==0)flag=all;
		else flag=check(ret);
		vis[k]=0;
		return flag;
	}
}G;
class EllysTree {
public:
	vector <int> getMoves(vector <int> parent) {
		vector<int>ret;
		n=parent.size();
		rep(i,1,n)G.ins(parent[i-1],i);
		G.vis[0]=1;
		G.dfs(0,0);
		int lst=0;
		if(!G.check(0))return ret;
		rep(i,1,n){
			rep(j,1,n)if(!G.vis[j]&&G.check(j)){
				int x=lst,y=j;
				if(G.dep[x]<G.dep[y])swap(x,y);
				while(G.dep[x]>G.dep[y])x=G.pa[x];
				if(x!=y)continue;
				G.vis[j]=1;
				lst=j;
				ret.pb(j);
				break;
			}
		}
		return ret;
	}
};
/*int main(){
	EllysTree t;
	int pa[]={9, 13, 7, 9, 8, 14, 14, 0, 6, 9, 2, 2, 5, 5, 7};
	int size=sizeof(pa)/sizeof(int);
	vector<int> ans=t.getMoves(vector<int>(pa,pa+size));
	for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
	return 0;
}*/
