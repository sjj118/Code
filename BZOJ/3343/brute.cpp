#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e6+10,maxb=5e3+10;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,q,b,a[maxn];
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d%d",&n,&q);b=5e3;
	rep(i,1,n)a[i]=read();
	while(q--){
		char op;int l,r,w;
		scanf("\n%c%d%d%d",&op,&l,&r,&w);
		if(op=='A'){
			int ans=0;
			rep(i,l,r)ans+=(a[i]>=w);
			printf("%d\n",ans);
		}else{
			rep(i,l,r)a[i]+=w;
		}
	}
	return 0;
}
