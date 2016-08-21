#include<bits/stdc++.h>
using namespace std;
int n=30,k=1e9,m=10000;
int main(){
	freopen("seed.txt","r",stdin);
	int seed;scanf("%d",&seed);srand(seed);
	freopen("seed.txt","w",stdout);
	printf("%d",rand()*rand());
	fclose(stdout);
	freopen("code.in","w",stdout);
	n=rand()%n+1;k=rand()*rand()%k+1;m=rand()%m+1;
	printf("%d %d %d\n",n,k,m);
	for(int i=1;i<=n;++i){for(int j=1;j<=n;++j)printf("%d ",rand());puts("");}
	return 0;
}
