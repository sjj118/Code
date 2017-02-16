#include<iostream>
#include<cstdio>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
const int N=500+10;
int n;
int a[N];
char s[N];
bool check(){
	rep(i,1,n){
		int t=s[i]-'a';
		if(t&&!a[t-1])return 0;
		a[t]=1;
	}
	return 1;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if(check())puts("YES");else puts("NO");
	return 0;
}
