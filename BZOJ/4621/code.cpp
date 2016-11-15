#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=500+10,mo=1e9+7;
int n,K,a[N];
struct Rational{
}f[N][N];
int main(){
	scanf("%d%d",&n,&K);
	rep(i,1,n)scanf("%d",&a[i]);
	f[0][0]=1;
	rep(i,1,n)rep(k,0,K){
		f[i][k]+=f[i-1][k];
		int maxv=a[i];
		per(j,i-1,1){
			up(maxv,a[j]);
			f[i][k]+=f[j-1][k-1];
		}
	}
	return 0;
}
