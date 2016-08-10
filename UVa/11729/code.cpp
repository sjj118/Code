#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1005

using namespace std;

int n,t;
struct Solder{
	int b,j;
} s[maxn];
bool comp(Solder a,Solder b){
	return a.j>b.j;
}

int main(){
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;++i)scanf("%d%d",&s[i].b,&s[i].j);
		sort(s,s+n,comp);
		int ans=0,time=0;
		for(int i=0;i<n;++i)ans=max(ans,(time+=s[i].b)+s[i].j);
		printf("Case %d: %d\n",++t,ans);
	}
}
