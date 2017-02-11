#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<assert.h>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=140+5;
const int ha=2333333,P=200;
inline void ck(int&x,int p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(int&x,int y,int p){x+=y;ck(x,p);}
inline int power(int x,int y,int p){int a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline int inv(int n,int p){return power(n,p-2,p);}
int n,p;
struct Matrix{
	int n,m,val[N][N];
	Matrix(){n=m=0;cls(val);}
	Matrix(int n,int m):n(n),m(m){cls(val);}
	static Matrix I(int n){Matrix ret(n,n);rep(i,1,n)ret[i][i]=1;return ret;}
	int*operator[](int x){return val[x];}
	const int*operator[](int x)const{return val[x];}
	void input(int _n,int _m){
		n=_n;m=_m;
		rep(i,1,n)rep(j,1,m)scanf("%d",&val[i][j]);
	}
	void output(){
		rep(i,1,n){
			rep(j,1,m)printf("%5d",val[i][j]);puts("");
		}
	}
	friend Matrix operator*(const Matrix&a,const Matrix&b){
		Matrix ret(a.n,b.m);
		rep(i,1,ret.n)rep(k,1,a.m)rep(j,1,ret.m)ad(ret[i][j],a[i][k]*b[k][j]%p,p);
		return ret;
	}
	friend bool operator==(const Matrix&a,const Matrix&b){
		if(a.n!=b.n||a.m!=b.m)return 0;
		rep(i,1,a.n)rep(j,1,a.m)if(a[i][j]!=b[i][j])return 0;
		return 1;
	}
	int hash()const{
		LL ret=(n*13131+m)%ha;
		rep(i,1,n)rep(j,1,m)ret=(ret*(i+j+13131)+val[i][j])%ha;
		return ret;
	}
	void Gauss(){
		rep(i,1,n){
			rep(j,i+1,n)if(val[j][i]){
				rep(k,1,m)swap(val[i][k],val[j][k]);
				break;
			}
			rep(j,i+1,n){
				int t=inv(val[i][i],p)*val[j][i]%p;
				rep(k,1,m)ad(val[j][k],-val[i][k]*t%p,p);
			}
		}
		per(i,n,1){
			int t=inv(val[i][i],p);
			rep(j,i,m)val[i][j]=val[i][j]*t%p;
			rep(j,1,i-1){
				per(k,m,i)ad(val[j][k],-val[j][i]*val[i][k]%p,p);
			}
		}
	}
	Matrix getInv()const{
		Matrix ret(n,m*2);
		rep(i,1,n)rep(j,1,m)ret[i][j]=val[i][j];
		rep(i,1,n)ret[i][m+i]=1;
		ret.Gauss();
		rep(i,1,n)rep(j,1,m)ret[i][j]=ret[i][j+m];
		ret.m=m;
		return ret;
	}
}A,B;
struct HashTable{
	int tot,head[ha],next[P],val[P];
	Matrix key[P];
	int find(const Matrix&a){int k=a.hash();for(int p=head[k];p;p=next[p])if(key[p]==a)return p;return 0;}
	void ins(const Matrix&a,int b){key[++tot]=a;val[tot]=b;int k=a.hash();next[tot]=head[k];head[k]=tot;}
	void insert(const Matrix&a,int b){
		int t=find(a);
		if(t)return;
		ins(a,b);
	}
}ht;
Matrix power(Matrix x,int y){Matrix a=Matrix::I(x.n);for(;y;y>>=1,x=x*x)if(y&1)a=a*x;return a;}
int BSGS(Matrix a,Matrix b){
	int L=round(sqrt(p));
	Matrix m=Matrix::I(a.n);
	for(int i=0;i<L;++i,m=m*a)ht.ins(m,i);
	m=m.getInv();
	for(int i=0;i*L<=p;++i,b=b*m){
		int t=ht.find(b);
		if(t)return i*L+ht.val[t];
	}
	assert(0);
}
int main(){
	scanf("%d%d",&n,&p);
	A.input(n,n);
	B.input(n,n);
	printf("%d",BSGS(A,B));
	return 0;
}
