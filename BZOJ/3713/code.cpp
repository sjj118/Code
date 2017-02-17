#include<iostream>
#include<cstdio>
#include<set>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::set;
typedef long long LL;
const int N=45;
LL f[N];
set<LL> s;
int main(){
	f[0]=0;f[1]=1;
	rep(i,2,N-1)f[i]=f[i-1]+f[i-2];
	rep(i,0,N-1)rep(j,0,N-1)s.insert(f[i]*f[j]);
	int T;scanf("%d",&T);
	while(T--){
		int x;scanf("%d",&x);
		if(s.count(x))puts("TAK");else puts("NIE");
	}
	return 0;
}
