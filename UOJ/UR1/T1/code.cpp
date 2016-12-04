#include<iostream>
#include<cstdio>
#define maxn 1000010
#define inf 2000

using namespace std;

int n,a[maxn],num[2010];

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int x=1;x<=inf;++x){
		for(int i=1;i<=n;++i)num[x]+=a[i]/x+a[i]%x;
		printf("%d %d\n",x,num[x]);
	}
	return 0;
}
