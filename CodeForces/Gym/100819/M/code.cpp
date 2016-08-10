#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
int n;
struct Operation{
	char kind[10];
	int x;
}a[12];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%s%d",a[i].kind,&a[i].x);
	int ans=0;
	rep(i,1,100){
		int x=i;bool flag=0;
		rep(j,1,n){
			if(a[j].kind[0]=='A')x+=a[j].x;
			if(a[j].kind[0]=='S'){x-=a[j].x;if(x<0)flag=1;}
			if(a[j].kind[0]=='M')x*=a[j].x;
			if(a[j].kind[0]=='D'){if(x%a[j].x)flag=1;x/=a[j].x;}
		}
		if(flag)++ans;
	}
	printf("%d",ans);
	return 0;
}
