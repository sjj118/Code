#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=2000+10;
int n,m,x,ans,a[maxn],b[maxn],l;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	x=n/m;
	rep(i,1,n)if(a[i]<=m)++b[a[i]];
	ans=m*x;
	rep(i,1,m)ans-=min(x,b[i]);
	printf("%d %d\n",x,ans);l=1;
	rep(i,1,n){
		if(a[i]>m||b[a[i]]>x){
			while(l<=m&&b[l]>=x)++l;
			if(l<=m){
				if(a[i]<=m)--b[a[i]];
				a[i]=l;++b[l];
			}
		}
		printf("%d ",a[i]);
	}
	return 0;
}
