#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int inf=1e9;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int sum(int a,int b){
	int ret=0;
	while(a&&b){
		if(a>b){
			ret+=a/b;
			a%=b;
		}else{
			ret+=b/a;
			b%=a;
		}
	}
	if(a+b>1)return inf;
	return ret;
}
int n,ans[70];
int main(){
	//scanf("%d",&n);
	//rep(i,1,n){
	//	rep(j,1,i)printf("%5.0d",sum(i,j));puts("");
	//}
	//int mi=1e9,mo=0;
	//rep(i,1,n/2){
	//	int t=sum(n,i);
	//	if(t>=0&&t<=mi)mi=t,mo=i;
	//}
	//printf("%d %d\n",n,mo);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int t;
		while(1){
			t=rand()%n+1;
			if(sum(n,t)<=60)break;
		}
		int l=sum(n,t),tl=l;
		int a=n,b=t;
		while(a&&b){
			if(a>b){
				a-=b;
				ans[tl--]=0;
			}else{
				b-=a;
				ans[tl--]=1;
			}
		}
		if(a)rep(i,1,l)ans[i]^=1;
		rep(i,1,l)printf("%d",ans[i]);puts("");
	}
	return 0;
}
