#include<iostream>
#include<cstring>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=2e4+10;
char s[maxn];
int n;
int minexpress(){
	for(int i=1,j=2,k=0;;){
		if(s[i+k]>s[j+k])i=i+k+1,k=0;
		else if(s[i+k]<s[j+k])j=j+k+1,k=0;
		else ++k;
		if(i==j)++i;
		if(i>n)return j;
		if(j>n)return i;
		if(k>n)return min(i,j);
	}
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		rep(i,1,n)s[n+i]=s[i];
		printf("%d\n",minexpress());
	}
	return 0;
}
