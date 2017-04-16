#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::cin;
using std::string;
const int N=50+10;
int n,k,a[N],tot,b[N];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n-k+1){
		char op[10];scanf("%s",op);
		if(op[0]=='Y')b[i]=1;else b[i]=0;
	}
	rep(i,1,k-1)a[i]=++tot;
	rep(i,k,n)if(b[i-k+1])a[i]=++tot;else a[i]=a[i-k+1];
	rep(i,1,n){
		char s[10];
		int l=0;
		int x=a[i];
		while(x)s[++l]=x%26+'a',x/=26;
		s[1]+='A'-'a';
		rep(j,1,l)printf("%c",s[j]);putchar(' ');
	}
	return 0;
}
