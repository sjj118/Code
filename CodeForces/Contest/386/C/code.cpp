#include<iostream>
#include<cstdio>
#include<cmath>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int s,x1,x2,t1,t2,p,d,ans;
int main(){
	scanf("%d%d%d",&s,&x1,&x2);
	scanf("%d%d",&t1,&t2);
	scanf("%d%d",&p,&d);
	ans=abs(x1-x2)*t2;
	int t=0,p1=0,p2=0;
	if(p==x1)p1=1;
	if(p1&&p==x2)p2=1;
	while(!p2){
		++t;
		if(p+d>s||p+d<0)d=-d;
		p+=d;
		if(p==x1)p1=1;
		if(p1&&p==x2)p2=1;
	}
	printf("%d",min(ans,t*t1));
	return 0;
}
