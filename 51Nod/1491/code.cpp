#include<bits/stdc++.h>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,maxl=1000;
typedef long long LL;
char a[maxn],b[maxn];
int main(){
	scanf("%s\n%s",a,b);
	int n=max(strlen(a)-1,strlen(b)-1);
	per(i,n,0){
		if(i<n-1)q[(n-i)&1]=q[(n-i)&1]+q[(n-i)&1^1];
		if(a[i]=='1')qb=qb+q[(n-i)&1];
		if(b[i]=='1')qb=qb+q[(n-i)&1];
	}
	return 0;
}
