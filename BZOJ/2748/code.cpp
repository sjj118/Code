#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
using namespace std;
const int maxn=55,maxl=1000+10;
int n,begin,h;
int f[maxn][maxl],c[maxn];
int main(){
	scanf("%d%d%d",&n,&begin,&h);
	rep(i,1,n)scanf("%d",&c[i]);
	f[0][begin]=1;
	rep(i,1,n)rep(j,0,h)if(j+c[i]<=h&&f[i-1][j+c[i]]||j-c[i]>=0&&f[i-1][j-c[i]])f[i][j]=1;
	int ans=-1;
	rep(i,0,h)if(f[n][i])ans=i;
	printf("%d",ans);
	return 0;
}
