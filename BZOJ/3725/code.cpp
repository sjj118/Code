#include<iostream>
#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::max;
using std::min;
const int N=1e6+10,inf=1e9;
int n;
char s[N];
bool check(int k){
	char lstc='*';
	int lstp=-inf;
	rep(i,1,n)if(s[i]!='*'){
		int l=max(1,i-n+k),r=min(k,i);
		if(s[i]!=lstc&&l<=lstp)return 0;
		lstp=r;lstc=s[i];
	}
	return 1;
}
int main(){
	scanf("\n%s",s+1);
	n=strlen(s+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;else l=mid+1;
	}
	printf("%d",l);
	return 0;
}
