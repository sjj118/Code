#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)

using namespace std;
inline int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
int n,m,k,ans;
bool check(int p,int q){
	if(gcd(p,q)>1)return 0;
	if(gcd(q,k)>1)return 0;
	return 1;
}

int main(){
	freopen("cyclic.in","r",stdin);freopen("brute.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	rep(x,1,n)rep(y,1,m)ans+=check(x,y);
	printf("%d",ans);
	return 0;
}
