#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int inf=1e9+1,maxn=1e6+10,mo=0,maxv=1e7+10;
const double eps=1e-8;
using namespace std;
inline char gc(){char c=getchar();while(!(c=='-'||c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0,f=1;char c=gc();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp*f;}
inline LL ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;return x;}
inline LL ad(LL&x,LL y,LL p){return ck(x+=y,p);}
inline void up(LL&x,LL y){if(y>x)x=y;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
inline LL gcd(LL a,LL b){if(!b)return a;return gcd(b,a%b);}
inline LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
inline LL sqr(LL x){return x*x;}
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;x=x*x%p,y>>=1)if(y&1)a=a*x%p;return a;}
inline LL exgcd(LL a,LL b,LL&x,LL&y){if(!b)return x=1,y=0,a;LL d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
inline LL inv(LL n,LL p){LL x,y;if(exgcd(n,p,x,y)>1)cerr<<"NO_REV"<<endl;return ck(x,p);}
/*ÏßÐÔÉ¸
int tot,prime[maxn],miu[maxn],phi[maxn];
bool s[maxn];
void sieve(){
	miu[1]=phi[1]=1;
	rep(i,2,maxn-1){
		if(!s[i])prime[++tot]=i,miu[i]=-1,phi[i]=i-1;
		for(int j=1;j<=tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				miu[i*prime[j]]=-miu[i];
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}else{
				miu[i*prime[j]]=0;
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
		}
	}
}
//*/
int n,m;
struct Interval{
	int l,r;
}a[maxn];
bool operator<(Interval a,Interval b){return a.r-a.l<b.r-b.l;}
bool comp(int*a,int*b){return *a<*b;}
struct Lisan{
	int tot,*val[maxv],maxval,real[maxv];
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,comp);
		for(int i=1,last=-1;i<=tot;++i){
			if(*val[i]>last)last=real[++maxval]=*val[i];
			*val[i]=maxval;
		}
	}
}lisan;
struct SGT{
	int val[maxv],maxx[maxv];
	void modify(int ll,int rr,int v,int k,int l,int r){
		if(ll<=l&&r<=rr){val[k]+=v,maxx[k]+=v;return;}
		int m=(l+r)>>1;
		val[k<<1]+=val[k];maxx[k<<1]+=val[k];val[k<<1|1]+=val[k];maxx[k<<1|1]+=val[k];
		val[k]=0;
		if(ll<=m)modify(ll,rr,v,k<<1,l,m);
		if(rr>m)modify(ll,rr,v,k<<1|1,m+1,r);
		maxx[k]=max(maxx[k<<1],maxx[k<<1|1]);
	}
}T;

int main(){
	freopen("interval.in","r",stdin);freopen("interval.out","w",stdout);
	n=read();m=read();
	rep(i,1,n)a[i].l=read(),a[i].r=read();
	sort(a+1,a+1+n);
	rep(i,1,n)lisan.ins(a[i].l),lisan.ins(a[i].r);
	lisan.work();
	int ans=inf;
	for(int l=1,r=0;l<=n;++l){
		while(r<n&&T.maxx[1]<m)
		++r,T.modify(a[r].l,a[r].r,1,1,1,lisan.maxval);
		if(T.maxx[1]==m)ans=min(ans,(lisan.real[a[r].r]-lisan.real[a[r].l])-(lisan.real[a[l].r]-lisan.real[a[l].l]));
		T.modify(a[l].l,a[l].r,-1,1,1,lisan.maxval);
	}
	if(ans==inf)printf("-1\n");else printf("%d\n",ans);
	return 0;
}

