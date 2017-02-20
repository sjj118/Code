#include<iostream>
#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
const int N=15000+10;
int n,k;
char s[N];
int nxt[N];
int calc(char*s,int n){
	int ret=0;
	nxt[1]=0;
	for(int i=2,j=0;i<=n;++i){
		while(j&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])++j;
		nxt[i]=j;
	}
	for(int i=1,j=0;i<=n;++i){
		while(j&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])++j;
		while(j*2+1>i)j=nxt[j];
		if(j>=k)++ret;
	}
	return ret;
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%d",&k);
	LL ans=0;
	rep(i,1,n)ans+=calc(s+i-1,n-i+1);
	printf("%lld",ans);
	return 0;
}
