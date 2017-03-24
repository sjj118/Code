#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::cin;
using std::string;
using std::map;
const int N=4000+10,M=20000+10;
int n,m;
struct Graph{
	int tot,head[N],to[M],next[M],mat[N],vis[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	bool find(int k){
		for(int p=head[k];p;p=next[p])if(!vis[to[p]]){
			vis[to[p]]=1;
			if(!mat[to[p]]||find(mat[to[p]]))return mat[to[p]]=k,1;
		}
		return 0;
	}
}G;
map<string,int> boyid,girlid;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		string t;
		cin>>t;boyid[t]=i;
		cin>>t;girlid[t]=i;
	}
	scanf("%d",&m);
	rep(i,1,m){
		string t;
		cin>>t;int a=boyid[t];
		cin>>t;int b=girlid[t];
		G.ins(a,b);
	}
	rep(i,1,n){
		rep(j,1,n)G.mat[j]=j;
		cls(G.vis);
		G.mat[i]=0;
		if(G.find(i))puts("Unsafe");else puts("Safe");
	}
	return 0;
}
