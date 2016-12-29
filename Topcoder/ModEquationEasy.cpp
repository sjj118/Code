#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int K=100+10,mo=1e9+7;
int n,k;
struct Matrix{
	int n,m;
	LL val[K][K];
	Matrix(){}
	Matrix(int n,int m):n(n),m(m){cls(val);}
	Matrix(int n):n(n),m(n){cls(val);rep(i,0,n-1)val[i][i]=1;}
}f,trans;
Matrix operator*(const Matrix&a,const Matrix&b){
	Matrix ret(a.n,b.m);
	rep(i,0,ret.n-1)rep(k,0,a.m-1)rep(j,0,ret.m-1)(ret.val[i][j]+=a.val[i][k]*b.val[k][j])%=mo;
	return ret;
}
Matrix power(Matrix x,LL y){Matrix a(x.n);for(;y;y>>=1,x=x*x)if(y&1)a=a*x;return a;}
class ModEquationEasy {
public:
	int count(int _n, int _K, int v) {
		n=_n;k=_K;
		f.n=k;f.m=1;f.val[1][0]=1;
		trans.n=trans.m=k;
		rep(i,0,k-1)rep(j,0,k-1)trans.val[i*j%k][i]++;
		f=power(trans,n)*f;
		return f.val[v][0];
	}
};
