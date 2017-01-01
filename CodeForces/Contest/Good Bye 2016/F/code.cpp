#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define cls(a) memset(a,0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1000;
int h,ans;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&h);
		ans=0;
		G.clear();
		printf("? 1\n");fflush(stdout);
		int k,x[4];
		scanf("%d",&k);
		rep(i,1,k)scanf("%d",&x[i]);
		if(k==2){puts("! 1");fflush(stdout);continue;}
		int p;
		if(k==1)p=x[1];
		else{
			int l1=G.dfs(x[1],1);
			int l2=G.dfs(x[2],1);
			if(l1==l2)p=x[3];
			else{
			}
		}
		while(!ans){
		}
		printf("! %d\n",ans);fflush(stdout);
	}
	return 0;
}
