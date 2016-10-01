#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=500+10,maxv=1e6+10;
int n,a[maxn],c[maxv];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);cls(c); 
		rep(i,1,n)scanf("%d",&a[i]);
		rep(i,1,n)rep(j,i+1,n)c[gcd(a[i],a[j])]=1;
		bool flag=1;
		rep(i,1,maxv-1)if(c[i])printf(flag?"%d":" %d",i),flag=0;puts("");
	}
	return 0;
}
