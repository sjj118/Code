#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=33;
int n,m,k;
inline void ck(int&a,int p){if(a>=p)a-=p;if(a<0)a+=p;}
inline void ad(int&a,int b,int p){a+=b;ck(a,p);}
struct Matrix{
	int h,w,val[maxn][maxn];
	Matrix(int _h=0,int _w=0){h=_h;w=_w;cls(val);}
}A,I;
Matrix operator+(const Matrix&a,const Matrix&b){
	Matrix c(a.h,a.w);
	rep(i,1,c.h)rep(j,1,c.w)c.val[i][j]=a.val[i][j]+b.val[i][j],ck(c.val[i][j],m);
	return c;
}
Matrix operator*(const Matrix&a,const Matrix&b){
	Matrix c(a.h,b.w);
	rep(i,1,c.h)rep(k,1,a.w)rep(j,1,c.w)ad(c.val[i][j],a.val[i][k]*b.val[k][j]%m,m);
	return c;
}
Matrix power(Matrix x,int y){Matrix a=I;for(;y;y>>=1,x=x*x)if(y&1)a=a*x;return a;}
Matrix powersum(const Matrix&x,int y){
	if(y==1)return x;
	if(y&1)return x*powersum(x,y^1)+x;
	return (power(x,y>>1)+I)*powersum(x,y>>1);
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	I.h=I.w=n;rep(i,1,n)I.val[i][i]=1;A.h=A.w=n;
	rep(i,1,n)rep(j,1,n)scanf("%d",&A.val[i][j]),A.val[i][j]%=m;
	A=powersum(A,k);
	rep(i,1,n){rep(j,1,n)printf("%d ",A.val[i][j]);puts("");}
	return 0;
}
