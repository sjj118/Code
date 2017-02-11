#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=300+10,inf=1e9;
inline void dn(int&x,int y){if(y<x)x=y;}
int n,q,l[N],r[N],f[N];
int joint(int a,int b,int c,int d){
	return min(b-c,d-a);
}
int count(int a,int b){
	int ret=0;
	rep(i,1,q){
		if(l[i]==a&&r[i]==b)++ret;
		else if(a<=l[i]&&r[i]<=b)ret+=l[i]-a+b-r[i];
		else if(l[i]<=a&&b<=r[i])++ret;
		else if(r[i]>a&&b>l[i]){
			ret+=min(joint(a,b,l[i],r[i]),b-a-joint(a,b,l[i],r[i]));
		}
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,q)scanf("%d%d",&l[i],&r[i]);
	f[1]=0;
	rep(i,2,n){
		f[i]=inf;
		rep(j,1,i-1){
			dn(f[i],f[j]+count(j,i));
		}
	}
	printf("%d",f[n]);
	return 0;
}
