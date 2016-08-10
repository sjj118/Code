#include<iostream>
#include<cstdio>
#define maxn 3000

using namespace std;

int n,maxl,ans;
int f[maxn];

int main(){
	scanf("%d",&n);
	maxl=(n+1)/2-1;
	for(int i=2;i<=n;++i){
		if(i<=maxl)f[i]=i-1;
		else f[i]=maxl-(i-maxl)+1;
	}
	for(int i=2;i<n-1;++i){
		ans+=f[i]*f[n-i];
	}
	printf("%d",ans);
	return 0;
} 
