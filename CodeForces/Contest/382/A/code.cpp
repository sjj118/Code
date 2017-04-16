#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
LL n;
LL num[100];
int main(){
	std::cin>>n;
	num[0]=1;
	num[1]=2;
	int p=1;
	while(num[p]<=n){
		num[p+1]=num[p]+num[p-1];
		++p;
	}
	if(num[p]>n)--p;
	printf("%d\n",p);
	return 0;
}
