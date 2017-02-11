#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef double real;
inline bool vaild(char c){return c=='-'||(c>='0'&&c<='9');}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0,f=1;char c=gc();if(c=='-')f=-1,c=getchar();while(vaild(c))ret=ret*10+c-'0',c=getchar();return f*ret;}
const int N=20+3;
const real eps=1e-8,inf=1e100;
int n,m,t,id[N<<1];
real a[N][N],A[N];
void pivot(int x,int y){
	swap(id[x],id[n+y]);
	rep(i,0,n)if(i!=x)a[y][i]/=a[y][x];a[y][x]=1/a[y][x];
	rep(i,0,m)if(i!=y){
		rep(j,0,n)if(j!=x)a[i][j]-=a[i][x]*a[y][j];a[i][x]=-a[i][x]*a[y][x];
	}
}
void output(){
	rep(i,0,m){
		rep(j,0,n)printf("%4.4lf ",a[i][j]);puts("");
	}
	puts("");
}
int solve(){
	rep(i,1,n+m)id[i]=i;
	while(1){
		int x=0,y=0;
		rep(i,1,m)if(a[i][0]<-eps)y=i;if(!y)break;
		rep(i,1,n)if(a[y][i]<-eps)x=i;if(!x)return -1;
		pivot(x,y);
	}
	while(1){
		//output();
		int x=0,y=0;real mn=inf;
		rep(i,1,n)if(a[0][i]>eps){x=i;break;}if(!x)break;
		rep(i,1,m)if(a[i][x]>eps&&a[i][0]/a[i][x]<mn-eps)mn=a[i][0]/a[i][x],y=i;if(!y)return 0;
		pivot(x,y);
	}
	if(t)rep(i,1,m)if(id[n+i]<=n)A[id[n+i]]=a[i][0];
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&m,&t);
	rep(i,1,n)a[0][i]=read();
	rep(i,1,m){
		rep(j,1,n)a[i][j]=read();
		a[i][0]=read();
	}
	int tmp=solve();
	if(tmp==1)printf("%.10lf\n",(double)-a[0][0]);
	else if(tmp==0)puts("Unbounded");
	else puts("Infeasible");
	if(t&&tmp==1)rep(i,1,n)printf("%.10lf ",(double)A[i]);
	return 0;
}
