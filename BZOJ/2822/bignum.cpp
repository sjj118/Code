#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
inline void up(int&x,int y){if(y>x)x=y;}
struct Bignum{
	static const int B=1000;
	int deg,a[B];
	Bignum(){deg=0;cls(a);}
	Bignum(int x){
		deg=0;cls(a);
		while(x)a[++deg]=x%10,x/=10;
	}
	void update(){
		while(a[deg+1])++deg;
		while(a[deg]==0)--deg;
	}
	Bignum&operator+=(const Bignum&x){
		up(deg,x.deg);
		rep(i,1,deg){
			a[i]+=x.a[i];
			if(a[i]>=10)++a[i+1],a[i]-=10;
		}
		update();
		return *this;
	}
	void output(){
		if(deg==0)putchar('0');
		per(i,deg,1)printf("%d",a[i]);
	}
};
Bignum operator*(const Bignum&x,const Bignum&y){
	Bignum ret;
	ret.deg=x.deg+y.deg-1;
	rep(i,1,x.deg)rep(j,1,y.deg){
		ret.a[i+j-1]+=x.a[i]*y.a[j];
		ret.a[i+j]+=ret.a[i+j-1]/10;
		ret.a[i+j-1]%=10;
	}
	ret.update();
	return ret;
}
Bignum operator/(const Bignum&x,int y){
	Bignum ret;
	ret.deg=x.deg;
	per(i,ret.deg,1)ret.a[i]+=x.a[i],ret.a[i-1]+=ret.a[i]%y*10,ret.a[i]/=y;
	ret.update();
	return ret;
}
Bignum x,y; 
int main(){
	int a,b;scanf("%d%d",&a,&b);
	printf("%d\n",a/b);
	x=Bignum(a);y=Bignum(b);
	(x/b).output();
	return 0;
}
