#include<iostream>
#include<cstdio>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=100+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,r,c[N],num[N][N];
char s[N][N][N],f[N][N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int k;scanf("%d%s",&k,f[i]);
		up(r,k);
		rep(j,1,k){
			scanf("\n%s",s[i][j]);
			int l=strlen(s[i][j]);
			rep(p,0,l-1)if(s[i][j][p]==',')++num[i][j];
			up(c[i],num[i][j]);
		}
	}
	rep(i,1,n){
		if(i!=1)printf(",");
		printf("%s",f[i]);
		rep(j,1,c[i])printf(",");
	}
	puts("");
	rep(i,1,r){
		rep(j,1,n){
			if(j!=1)printf(",");
			printf("%s",s[j][i]);
			rep(k,num[j][i]+1,c[j])printf(",");
		}
		puts("");
	}
	return 0;
}
