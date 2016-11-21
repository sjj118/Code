#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000;
int a[N],m;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=rand()%N+1;
	rep(i,1,n)a[i]=i;
	random_shuffle(a+1,a+1+n);
	rep(i,1,n)rep(j,i+1,n)if(a[i]>a[j])++m;
	printf("%d %d\n",n,m);
	rep(i,1,n)rep(j,i+1,n)if(a[i]>a[j])printf("%d %d\n",i,j);
}
