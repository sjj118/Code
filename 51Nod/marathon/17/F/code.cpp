#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxd=100,maxk=9,mo=1e9+7,maxl=7e3;
inline void ck(LL&x){if(x<0)x+=mo;if(x>=mo)x-=mo;}
inline void ad(LL&x,LL y){x+=y;ck(x);}
struct Polynomial{
	int deg;
	LL a[maxd];
	void clear(){deg=0;cls(a);}
	Polynomial(int d=0){deg=d;cls(a);}
	LL operator[](const LL&x){
		LL ans=0,tmp=1;
		rep(i,0,deg)ad(ans,tmp*a[i]%mo),tmp=tmp*x%mo;
		return ans;
	}
};
Polynomial operator+(const Polynomial&a,const Polynomial&b){
	Polynomial c(max(a.deg,b.deg));
	rep(i,0,c.deg)c.a[i]=a.a[i]+b.a[i],ck(c.a[i]);
	return c;
}
Polynomial operator-(const Polynomial&a,const Polynomial&b){
	Polynomial c(max(a.deg,b.deg));
	rep(i,0,c.deg)c.a[i]=a.a[i]-b.a[i],ck(c.a[i]);
	return c;
}
Polynomial operator*(const int&a,const Polynomial&b){
	Polynomial c(b.deg);
	rep(i,0,c.deg)c.a[i]=a*b.a[i]%mo,ck(c.a[i]);
	return c;
}
struct Interval{
	Polynomial val,sum;
	int start,end;
	void clear(){start=end=0;val.clear();sum.clear();}
	void countsum(){
	}
};
struct Function{
	int tot;
	Interval l[maxl];
	void clear(){tot=0;rep(i,0,maxl-1)l[i].clear();}
}a,b,tmp;
Function merge(const Function&a,int l,int r){
	tmp.clear();
	rep(i,1,a.tot){
	}
	return tmp;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int k;scanf("%d",&k);
		rep(i,1,k){
			int l,r;scanf("%d%d",&l,&r);
			a=merge(a,l,r);
		}
		scanf("%d",&k);
		rep(i,1,k){
			int l,r;scanf("%d%d",&l,&r);
			b=merge(b,l,r);
		}

	}
	return 0;
}
