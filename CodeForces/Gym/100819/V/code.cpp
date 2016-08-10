#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=1010;
using namespace std;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int sqr(int x){return x*x;}
int n;
struct Gear{
	int x,y,r;
}a[maxn];
int dis(Gear a,Gear b){return sqr(a.x-b.x)+sqr(a.y-b.y);}
bool met(Gear a,Gear b){return dis(a,b)==sqr(a.r+b.r);}
struct Frac{
	int p,q;
	void update(){int d=gcd(p,q);p/=d,q/=d;}
	Frac(int _p=0,int _q=1){p=_p;q=_q;update();}
	void operator=(const int x){p=x;q=1;}
	void output(){
		if(p*q<0)printf("-");
		printf("%d:%d",abs(q),abs(p));
	}
}b[maxn];
Frac operator+(Frac a,Frac b){
	int d=gcd(a.q,b.q);
	a.p*=b.q/d;b.p*=a.q/d;
	a.q*=b.q/d;b.q=a.q;
	return Frac(a.p+b.p,a.q);
}
Frac operator-(Frac a,Frac b){
	int d=gcd(a.q,b.q);
	a.p*=b.q/d;b.p*=a.q/d;
	a.q*=b.q/d;b.q=a.q;
	return Frac(a.p-b.p,a.q);
}
Frac operator/(Frac a,const int b){
	a.q*=b;a.update();
	return a;
}
bool operator<(Frac a,Frac b){
	a.update();b.update();
	Frac t=b-a;return t.p*t.q>0;
}
bool operator==(Frac a,Frac b){
	a.update();b.update();
	return a.p==b.p&&a.q==b.q;
}
int q[maxn],ql,qr;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
	ql=qr=0;q[qr++]=1;b[1].p=b[1].q=1;
	int flag=0;
	while(ql!=qr){
		int k=q[ql++];
		rep(i,1,n)if(met(a[k],a[i])){
			if(b[i].p==0)b[i]=Frac(-b[k].p*a[i].r,b[k].q*a[k].r),q[qr++]=i;
			else if(!(b[i]==Frac(-b[k].p*a[i].r,b[k].q*a[k].r)))flag=1;
		}
	}
	if(flag){printf("The input gear cannot move.");return 0;}
	if(b[n].p==0)printf("The input gear is not connected to the output gear.");
	else b[n].output();
	return 0;
}
