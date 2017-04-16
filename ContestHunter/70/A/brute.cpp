#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=1e6+10;
using namespace std;
inline int read(){int tmp=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n;
struct Waiter{
	int h,m;
}a[maxn];
int ans;
bool check(){
	rep(i,1,n-1)if(a[i].h>a[i+1].h)return 0;
	return 1;
}
void dfs(int k){
	if(k==n+1)return;
	if(check()){ans=min(ans,k-1);return;}
	rep(i,1,n)if(!a[i].m){
		int h=a[i].h;
		per(j,i-1,1)a[j+1]=a[j];
		a[1].h=h;a[1].m=1;
		dfs(k+1);
		rep(j,1,i-1)a[j]=a[j+1];
		rep(j,i+1,n)a[j-1]=a[j];
		a[n].h=h;a[n].m=1;
		dfs(k+1);
		per(j,n,i+1)a[j]=a[j-1];
		a[i].h=h;a[i].m=0;
	}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	ans=n=read();
	rep(i,1,n)a[i].h=read();
	dfs(1);
	printf("%d",ans);
	return 0;
}
