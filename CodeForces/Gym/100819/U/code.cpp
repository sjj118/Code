#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=110,dx[9]={-1,-1,-1,0,0,0,1,1,1},dy[9]={-1,0,1,-1,0,1,-1,0,1};
using namespace std;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
int w,h,t;
struct Frac{
	int p,q;
	void update(){int d=gcd(p,q);p/=d,q/=d;}
	Frac(int _p=0,int _q=1){p=_p;q=_q;update();}
	void operator=(const int x){p=x;q=1;}
}a[maxn][maxn],b[maxn][maxn],all[maxn*maxn];
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
void blur(){
	rep(i,1,w)a[0][i]=a[h][i],a[h+1][i]=a[1][i];
	rep(i,1,h)a[i][0]=a[i][w],a[i][w+1]=a[i][1];
	a[0][0]=a[h][w];a[h+1][w+1]=a[1][1];a[h+1][0]=a[1][w];a[0][w+1]=a[h][1];
	rep(i,1,h)rep(j,1,w){
		Frac tmp=0;
		rep(k,0,8)tmp=tmp+a[i+dx[k]][j+dy[k]];
		b[i][j]=tmp/9;
	}
	rep(i,1,h)rep(j,1,w)a[i][j]=b[i][j];
}
int main(){
	scanf("%d%d%d",&w,&h,&t);
	rep(i,1,h)rep(j,1,w){int x;scanf("%d",&x);a[i][j]=x;}
	rep(i,1,t)blur();
	rep(i,1,h)rep(j,1,w)all[(i-1)*w+j]=a[i][j];
	sort(all+1,all+1+h*w);
	int ans=1;
	rep(i,2,h*w)if(all[i-1]<all[i])++ans;
	printf("%d",ans);
	return 0;
}
