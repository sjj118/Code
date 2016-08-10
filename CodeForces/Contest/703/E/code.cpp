#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
#define cls(a) memset(a,0,sizeof(a))
typedef long long LL;
const int maxn=1010,maxv=10000;
const LL inf=1e18;
using namespace std;
inline char gc(){char c=getchar();while(!(c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0;char c=gc();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
int n,tot;
LL k,a;
LL prime[20],mod[20],maxp=1;
int cnt[20];
LL sum[2][maxv];
LL num[2][maxv];
bool sel[maxn][maxv];
int id[maxn][maxv];
int c[20],p,b[20],d[20],r;
void dfs(int k){
	if(k==tot+1){
		if(num[r&1][p]<inf){
			rep(i,1,tot)d[i]=min(cnt[i],b[i]+c[i]);
			LL t=d[1];rep(i,2,tot)t=t*(cnt[i]+1)+d[i];
			if(num[r&1^1][t]>num[r&1][p]+1){
				num[r&1^1][t]=num[r&1][p]+1;
				sum[r&1^1][t]=sum[r&1][p]+a;
				sel[r+1][t]=1,id[r+1][t]=p;
			}else if(num[r&1^1][t]==num[r&1][p]+1&&sum[r&1^1][t]>sum[r&1][p]+a){
				sum[r&1^1][t]=sum[r&1][p]+a;
				sel[r+1][t]=1,id[r+1][t]=p;
			}
			if(num[r&1^1][p]>num[r&1][p]){
				num[r&1^1][p]=num[r&1][p];
				sum[r&1^1][p]=sum[r&1][p];
				sel[r+1][p]=0,id[r+1][p]=p;
			}else if(num[r&1^1][p]==num[r&1][p]&&sum[r&1^1][p]>sum[r&1][p]){
				sum[r&1^1][p]=sum[r&1][p];
				sel[r+1][p]=0,id[r+1][p]=p;
			}
		}
		++p;
		return;
	}
	rep(i,0,cnt[k])b[k]=i,dfs(k+1);
}
int main(){
	n=read();k=read();
	if(k==1){
		printf("1\n");
		LL minv=inf,x,pos=0;
		rep(i,1,n){x=read();if(x<minv)minv=x,pos=i;}
		printf("%d",pos);
		return 0;
	}
	for(LL i=2;i*i<=k;++i)if(!(k%i)){
		prime[++tot]=i;mod[tot]=1;
		while(!(k%i))k/=i,++cnt[tot],mod[tot]*=i;
		maxp*=cnt[tot]+1;
	}
	if(k>1)prime[++tot]=k,cnt[tot]=1,mod[tot]=k,maxp*=cnt[tot]+1;
	rep(i,0,maxp-1)num[0][i]=inf,sum[0][i]=inf;
	num[0][0]=0;sum[0][0]=0;
	for(r=0;r<n;++r){
		a=read();
		cls(c);LL tmp=a;
		rep(j,1,tot)while(!(tmp%prime[j]))tmp/=prime[j],++c[j];
		rep(i,0,maxp-1)num[r&1^1][i]=inf,sum[r&1^1][i]=inf;
		p=0;dfs(1);
	}
	if(num[n&1][maxp-1]==inf)printf("-1");
	else{
		printf("%d\n",num[n&1][maxp-1]);
		p=maxp-1;
		per(i,n,1){if(sel[i][p])printf("%d ",i);p=id[i][p];}
	}
	return 0;
}
