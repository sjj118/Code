#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=100+10,L=100;
template<class T>inline T abs(T x){return x>0?x:-x;}
int n;
struct Bignum{
	int deg,val[L],f;
	Bignum();
	Bignum(int x);
	friend Bignum operator+(const Bignum&a,const Bignum&b);
	friend Bignum operator-(const Bignum&a,const Bignum&b);
	friend Bignum operator*(const Bignum&a,const Bignum&b);
	friend Bignum operator/(const Bignum&a,const Bignum&b);
	friend bool operator<(const Bignum&a,const Bignum&b);
	friend bool operator>(const Bignum&a,const Bignum&b);
	Bignum&operator+=(const Bignum&b);
	Bignum&operator-=(const Bignum&b);
	Bignum&operator*=(const Bignum&b);
	Bignum&operator/=(const Bignum&b);
	bool iszero()const;
	void output()const;
};
Bignum::Bignum(){deg=0;f=1;cls(val);}
Bignum::Bignum(int x){
	deg=0;f=1;cls(val);
	if(x<0)x=-x,f=-1;
	while(x)val[++deg]=x%10,x/=10;
	rep(i,1,deg>>1)swap(val[i],val[deg-i+1]);
}
Bignum operator+(const Bignum&a,const Bignum&b){
	
}
Bignum operator-(const Bignum&a,const Bignum&b){
}
Bignum operator*(const Bignum&a,const Bignum&b){}
Bignum operator/(const Bignum&a,const Bignum&b){}
bool operator<(const Bignum&a,const Bignum&b){}
bool operator>(const Bignum&a,const Bignum&b){}
Bignum&Bignum::operator+=(const Bignum&b){}
Bignum&Bignum::operator-=(const Bignum&b){}
Bignum&Bignum::operator*=(const Bignum&b){}
Bignum&Bignum::operator/=(const Bignum&b){}
bool Bignum::iszero()const{}
void Bignum::output()const{}
struct Matrix{
	int w,h;
	Bignum val[N][N];
	Matrix(){w=h=0;cls(val);}
	Matrix(int _h,int _w){w=_w;h=_h;cls(val);}
	Matrix(int x){w=h=x;cls(val);rep(i,1,x)val[i][i]=1;}
	void Gauss(){
		rep(i,1,w){
			int k=i;
			rep(j,i,h)if(val[j][i]>val[k][i])k=j;
			rep(j,1,w)swap(val[i][j],val[k][j]);
			rep(j,i+1,h){
				while(!val[j][i].iszero()){
					Bignum t=val[k][i]/val[j][i];
					rep(p,i,w)val[k][p]-=t*val[j][p];
					rep(p,i,w)swap(val[k][p],val[j][p]);
				}
			}
		}
	}
}D;
int main(){
	scanf("%d",&n);
	D.h=D.w=n;
	rep(i,1,n)D.val[i][i]=3;
	rep(i,1,n-1)D.val[i][i+1]=D.val[i+1][i]=-1;D.val[n][1]=D.val[1][n]=-1;
	D.Gauss();
	Bignum ans=Bignum(1);
	rep(i,1,n)ans*=D.val[i][i];
	ans.output();
	return 0;
}
