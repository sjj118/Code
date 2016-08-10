#include<iostream>
#include<cstdio>
#define maxn 1000010
#define inf 2000

using namespace std;

int n,a[maxn],num,ans;

int main(){
	freopen("code.in","r",stdin);
	freopen("brute.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	ans=1e9;
	for(int x=1;x<=inf;++x){
		num=0;
		for(int i=1;i<=n;++i)num+=a[i]/x+a[i]%x;
		ans=min(ans,num);
	}
	printf("%d",ans);
	return 0;
}
