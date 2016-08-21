#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
inline void dn(int&x,int y){if(y<x)x=y;}
const int maxn=24,inf=1e9;
inline int id(int x){
	if(x>=3&&x<=13)return x-2;
	if(x==1)return 12;
	if(x==2)return 13;
	if(x==0)return 14;
	return -1;
}
int n,num[16];
const int p4=6,p3=8,p2=12,p1=14;
int dp[p4][p3][p2][p1][3];
int cnt[5];
int ans;
void dfs(int l,int r,int h){ 
	cls(cnt);
	rep(i,1,13)++cnt[num[i]];
	dn(ans,h+dp[cnt[4]][cnt[3]][cnt[2]][cnt[1]][num[14]]);
	rep(i,l,11){
		int minc=inf;
		rep(j,i,12){
			dn(minc,num[j]);
			if(minc==0)break;
			if(i==l&&j<=r)continue;
			int low=4;
			if(j-i+1>=2)low=3;
			if(j-i+1>=3)low=2;
			if(j-i+1>=5)low=1;
			if(low<=minc)rep(p,i,j)num[p]-=low-1;
			rep(k,low,min(minc,3)){
				rep(p,i,j)--num[p];
				dfs(i,j,h+1);
			}
			if(low<=minc)rep(p,i,j)num[p]+=low-1;
			rep(k,low,min(minc,3)){
				rep(p,i,j)++num[p];
			}
		}
	}
}
int dai(int i4,int i3,int i2,int i1,int iw,int da,int cheng){
	if(i4<0||i3<0||i2<0||i1<0||iw<0)return inf;
	if(cheng==0)return dp[i4][i3][i2][i1][iw];
	int ans=inf;
	if(da==1){
		dn(ans,dai(i4,i3,i2,i1,iw-1,da,cheng-1));
		dn(ans,dai(i4,i3,i2,i1-1,iw,da,cheng-1));
		dn(ans,dai(i4,i3,i2-1,i1+1,iw,da,cheng-1));
		dn(ans,dai(i4,i3-1,i2+1,i1,iw,da,cheng-1));
		dn(ans,dai(i4-1,i3+1,i2,i1,iw,da,cheng-1));
	}else if(da==2){
		dn(ans,dai(i4,i3,i2-1,i1,iw,da,cheng-1));
		dn(ans,dai(i4,i3-1,i2,i1+1,iw,da,cheng-1));
		dn(ans,dai(i4-1,i3,i2+1,i1,iw,da,cheng-1));
	}
	return ans;
}
int main(){
	int T;scanf("%d%d",&T,&n);
	rep(i1,0,p4-1)rep(i2,0,p3-1)rep(i3,0,p2-1)rep(i4,0,p1-1)rep(i5,0,2)dp[i1][i2][i3][i4][i5]=inf;
	dp[0][0][0][0][0]=0;
	rep(i4,0,p4-1)rep(i3,0,p3-1)rep(i2,0,p2-1)rep(i1,0,p1-1)rep(iw,0,2){
		dn(dp[i4][i3][i2][i1][iw],dp[i4][i3][i2][i1][0]+1);
		if(i1-1>=0)dn(dp[i4][i3][i2][i1][iw],dp[i4][i3][i2][i1-1][iw]+1);
		if(i2-1>=0)dn(dp[i4][i3][i2][i1][iw],dp[i4][i3][i2-1][i1][iw]+1);
		if(i3-1>=0){
			dn(dp[i4][i3][i2][i1][iw],dai(i4,i3-1,i2,i1,iw,0,0)+1);
			dn(dp[i4][i3][i2][i1][iw],dai(i4,i3-1,i2,i1,iw,1,1)+1);
			dn(dp[i4][i3][i2][i1][iw],dai(i4,i3-1,i2,i1,iw,2,1)+1);
		}
		if(i4-1>=0){
			dn(dp[i4][i3][i2][i1][iw],dai(i4-1,i3,i2,i1,iw,0,0)+1);
			dn(dp[i4][i3][i2][i1][iw],dai(i4-1,i3,i2,i1,iw,1,2)+1);
			dn(dp[i4][i3][i2][i1][iw],dai(i4-1,i3,i2,i1,iw,2,2)+1);
		}
	}
	while(T--){
		ans=inf;
		cls(num);
		rep(i,1,n){
			int x,t;scanf("%d%d",&x,&t);
			++num[id(x)];
		}
		dfs(1,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
