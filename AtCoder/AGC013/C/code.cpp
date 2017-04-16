#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
const int N=4e5+10;
LL n,l,t,x[N],w[N],a[N],b[N],ca,cb,ans[N];
int main(){
	scanf("%lld%lld%lld",&n,&l,&t);
	rep(i,1,n)scanf("%lld%lld",&x[i],&w[i]);
	LL tmp=t/l;
	t%=l;
	rep(i,1,n)if(w[i]==1)a[++ca]=x[i];else b[++cb]=x[i];
	rep(i,1,ca)a[ca+i]=a[i]+l,a[ca*2+i]=a[i]+2*l;
	rep(i,1,cb)b[cb+i]=b[i]+l,b[cb*2+i]=b[i]+2*l;
	rep(i,1,n){
		if(w[i]==1){
			ans[(i+(LL)2*tmp*cb%n+std::upper_bound(b+1,b+1+cb*3,x[i]+2*t)-std::lower_bound(b+1,b+1+cb*3,x[i])-1)%n+1]=(x[i]+t)%l;
		}else{
			ans[(i+n-(LL)2*tmp*ca%n+n+std::lower_bound(a+1,a+1+ca*3,x[i]+2*l-2*t)-std::upper_bound(a+1,a+1+ca*3,x[i]+2*l)-1)%n+1]=(x[i]-t+l)%l;
		}
	}
	rep(i,1,n)printf("%lld\n",ans[i]);
	return 0;
}
