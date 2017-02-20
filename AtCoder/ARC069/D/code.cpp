#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=1e5+10;
inline bool vaild(char c){return c=='o'||c=='x';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n;
int s[N],a[N];
bool work(int a1,int a2){
	a[1]=a1;a[2]=a2;
	rep(i,3,n){
		a[i]=a[i-1]^s[i-1]^a[i-2];
	}
	return a[n]^a[2]^a[1]^s[1]==0&&a[n]^s[n]^a[n-1]^a[1]==0;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)s[i]=(gc()=='x');
	if(work(0,0)||work(0,1)||work(1,0)||work(1,1)){
		rep(i,1,n)printf("%c",a[i]?'W':'S');
	}else puts("-1");
	return 0;
}
