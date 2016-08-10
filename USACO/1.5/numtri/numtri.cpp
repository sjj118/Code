/*
ID:sjj118
PROG:numtri
LANG:C++
*/
#include<iostream>
#include<cstdio>
#define maxn 1005

using namespace std;

int n,c[maxn][maxn];

int main(){
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j)scanf("%d",&c[i][j]);
	}
	for(int i=n-1;i;--i){
		for(int j=1;j<=i;++j)c[i][j]+=max(c[i+1][j],c[i+1][j+1]);
	}
	printf("%d\n",c[1][1]);
	return 0;
}
