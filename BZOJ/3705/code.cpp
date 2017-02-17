#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::min;
using std::max;
using std::swap;
const int N=2000+10,inf=1e9+2;
inline void dn(int&x,int y){if(y<x)x=y;}
inline void up(int&x,int y){if(y>x)x=y;}
int len[N][N];
int n,m,a[N][N],r[N][N];
void output(){
	rep(i,0,2*n+2){
		rep(j,0,2*m+2)printf("%5d ",len[i][j]);puts("");
	}
	puts("");
}
int b[N][N];
void rotate(){
	rep(i,0,2*n+2)rep(j,0,2*m+2)b[2*m+2-j][i]=a[i][j];
	rep(i,0,2*m+2)rep(j,0,2*n+2)a[i][j]=b[i][j];
	rep(i,0,2*n+2)rep(j,0,2*m+2)b[2*m+2-j][i]=r[i][j];
	rep(i,0,2*m+2)rep(j,0,2*n+2)r[i][j]=b[i][j];
	rep(i,0,2*n+2)rep(j,0,2*m+2)b[2*m+2-j][i]=len[i][j];
	rep(i,0,2*m+2)rep(j,0,2*n+2)len[i][j]=b[i][j];
	swap(n,m);
}
void manacher(){
	rep(k,1,2*n+1){
		int mx=1;
		int*rr=r[k];
		int*aa=a[k];
		rr[1]=0;
		rep(i,1,2*m+1){
			rr[i]=min(mx+rr[mx]-i,rr[2*mx-i]);
			while(aa[i+rr[i]]==aa[i-rr[i]])++rr[i];
			if(i+rr[i]>mx+rr[mx])mx=i;
		}
	}
}
int q[N],ql,qr,p;
void solve(){
	rep(i,1,2*n+1){
		ql=1;qr=0;p=0;
		int*rr=r[i];
		rep(j,1,2*m+1){
			while(ql<=qr&&rr[j]<=rr[q[qr]])--qr;
			dn(p,qr);
			q[++qr]=j;
			while(p<qr&&rr[q[p+1]]<=j-q[p])++p;
			int tmp=0;
			if(p)up(tmp,min(j-q[p-1],rr[q[p]]));
			if(p<qr)up(tmp,min(j-q[p],rr[q[p+1]]));
			dn(len[i][j],tmp);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[2*i][2*j]);
	rep(i,0,2*n+2)rep(j,0,2*m+2){
		if(i==0||j==0)a[i][j]=-1;
		else if(i==2*n+2||j==2*m+2)a[i][j]=-2;
		else if((i&1)||(j&1))a[i][j]=0;
	}
	rep(i,1,2*n+1)rep(j,1,2*m+1)len[i][j]=inf;
	rep(i,1,4){
		manacher();
		rotate();
		solve();
	}
	int ans=0;
	rep(i,1,2*n+1)rep(j,1,2*m+1)if(((i+j)&1)==0)ans+=len[i][j]/2;
	printf("%d",ans);
	return 0;
}
