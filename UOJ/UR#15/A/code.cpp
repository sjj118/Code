#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
int n,m,k,rev;
void output(int x,int y){if(rev)printf("%d %d\n",y,x);else printf("%d %d\n",x,y);}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k==1||k==2&&min(n,m)>1){puts("-1");return 0;}
	if((n*m&1)==0){
		if(n&1)rev=1,swap(n,m);
		rep(i,1,m)if(i%4==2||i%4==3)rep(j,1,n)output(j,i);else per(j,n,1)output(j,i);
	}else{
		if(n>m)rev=1,swap(n,m);
		if(k>n){
			rep(i,1,n)rep(j,1,m)output(i,j);
		}else{
			rep(i,1,n)output(i,1);
			for(int i=3;i<=m;){
				if(i%4==3){rep(j,1,n)output(j,i);--i;}
				else if(i%4==2){rep(j,1,n)output(j,i);i+=2;}
				else if(i%4==0){rep(j,1,n)output(j,i);++i;}
				else if(i%4==1){rep(j,1,n)output(j,i);i+=2;}
			}
		}
	}
	return 0;
}
