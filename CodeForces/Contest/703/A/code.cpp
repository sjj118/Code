#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
int n,a,b;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int x,y;scanf("%d%d",&x,&y);
		if(x>y)++a;if(y>x)++b;
	}
	if(a>b)printf("Mishka");
	else if(b>a)printf("Chris");
	else printf("Friendship is magic!^^"); 
}
