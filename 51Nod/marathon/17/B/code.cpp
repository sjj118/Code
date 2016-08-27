#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int mo=1e9+7;
typedef long long LL;
inline void ck(LL&x){x%=mo;if(x<0)x+=mo;}
inline void ad(LL&x,LL y){x+=y;ck(x);}
LL n;
struct Matrix{
	int h,w;
	LL v[3][3];
	Matrix(int _h=0,int _w=0){h=_h;w=_w;cls(v);}
}T,F,I;
Matrix operator*(const Matrix&a,const Matrix&b){
	Matrix c(a.h,b.w);
	rep(i,1,c.h)rep(k,1,a.w)rep(j,1,c.w)ad(c.v[i][j],a.v[i][k]*b.v[k][j]%mo);
	return c;
}
Matrix power(Matrix x,LL y){Matrix a=I;for(;y;y>>=1,x=x*x)if(y&1)a=a*x;return a;}
int main(){
	scanf("%lld",&n);
	I.h=2,I.w=2;I.v[1][1]=1;I.v[2][2]=1;
	F.h=1;F.w=2,F.v[1][1]=1;F.v[1][2]=0;
	T.h=2;T.w=2;T.v[1][1]=2;T.v[1][2]=1;
	T.v[2][1]=1;T.v[2][2]=0;
	F=F*power(T,n);
	if(n&1)printf("%lld",2*F.v[1][2]*F.v[1][2]%mo);else printf("%lld",(2*F.v[1][2]*F.v[1][2]+1)%mo);
	return 0;
}
