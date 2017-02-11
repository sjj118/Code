#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::sort;
const int N=50000+10,mo=1e5+7,inf=100000;
inline int lowbit(int x){return x&(-x);}
inline void ck(int&x,int p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(int&x,int y,int p){x+=y;ck(x,p);}
int n,k,dp[N][12][2];
struct Point{
	int x,y;
}p[N];
bool operator<(const Point&a,const Point&b){return a.x<b.x;}
struct BIT{
	int arr[inf+10];
	void clear(){cls(arr);}
	void add(int x,int y){
		for(;x<=inf;x+=lowbit(x))ad(arr[x],y,mo);
	}
	int sum(int x){
		int ret=0;
		for(;x;x-=lowbit(x))ad(ret,arr[x],mo);
		return ret;
	}
}s[12][2],b[12][2],ss,bb;
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+1+n);
	rep(i,1,n){
		per(j,k,1){
			dp[i][j][0]=s[j][0].sum(p[i].y-1)+s[j-1][1].sum(p[i].y-1);ck(dp[i][j][0],mo);
			dp[i][j][1]=b[j][1].sum(inf-p[i].y)+b[j-1][0].sum(inf-p[i].y);ck(dp[i][j][1],mo);
			s[j][0].add(p[i].y,dp[i][j][0]);
			s[j][1].add(p[i].y,dp[i][j][1]);
			b[j][0].add(inf-p[i].y+1,dp[i][j][0]);
			b[j][1].add(inf-p[i].y+1,dp[i][j][1]);
		}
		int t=ss.sum(p[i].y-1);
		ad(dp[i][1][0],t,mo);
		s[1][0].add(p[i].y,t);
		b[1][0].add(inf-p[i].y+1,t);
		t=bb.sum(inf-p[i].y);
		ad(dp[i][1][1],t,mo);
		s[1][1].add(p[i].y,t);
		b[1][1].add(inf-p[i].y+1,t);
		ss.add(p[i].y,1);
		bb.add(inf-p[i].y+1,1);
	}
	int ans=0;
	rep(i,1,n)ad(ans,dp[i][k][0],mo),ad(ans,dp[i][k][1],mo);
	printf("%d",ans);
	return 0;
}
