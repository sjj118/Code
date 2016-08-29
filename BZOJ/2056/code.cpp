#include<cstdio>
using namespace std;
typedef unsigned long long LL;
LL a,b,c,d,e,f,g,h,i;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%llu%llu%llu%llu%llu%llu%llu%llu%llu",&a,&b,&c,&d,&e,&f,&g,&h,&i);
		LL ans=(1ll<<a)+(1ll<<b)+(1ll<<c)+(1ll<<d)+(1ll<<e)+(1ll<<f)+(1ll<<g)+(1ll<<h)+i;
		if(ans)printf("%llu\n",ans);else puts("18446744073709551616");
	}
}
