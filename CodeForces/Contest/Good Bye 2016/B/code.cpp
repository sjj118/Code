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
int n;
int main(){
	int p=20000;
	scanf("%d",&n);
	int ans=1;
	rep(i,1,n){
		int t;char dir[10];
		scanf("%d%s",&t,dir);
		if(p==20000){
			if(dir[0]!='S')ans=0;
		}else if(p==0){
			if(dir[0]!='N')ans=0;
		}
		if(dir[0]=='S')p-=t;
		if(dir[0]=='N')p+=t;
		if(p>20000||p<0)ans=0;
	}
	if(p!=20000)ans=0;
	if(ans)puts("YES");else puts("NO");
	return 0;
}
