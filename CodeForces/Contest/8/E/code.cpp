#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=55;
int n;
LL k;
LL calc(int p,int l){//长度为p，右边至多l个固定
	
}
int main(){
	scanf("%d%I64d",&n,&k);
	per(i,n,2){
		LL tmp=calc(n-i,i);
		if(t<k)k-=t;
		else{
			rep(j,1,i-1)printf("0");printf("1");
			rep(j,i+1,n){
				t=calc(n-j,i);
				if(t<k)k-=t,printf("1");
				else printf("0");
			}
			break;
		}
	}
	return 0;
}
