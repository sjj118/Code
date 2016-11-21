#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=5+2,L=2000+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline bool vaild(char c){return c>='a'&&c<='z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n;
int a[N][L],l[N];
int st[N];
int dfs(int k){
	if(k==n+1){
		int p=0;
		while(1){
			bool flag=0;
			rep(i,1,n)if(st[i]+p>l[i])flag=1;
			if(flag)break;
			rep(i,2,n)if(a[i][st[i]+p]!=a[i-1][st[i-1]+p])flag=1;
			if(flag)break;
			++p;
		}
		return p;
	}
	int ret=0;
	rep(i,1,l[k])st[k]=i,up(ret,dfs(k+1));
	return ret;
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		char c=gc();
		while(vaild(c))a[i][++l[i]]=c-'a',c=getchar();
	}
	printf("%d",dfs(1));
	return 0;
}
