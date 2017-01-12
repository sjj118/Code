#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,inf=1e9;
int n,a[N],f[N],g[N];
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	n=rand()%20+1;
	printf("%d\n",n);
	rep(i,1,n)a[i]=i;
	random_shuffle(a+1,a+1+n);
	rep(i,1,n)g[i]=inf;
	rep(i,1,n){
		int t=upper_bound(g,g+n,a[i])-g;
		f[i]=t;
		g[t]=a[i];
	}
	rep(i,1,n)printf("%d ",f[i]);
	return 0;
}
