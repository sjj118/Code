#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i<=(y);++i)
using namespace std;
const int N=1e6;
int n,a[N],c[N];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),c[a[i]]=1;
	int ans=0;
	rep(i,1,N){
		int d=0;
		for(int j=1;i*j<=N;++j)if(c[i*j]){
			d=gcd(d,j);
			if(d==1){++ans;break;}
		}
	}
	printf("%d",ans);
	return 0;
}
