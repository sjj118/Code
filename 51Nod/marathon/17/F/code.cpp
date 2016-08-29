#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxk=9,mo=1e9+7,maxl=1e4;
inline void ck(LL&x){if(x<0)x+=mo;if(x>=mo)x-=mo;}
inline void ad(LL&x,LL y){x+=y;ck(x);}
struct Polynomial{
	int deg;
	LL a[maxk];
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
	int l,r;
	void clear(){start=end=0;val.clear();sum.clear();}
	void countsum(){
	}
};
struct Function{
	int tot;
	Interval l[maxl];
	void clear(){tot=0;rep(i,0,maxl-1)l[i].clear();}
}a,b,tmp;
LL B[maxk],fact[maxk],inv[maxk],_fact[maxk];
inline LL C(int n,int m){if(m>n)return 0;return fact[n]*_fact[m]%mo*_fact[n-m]%mo;}
inline LL S(LL n,int k){
	++n;LL ans=0,tmp=n;per(i,k,0)ad(ans,C(k+1,i)*B[i]%mo*tmp%mo),tmp=tmp*n%mo;
	return ans;
}
Function merge(const Function&a,int l,int r){
	tmp.clear();
	rep(i,1,a.tot){
		if(r-l>=a.l[i].r-a.l[i].l){
			++tmp.tot;
			tmp.l[tmp.tot].l=l+a.l[i].l;tmp.l[tmp.tot].r=l+a.l[i].r-1;tmp.l[tmp.tot].val=a.l[i].sum
		}else{
		}
	}
	return tmp;
}
int main(){
	inv[1]=1;rep(i,2,maxk-1)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i]);
	fact[0]=1;rep(i,1,maxk-1)fact[i]=fact[i-1]*i%mo;
	_fact[0]=1;rep(i,1,maxk-1)_fact[i]=_fact[i-1]*inv[i]%mo;
	B[0]=1;rep(i,1,maxk-2){rep(j,0,i-1)ad(B[i],-C(i+1,j)*B[j]%mo);B[i]=B[i]*inv[i+1]%mo;}
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
