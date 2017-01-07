#include<iostream>
#include<cstdio>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=15000+10;
int n,k,nxt[N];
char s[N];
int kmp(char*s,int n){
	int ret=0;
	nxt[1]=0;
	for(int i=2,j=0;i<=n;++i){
		while(j&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])++j;
		nxt[i]=j;
	}
	for(int i=2,j=0;i<=n;++i){
		while(j&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])++j;
		while(j+j>=i)j=nxt[j];
		if(j>=k)++ret;
	}
	return ret;
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%d",&k);
	LL ans=0;
	rep(i,1,n)ans+=kmp(s+i-1,n-i+1);
	printf("%lld",ans);
	return 0;
}
