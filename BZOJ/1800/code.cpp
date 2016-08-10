#include<iostream>
#include<cstdio>
#define maxn 22

using namespace std;

int n,a[maxn],c,m;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]+=a[i-1];c=a[n];
	if(c&1)return puts("0"),0;
	c/=2;
	for(int i=0,j=0;;++i){
		while(j<n&&a[j]-a[i]<c)++j;
		if(j==n)break;
		if(a[j]-a[i]==c)++m;
	}
	printf("%d",m*(m-1)/2);
	return 0;
}
