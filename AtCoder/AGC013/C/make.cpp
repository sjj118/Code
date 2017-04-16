#include<iostream>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=1e5+10;
int a[N];
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	int l=rand()%6+1,n=rand()%l+1,t=rand()%l+1;
	printf("%d %d %d\n",n,l,t);
	rep(i,0,n-1)a[i]=rand()%(l-n+1);
	std::sort(a,a+n);
	rep(i,0,n-1)printf("%d %d\n",i+a[i],rand()%2+1);
	return 0;
}
