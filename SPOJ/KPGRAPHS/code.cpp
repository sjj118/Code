#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
const int mo=1e9+7,N=1000+10,_2=power(2,mo-2,mo);
LL C[N][N];
void init(){
	rep(i,0,N-1){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
}
namespace Connected{
	LL f[N],g[N];
	void init(){
		int n=N-1;
		cls(f);cls(g);
		rep(i,1,n)f[i]=power(2,C[i][2],mo);
		rep(i,1,n){
			g[i]=f[i];
			rep(j,1,i-1)ad(g[i],-g[j]*f[i-j]%mo*C[i-1][j-1]%mo,mo);
		}
	}
	int main(LL n){
		return g[n];
	}
}
namespace Eulerian{
	LL f[N],g[N];
	void init(){
		int n=N-1;
		cls(f);cls(g);
		rep(i,1,n)f[i]=power(2,C[i-1][2],mo);
		rep(i,1,n){
			g[i]=f[i];
			rep(j,1,i-1)ad(g[i],-g[j]*f[i-j]%mo*C[i-1][j-1]%mo,mo);
		}
	}
	int main(LL n){
		return g[n];
	}
}
namespace Bipartite{
	LL f[N],g[N],h[N];
	void init(){
		int n=N-1;
		rep(i,1,n)rep(j,0,i)ad(f[i],C[i][j]*power(2,j*(i-j),mo)%mo,mo);
		rep(i,1,n){
			g[i]=f[i];
			rep(j,1,i-1){
				ad(g[i],-g[j]*f[i-j]%mo*C[i-1][j-1]%mo,mo);
			}
		}
		h[0]=1;rep(i,1,n)rep(j,1,i)ad(h[i],g[j]*h[i-j]%mo*C[i-1][j-1]%mo*_2%mo,mo);
	}
	int main(LL n){
		return h[n];
	}
}
int main(){
	int T;scanf("%d",&T);
	init();
	Connected::init();
	Eulerian::init();
	Bipartite::init();
	while(T--){
		LL n;scanf("%lld",&n);
		printf("Connected: %d\n",Connected::main(n));
		printf("Eulerian: %d\n",Eulerian::main(n));
		printf("Bipartite: %d\n\n",Bipartite::main(n));
	}
	return 0;
}
