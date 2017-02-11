#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=10,d[8][2]={
	{2,1},
	{1,2},
	{-1,2},
	{-2,1},
	{-2,-1},
	{-1,-2},
	{1,-2},
	{2,-1}
},target[6][6]={
	{0,0,0,0,0,0},
	{0,1,1,1,1,1},
	{0,0,1,1,1,1},
	{0,0,0,-1,1,1},
	{0,0,0,0,0,1},
	{0,0,0,0,0,0}
};
inline bool vaild(char c){return c=='0'||c=='1'||c=='*';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int cw(char c){if(c=='*')return -1;return c-'0';}
inline void dn(int&x,int y){if(y<x)x=y;}
int a[N][N],ans;
bool cut(int step){
	if(step<=0)return 1;
	int cnt=0;
	rep(i,1,5)rep(j,1,5)if(!(i==3&&j==3)&&a[i][j]!=target[i][j])++cnt;
	if(cnt>step)return 1;
	return 0;
}
bool check(){
	rep(i,1,5)rep(j,1,5)if(a[i][j]!=target[i][j])return 0;
	return 1;
}
bool inside(int x,int y){return x>=1&&x<=5&&y>=1&&y<=5;}
void dfs(int step,int lstx,int lsty){
	if(check()){dn(ans,step);return;}
	if(cut(ans-step-1))return;
	int x,y;
	rep(i,1,5)rep(j,1,5)if(a[i][j]==-1)x=i,y=j;
	rep(i,0,7)if(inside(x+d[i][0],y+d[i][1])&&!(x+d[i][0]==lstx&&y+d[i][1]==lsty)){
		swap(a[x][y],a[x+d[i][0]][y+d[i][1]]);
		dfs(step+1,x,y);
		swap(a[x][y],a[x+d[i][0]][y+d[i][1]]);
	}
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		rep(i,1,5)rep(j,1,5)a[i][j]=cw(gc());
		ans=16;
		dfs(0,0,0);
		if(ans<16)printf("%d\n",ans);else puts("-1");
	}
	return 0;
}
