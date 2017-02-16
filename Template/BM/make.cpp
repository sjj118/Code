#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=5000+10,mo=1e9+7;
LL c[N],a[N];
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	int m=rand()%1000+1,n=2*m;
	rep(i,1,m)c[i]=rand()%mo;
	rep(i,1,m)a[i]=rand()%mo;
	rep(i,m+1,n)rep(j,1,m)a[i]=(a[i]+c[j]*a[i-j])%mo;
	freopen("code.in","w",stdout);
	printf("%d\n",n);
	rep(i,1,n)printf("%lld ",a[i]);
	fclose(stdout);
	freopen("code.ans","w",stdout);
	printf("%d\n",m);
	rep(i,1,m)printf("%lld ",c[i]);
	return 0;
}
