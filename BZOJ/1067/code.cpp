#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=5e4+10,inf=1e9+7;
int n,y[maxn],r[maxn];
int find_lowwer(int x){
	int l=0,r=n+1;
	while(l<r){
		int m=(l+r)>>1;
		if(y[m]<x)l=m+1;else r=m;
	}
	return l;
}
int find_upper(int x){
	int l=0,r=n+1;
	while(l<r){
		int m=(l+r+1)>>1;
		if(y[m]<=x)l=m;else r=m-1;
	}
	return l;
}
int mx[maxn][20],lg[maxn];
void pre(){
	rep(i,1,n)mx[i][0]=r[i];
	rep(j,1,19){
		rep(i,1,n){
			if(i+(1<<(j-1))<=n)mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
			else mx[i][j]=mx[i][j-1];
		}
	}
}
int getmax(int l,int r){
	if(l>r)return -inf;
	int x=lg[r-l+1]-1;
	return max(mx[l][x],mx[r-(1<<x)+1][x]);
}
int main(){
	scanf("%d",&n);y[0]=-inf;y[n+1]=inf;
	rep(i,1,n)lg[i]=lg[i>>1]+1;
	rep(i,1,n)scanf("%d%d",&y[i],&r[i]);
	pre();
	int q;
	scanf("%d",&q);
	while(q--){
		int s,t;scanf("%d%d",&s,&t);
		int a=find_lowwer(s),b=find_upper(t);
		if(s>=t)puts("false");
		else if(y[a]==s&&y[b]==t){
			if(r[b]>r[a]||getmax(a+1,b-1)>=r[b])puts("false");
			else if(t-s>b-a)puts("maybe");
			else puts("true");
		}else if(y[a]==s&&y[b]!=t){
			if(getmax(a+1,b)>=r[a])puts("false");
			else puts("maybe");
		}else if(y[a]!=s&&y[b]==t){
			if(getmax(a,b-1)>=r[b])puts("false");
			else puts("maybe");
		}else if(y[a]!=s&&y[b]!=t){
			puts("maybe");
		}
	}
	return 0;
}
