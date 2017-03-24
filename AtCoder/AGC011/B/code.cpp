#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
const int N=1e5+10;
int n;
LL a[N],s[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	std::sort(a+1,a+1+n);
	rep(i,1,n)s[i]=s[i-1]+a[i];
	per(i,n-1,1){
		if(s[i]*2<a[i+1]){
			printf("%d",n-i);
			return 0;
		}
	}
	printf("%d",n);
	return 0;
}
