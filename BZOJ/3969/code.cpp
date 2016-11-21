#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e6+10,inf=1e9;
int n,k,a[N];
bool check(int x){
	int l=1,r=1;
	rep(i,1,n){
		bool flag=1;
		rep(j,l,r)if(a[j+1]-a[j]<=x){
			flag=0;l=j+2;r=2*k*i+1;
			break;
		}
		if(flag)return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,2*n*k)scanf("%d",&a[i]);
	sort(a+1,a+1+2*n*k);
	int l=0,r=inf;
	while(l<r){
		int m=(l+r)>>1;
		if(check(m))r=m;else l=m+1;
	}
	printf("%d\n",l);
	return 0;
}
