#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2000+10;
inline bool vaild(char c){return c>='a'&&c<='z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n;
char s[N];
int main(){
	scanf("%d",&n);
	char c=gc();
	int p=(n+1)/2,f=n&1;
	rep(i,1,n){
		s[p]=c;
		if(f)p=n-p;else p=n+1-p;
		f=f^1;
		c=getchar();
	}
	rep(i,1,n)printf("%c",s[i]);
	return 0;
}
