#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i<=(y);++i)
using namespace std;
int N=1e9,K=1,R=1e5,L=1e9-R;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand()*rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int l=rand()%L+1,r=rand()%R+L;
	int n=rand()%N+1,k=rand()%K+1;
	printf("%d %d %d %d",n,k,l,r);
	return 0;
}
