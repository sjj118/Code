#include<iostream>
#include<cstdio>
#include<cmath>
#define max(a,b) (a>b?a:b)
#define LL long long

using namespace std;

LL n=600851475143,ans;

int main(){
	int x=floor(sqrt(n));
	for(int i=2;i<=x;++i){
		if(n%i==0){
			ans=max(ans,i);
			while(n%i==0)n/=i;
		}
	}
	ans=max(ans,n);
	printf("%d",ans);
}
