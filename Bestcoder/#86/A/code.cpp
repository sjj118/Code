#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int maxn=0,mo=0;
using namespace std;
inline char gc(){char c=getchar();while(!(c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0;char c=gc();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}

int main(){
	int T=read();
	while(T--){
		int n=read(),m=read();
		LL sum=0;rep(i,1,n)sum+=read();
		rep(i,1,m)printf("%d",read()>sum);puts("");
	}
	return 0;
}
