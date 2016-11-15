#include<cstdio>
typedef long long LL;
LL h,a,b,k;
bool check(){
	if(a*k>b*(k+1))return 1;
	if(a*k-b*(k-1)>=h)return 1;
	if(a>=h)return 1;
	return 0;
}
int main(){
	int cas=0;
	while(scanf("%lld%lld%lld%lld",&h,&a,&b,&k)&&h){
		printf("Case #%d: ",++cas);
		if(check())puts("YES");else puts("NO");
	}
}
