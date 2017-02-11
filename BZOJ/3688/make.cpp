#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	int n=rand()%1000+1,k=rand()%min(10,n)+1;
	printf("%d %d\n",n,k);
	rep(i,1,n)a[i]=i;
	random_shuffle(a+1,a+1+n);
	rep(i,1,n)printf("%d %d\n",i,a[i]);
	return 0;
}
