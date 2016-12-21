#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10;
int n,t,k,a[N],v[N];
int main(){
	scanf("%d%d%d",&n,&t,&k);
	rep(i,2,t+1)scanf("%d",&a[i]);
	int mink=0,maxk=n-t;
	a[1]=1;
	rep(i,2,t+1)mink+=max(0,a[i-1]-a[i]);
	rep(i,1,t+1)a[i]+=a[i-1];
	if(k<mink||k>maxk){puts("-1");return 0;}
	rep(i,2,t+1){
		int p=a[i-1];
		per(j,a[i],a[i-1]+1){
			printf("%d %d\n",j,p);
			if(k&&)
		}
	}
	return 0;
}
