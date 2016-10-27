#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int n,b,a[N],c[N<<1],p;
int main(){
	scanf("%d%d",&n,&b);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)if(a[i]==b)p=i;
	int t=n,ans=0;++c[n];
	rep(i,p+1,n){
		if(a[i]>b)++t;else --t;
		++c[t];
	}
	t=n;ans+=c[n];
	per(i,p-1,1){
		if(a[i]<b)++t;else --t;
		ans+=c[t];
	}
	printf("%d",ans);
	return 0;
}
