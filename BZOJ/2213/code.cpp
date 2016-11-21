#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=1e6+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline bool vaild(char c){return c>='a'&&c<='z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n,a[N],s[N],pr[N],ed[26],d[N],ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n)a[i]=gc()-'a';
	rep(i,1,n)pr[i]=ed[a[i]],ed[a[i]]=i;
	rep(m,0,25)rep(i,1,n)s[i]=s[pr[i]]+1;
	rep(m,0,25){
		for(int p=n,pm=ed[m];p>=1;--p){
			while(pm>p)pm=pr[pm];
			d[p]=s[p]-s[pm];
		}
		int mx[26],pi[26],plt[26];
		rep(i,0,25)mx[i]=-N,pi[i]=plt[i]=ed[i];
		for(int i=ed[m],j=n,lt=n+1;;lt=i,i=pr[i]){
			rep(p,0,25)while(pi[p]>i)pi[p]=pr[pi[p]];
			rep(p,0,25)while(plt[p]>lt)plt[p]=pr[plt[p]];
			while(j>lt)up(mx[a[j]],d[j]),--j;
			rep(p,0,25)up(ans,mx[p]-s[pi[p]]+s[i]);
			if(lt<=n)rep(p,0,25)up(ans,s[plt[p]]-s[lt]-s[pi[p]]+s[i]);
			if(i==0)break;
		}
	}
	printf("%d",ans);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
