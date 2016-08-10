#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int maxn=210;
using namespace std;
inline int read(){int tmp=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,k,a[maxn],b[maxn];
struct Bigint{
	int deg,a[200];
	void write(){
		printf("%d",a[deg]);
		per(i,deg-1,1)printf("%04d",a[i]);
	}
	inline void ck(){
		for(int i=1;i<=deg;++i){
			a[i+1]+=a[i]/10000;
			a[i]%=10000;
			if(a[i]<0)a[i]+=10000,--a[i+1];
			if(i==deg&&a[i+1])++deg;
		}
		while(deg&&!a[deg])--deg;
	}
	void operator+=(const Bigint&x){
		deg=max(deg,x.deg);
		rep(i,1,deg)a[i]+=x.a[i];
		ck();
	}
	void operator-=(const Bigint&x){
		deg=max(deg,x.deg);
		rep(i,1,deg)a[i]-=x.a[i];
		ck();
	}
}f[2][maxn],ans,fact[maxn],g[maxn],C[maxn][maxn];
Bigint operator+(const Bigint&a,const Bigint&b){
	Bigint x;x.deg=max(a.deg,b.deg);cls(x.a);
	rep(i,1,x.deg)x.a[i]=a.a[i]+b.a[i];
	x.ck();
	return x;
}
Bigint operator*(const Bigint&a,const int&b){
	Bigint x;cls(x.a);x.deg=a.deg;
	rep(i,1,x.deg)x.a[i]=a.a[i]*b;
	x.ck();
	return x;
}
Bigint operator*(const Bigint&a,const Bigint&b){
	Bigint x;cls(x.a);x.deg=a.deg+b.deg-1;
	rep(i,1,a.deg)rep(j,1,b.deg){
		x.a[i+j-1]+=a.a[i]*b.a[j];
		x.a[i+j]+=x.a[i+j-1]/10000;
		x.a[i+j-1]%=10000;
	}
	x.ck();
	return x;
}

int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d%d",&n,&k);
	rep(i,0,n){
		C[i][0].deg=1;C[i][0].a[1]=1;
		rep(j,1,n)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	fact[0].deg=1;fact[0].a[1]=1;rep(i,1,n)fact[i]=fact[i-1]*i;
	rep(i,1,n)a[i]=read();
	rep(i,1,n)b[i]=read();
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	int p=0;
	f[0][0].deg=1;f[0][0].a[1]=1;
	rep(i,1,n){
		while(p<n&&a[i]>=b[p+1])++p;
		rep(j,0,p){
			f[i&1][j]=f[i&1^1][j];
			if(j)f[i&1][j]+=f[i&1^1][j-1]*(p-j+1);
		}
	}
	per(i,n,n-k){
		g[i]=f[n&1][i]*fact[n-i];
		rep(j,i+1,n)g[i]-=g[j]*C[j][i];
		ans+=g[i];
	}
	ans.write();printf("\n");
	return 0;
}
