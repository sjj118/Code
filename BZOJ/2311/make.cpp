#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=50+5;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int n,m;
bool vaild(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m;}
double p[4][N][N];
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	n=50,m=50;
	printf("%d %d\n",n,m);
	rep(i,1,n){
		rep(j,1,m){
			int deg=0;
			rep(k,0,3)if(vaild(i+dx[k],j+dy[k]))++deg;
			rep(k,0,3)if(vaild(i+dx[k],j+dy[k]))p[k][i][j]=1.0/deg;
		}
		puts("");
	}
	rep(k,0,3)p[k][n][m]=0;
	rep(k,0,3){
		rep(i,1,n){
			rep(j,1,m)printf("%lf ",p[k][i][j]);
			puts("");
		}
	}
}
