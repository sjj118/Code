#include<iostream>
#include<cstdio>
#define LL long long

LL L,R,ans;
bool check(LL n){
	bool h4=0,h8=0,l3=0;
	int now=10,l=0;
	while(n){
		int tmp=n%10;n/=10;
		if(tmp==4)h4=1;
		if(tmp==8)h8=1;
		if(tmp==now)++l;
		else now=tmp,l=1;
		if(l==3)l3=1;
	}
	return l3&&(!(h4&&h8));
}

int main(){
	freopen("number.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%lld%lld",&L,&R);
	for(LL i=L;i<=R;++i)ans+=check(i);
	printf("%lld",ans);
	return 0;
}
