#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=100+10,alp=26;
inline bool vaild(char c){return c>='a'&&c<='z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline void up(int&x,int y){if(y>x)x=y;}
int n,a[alp],ans[alp],b[alp];
int main(){
	freopen("blocks.in","r",stdin);freopen("blocks.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		char c=gc();
		cls(a);cls(b);
		while(vaild(c))++a[c-'a'],c=getchar();
		c=gc();
		while(vaild(c))++b[c-'a'],c=getchar();
		rep(i,0,alp-1)ans[i]+=max(a[i],b[i]);
	}
	rep(i,0,alp-1)printf("%d\n",ans[i]);
	return 0;
}
