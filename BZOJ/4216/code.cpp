#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
typedef long long LL;
const int N=500000+10,B=250;
inline LL abs(LL x){return x<0?-x:x;}
inline void swap(int&x,int&y){int t=x;x=y;y=t;}
int n,m,t,a[N],s[N/B+10];
int main(){
	scanf("%d%d%d",&n,&m,&t);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)s[i/B]+=a[i];
	LL ans=0;
	while(m--){
		int l,r;scanf("%d%d",&l,&r);
		if(t)l=(l^abs(ans))%n+1,r=(r^abs(ans))%n+1;
		if(l>r)swap(l,r);
		ans=0;
		if(l/B==r/B){
			rep(i,l,r)ans+=a[i];
		}else{
			int fr=l/B*B+B-1;
			rep(i,l,fr)ans+=a[i];
			rep(i,l/B+1,r/B-1)ans+=s[i];
			rep(i,r/B*B,r)ans+=a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
