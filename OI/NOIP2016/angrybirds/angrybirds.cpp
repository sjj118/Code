#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
const int N=18+2,V=(1<<18)+10;
const double eps=1e-5;
inline void dn(int&x,int y){if(y<x)x=y;}
inline int lowbit(int x){return x&(-x);}
int n,m,v,f[V],co[V],g[N*N],tot;
int dblcmp(double x){if(fabs(x)<eps)return 0;return x>0?1:-1;}
double x[N],y[N];
int main(){
	int T;scanf("%d",&T);
	rep(i,1,V-1)co[i]=co[i>>1]+(i&1);
	while(T--){
		scanf("%d%d",&n,&m);v=1<<n;
		rep(i,1,n)scanf("%lf%lf",&x[i],&y[i]);
		cls(f);tot=0;
		rep(i,1,n)rep(j,i+1,n){
			bool flag=0;
			rep(k,1,tot)if(((g[k]>>(i-1))&1)&&((g[k]>>(j-1))&1))flag=1;
			if(flag)continue;
			if(dblcmp(x[i]-x[j])==0)continue;
			double a=1.0*(x[j]*y[i]-x[i]*y[j])/(x[i]*x[j]*(x[i]-x[j]));
			double b=1.0*(y[i]-a*x[i]*x[i])/x[i];
			if(dblcmp(a)>=0)continue;
			int tmp=0;
			rep(k,1,n)if(dblcmp(a*x[k]*x[k]+b*x[k]-y[k])==0)tmp|=1<<(k-1);
			g[++tot]=tmp;
		}
		rep(i,1,v-1){
			f[i]=co[i];
			rep(j,1,tot)dn(f[i],f[(i|g[j])^g[j]]+1);
		}
		printf("%d\n",f[v-1]);
	}
	return 0;
}
}
int main(){
	freopen("angrybirds.in","r",stdin);freopen("angrybirds.out","w",stdout);
	return sjj118::main();
}
