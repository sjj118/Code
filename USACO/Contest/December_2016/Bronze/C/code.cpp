#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=10+4;
int n,m,k;
char map[N][N];
int main(){
	freopen("cowsignal.in","r",stdin);freopen("cowsignal.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("\n%s",map[i]+1);
	rep(i,1,n)rep(_,1,k){
		rep(j,1,m)rep(__,1,k)printf("%c",map[i][j]);puts("");
	}
	return 0;
}
