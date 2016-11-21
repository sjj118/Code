#include<iostream>
#include<cstdio>
#include<cmath>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=5e5+10;
template<class Type>
inline Type abs(Type x){return x>0?x:-x;}
template<class T1,class T2>
inline void up(T1&x,T2 y){if(y>x)x=y;}
int n,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		int p=0;
		rep(j,1,n)up(p,a[j]+ceil(sqrt(abs(i-j)))-a[i]);
		printf("%d\n",p);
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
