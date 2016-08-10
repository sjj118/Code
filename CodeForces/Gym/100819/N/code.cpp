#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=110;
int n,k;
struct Expr{
	int x,y;
}a[maxn];
bool operator<(Expr a,Expr b){
	return a.x<b.x;
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		char s[10];scanf("%d%s",&a[i].x,s);
		if(s[0]=='S')a[i].y=0;else a[i].y=1;
	}
	a[++n].x=1;a[n].y=0;a[++n].x=k;a[n].y=1;
	sort(a+1,a+1+n);
	rep(i,1,n)if(a[i].y==1){printf("%d %d",a[i-1].x+1,a[i].x-1);break;}
	return 0;
}
