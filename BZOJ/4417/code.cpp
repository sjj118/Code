#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int mo=30011,maxn=110;
typedef long long LL;
using namespace std;
inline void ck(int&x){while(x<0)x+=mo;while(x>=mo)x-=mo;}
inline void ad(int&x,int y){x+=y%mo;ck(x);}
int n,m;
struct Matrix{
	int h,w,val[maxn][maxn];
	Matrix(int _h,int _w){h=_h;w=_w;cls(val);}
	Matrix(int a){h=w=a;cls(val);rep(i,1,a)val[i][i]=1;}
	void write(){
		rep(i,1,h){
			rep(j,1,w)printf("%d ",val[i][j]);printf("\n");
		}puts("");
	}
};
Matrix operator*(const Matrix&a,const Matrix&b){
	Matrix c(b.h,a.w);
	rep(i,1,c.h)rep(k,1,a.h)rep(j,1,c.w)ad(c.val[i][j],a.val[k][j]*b.val[i][k]);
	return c;
}
Matrix power(Matrix x,LL y){
	Matrix a(x.w);
	while(y){
		if(y&1)a=a*x;
		x=x*x;
		y>>=1;
	}
	return a;
}
int main(){
	scanf("%d%d",&n,&m);
	Matrix f(n*2,1),t(n*2,n*2);
	f.val[n+1][1]=1;
	rep(i,1,n){
		t.val[i][n+i]+=1;
		t.val[n+i][n+i]+=1;
		if(i>1)t.val[n+i][n+i-1]+=1;
		if(i<n)t.val[n+i][n+i+1]+=1;
		t.val[n+i][i]=1;
	}
	f=f*power(t,m-2);
	printf("%d\n",(f.val[n*2][1]+((n>1)?f.val[n*2-1][1]:0))%mo);
	return 0;
}
