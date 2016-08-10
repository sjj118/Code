#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
using namespace std;
int a[3],b[3];
int main(){
	rep(i,0,2)scanf("%d",&a[i]);sort(a,a+3);
	rep(i,0,2)scanf("%d",&b[i]);sort(b,b+3);
	bool flag=0;
	rep(i,0,2)if(a[i]!=b[i])flag=1;
	if(a[0]*a[0]+a[1]*a[1]!=a[2]*a[2])flag=1;
	if(flag)printf("NO");
	else printf("YES");
	return 0;
}
