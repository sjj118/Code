#include<iostream>
#include<cstdio>
#include<set>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::set;
typedef long long LL;
const int N=3e5+10;
LL f[N<<2];
int c,n,m;
set<int> s;
int main(){
	scanf("%d%d%d",&c,&m,&n);
	f[0]=0;f[1]=c%m;
	rep(i,2,6)f[i]=(f[i-1]+f[i-2])%m;
	int ans=0;
	rep(i,7,4*n-1){
		f[i]=(f[i-1]+f[i-2])%m;
		if(i&1){
			if(!s.count(f[i]*c%m))++ans;
			s.insert(f[i]*c%m);
		}
	}
	ans%=m;
	printf("%d",ans);
	return 0;
}
