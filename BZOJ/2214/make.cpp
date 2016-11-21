#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2000;
int n,a[N+10];
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("shift.in","w",stdout);
	n=rand()%N+1;
	printf("%d\n",n);
	rep(i,1,n)a[i]=i;
	random_shuffle(a+1,a+1+n);
	rep(i,1,n)printf("%d ",a[i]);
	return 0;
}
