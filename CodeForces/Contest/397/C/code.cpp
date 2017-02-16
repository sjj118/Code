#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
int k,a,b,wa,wb;
int main(){
	scanf("%d%d%d",&k,&a,&b);
	wa=a/k;a%=k;
	wb=b/k;b%=k;
	if((a&&!wb)||(b&&!wa))puts("-1");else printf("%d",wa+wb);
	return 0;
}
