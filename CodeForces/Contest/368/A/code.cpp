#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
#define cls(a) memset(a,0,sizeof(a))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	bool flag=0;
	rep(i,1,n)rep(j,1,m){
		char c=getchar();while(c<'A'||c>'Z')c=getchar();
		if(c=='C'||c=='M'||c=='Y')flag=1;
	}
	if(flag)printf("#Color");else printf("#Black&White");
	return 0;
}
