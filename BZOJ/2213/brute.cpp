#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=1e6+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline bool vaild(char c){return c>='a'&&c<='z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int ans,n,a[N],c[26];
int main(){
	scanf("%d",&n);
	rep(i,1,n)a[i]=gc()-'a';
	rep(l,1,n){
		cls(c);
		rep(r,l,n){
			++c[a[r]];
			int mx=0,mi=-1;
			rep(i,0,25)if(c[i]>c[mx])mx=i;
			rep(i,0,25)if(c[i]&&(mi==-1||c[i]<c[mi]))mi=i;
			up(ans,c[mx]-c[mi]);
		}
	}
	printf("%d",ans);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
