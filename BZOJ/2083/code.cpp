#include<iostream>
#include<cstdio>
#define maxn 1000010

using namespace std;

int n,m,a[maxn];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int l;scanf("%d",&l);
		int k=0;
		for(int j=1;j<=l;++j){
			int tmp;scanf("%d",&tmp);
			while(k<=n&&tmp!=a[k+1])++k;++k;
		}
		if(k<=n)printf("TAK\n");else printf("NIE\n");
	}
	return 0;
}
