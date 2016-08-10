#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10;
int n,s[maxn];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&s[i]);
	sort(s+1,s+1+n);
	int x=1e9;
	rep(i,1,n/2)x=min(x,s[i]+s[n-i+1]);
	printf("%d",x);
	return 0;
}
