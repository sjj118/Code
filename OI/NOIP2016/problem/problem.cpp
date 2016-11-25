#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2000+10;
int t,k,c[N][N],d[N][N];
int main(){
	scanf("%d%d",&t,&k);
	rep(i,0,N-1){
		c[i][0]=1;
		rep(j,1,i){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			if(c[i][j]>=k)c[i][j]-=k;
		}
	}
	rep(i,1,N-1){
		d[i][0]=d[i-1][0]+(c[i][0]==0);
		rep(j,1,i-1)d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+(c[i][j]==0);
		d[i][i]=d[i][i-1]+(c[i][i]==0);
	}
	rep(i,1,t){
		int n,m;scanf("%d%d",&n,&m);
		m=min(n,m);
		printf("%d\n",d[n][m]);
	}
	return 0;
}
