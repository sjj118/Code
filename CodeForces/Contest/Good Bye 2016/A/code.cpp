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
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	int t=240-k;
	int ans=0;
	rep(i,1,n){
		if(t>=5*i)++ans,t-=5*i;
	}
	printf("%d",ans);
	return 0;
}
