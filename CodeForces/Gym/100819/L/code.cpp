#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,maxw=1e6+10;
const double eps=1e-4;
int n,w;
struct Question{
	int safe,v;
	double p;
}a[maxn];
double dp[maxn];
int main(){
	scanf("%d%d",&n,&w);
	rep(i,1,n){
		char s[10];scanf("%s",s);
		a[i].safe=(s[0]=='s');
		scanf("%lf%d",&a[i].p,&a[i].v);
	}
	a[0].safe=1;a[0].v=0;a[0].p=1;
	dp[n]=log(1+a[n].v*1.0/w);
	for(int i=n-1,safe=n;i>=0;--i){
		if(safe>i){--safe;while(a[safe].safe==0)--safe;}
		double tmp=a[i+1].p*dp[i+1]+(1-a[i+1].p)*log(1+a[safe].v*1.0/w);
		if(tmp>log(1+a[i].v*1.0/w))dp[i]=tmp;else dp[i]=log(1+a[i].v*1.0/w);
	}
	double l=0,r=maxw;
	while(r-l>eps){
		double m=(l+r)/2;
		if(log(1+m/w)<dp[0])l=m;else r=m;
	}
	printf("$%.2lf",l);
	return 0;
}
