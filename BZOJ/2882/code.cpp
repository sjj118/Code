#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=6e5+10;
int n,a[N];
int solve(){
	for(int i=1,j=2,k=0;;){
		if(a[i+k]==a[j+k])++k;
		else if(a[i+k]<a[j+k])j=j+k+1,k=0;
		else if(a[j+k]<a[i+k])i=i+k+1,k=0;
		if(i==j)++j;
		if(k==n||i>n||j>n)return min(i,j);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)a[n+i]=a[i];
	int s=solve();
	rep(i,s,s+n-2)printf("%d ",a[i]);printf("%d",a[s+n-1]);
	return 0;
}
