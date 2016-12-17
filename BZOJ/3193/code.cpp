#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a));
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1000+10,mo=2011;
int n,f[N][N];
struct Mountain{
	int h,d;
}m[N];
bool operator<(const Mountain&a,const Mountain&b){return a.h>b.h||a.h==b.h&&a.d<b.d;}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&m[i].h,&m[i].d);
	sort(m+1,m+1+n);
	f[0][0]=1;int ans=1,hi=0;
	rep(i,1,n){
		if(m[i].h!=m[i-1].h){
			rep(j,1,i)(f[i-1][0]+=f[i-1][j])%=mo,f[i-1][j]=0;
			hi=i-1;
		}
		f[i][0]=f[i-1][0];
		rep(j,1,min(hi,m[i].d-1))f[i][j]=(f[i][j-1]+f[i-1][j])%mo;
		ans=ans*(min(i-1,m[i].d-1+i-1-hi)+1)%mo;
	}
	printf("%d ",ans);
	ans=0;
	rep(i,0,n)(ans+=f[n][i])%=mo;
	printf("%d",ans);
	return 0;
}
