#include<iostream>
#include<cstdio>
const int maxn=1e6+10;
typedef long long LL;
using namespace std;

int n,a[maxn],stack[maxn],top;

int main(){
	scanf("%d",&n);LL ans=0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		while(top>1&&a[i]>=stack[top-1])ans+=stack[--top];
		if(top&&a[i]>stack[top])--top,ans+=a[i];
		stack[++top]=a[i];
	}
	while(top>1)ans+=stack[--top];
	printf("%lld",ans);
	return 0;
}
