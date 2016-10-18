#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=300;
int n,a,b;
int main(){
	scanf("%d\n",&n);
	int l=0,in=0;
	rep(i,1,n){
		char c=getchar();
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')++l;
		else{
			if(in&&l)++b;
			else a=max(a,l);
			l=0;
			if(c=='(')in=1;
			if(c==')')in=0;
		}
	}
	a=max(a,l);
	printf("%d %d",a,b);
	return 0;
}
