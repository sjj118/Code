#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
const int N=1e6+10;
int n,m,a[N];
LL c[N];
int main(){
	scanf("%d",&n);rep(i,0,n-1)scanf("%d",a+i);
	scanf("%d",&m);rep(i,0,m-1)scanf("%lld",c+i);
	LL sum=1;
	a[n]=1e9;
	rep(i,0,n){
		if(sum>m)break;
		if(a[i]==1)continue;
		per(j,m-1,0){
			if(j%(sum*a[i])>=sum)c[j]-=c[j-sum];
		}
		sum*=a[i];
	}
	printf("%d\n",n);
	rep(i,0,n-1)printf("%d ",a[i]);puts("");
	printf("%d\n",m);
	rep(i,0,m-1)printf("%lld ",c[i]);
	return 0;
}
