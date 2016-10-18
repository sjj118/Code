#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=2e5+10,mo=1e9+7;
inline LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
int n,m,fn;
int s[maxn];
LL f[maxn];
int tot,prime[maxn];
void fwt(LL*a,int l,int r){
	if(l==r)return;
	int m=(l+r)>>1;
	fwt(a,l,m);fwt(a,m+1,r);
	rep(i,0,m-l){
		LL x=a[l+i];
		a[l+i]+=a[m+1+i];ck(a[l+i],mo);
		a[m+1+i]=x-a[m+1+i];ck(a[m+1+i],mo);
	}
}
void ufwt(LL*a,int l,int r){
	if(l==r)return;
	int m=(l+r)>>1;
	ufwt(a,l,m);ufwt(a,m+1,r);
	rep(i,0,m-l){
		LL x=a[l+i];
		a[l+i]=(a[l+i]+a[m+1+i])*500000004%mo;
		a[m+1+i]=(x-a[m+1+i])*500000004%mo;ck(a[m+1+i],mo);
	}
}
int main(){
	rep(i,2,maxn-1){
		if(!s[i])prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	while(scanf("%d%d",&n,&m)>0){
		cls(f);
		rep(i,2,m)f[i]=!s[i];
		for(fn=1;fn<=m;fn<<=1);
		fwt(f,0,fn-1);
		rep(i,0,fn-1)f[i]=power(f[i],n,mo);
		ufwt(f,0,fn-1);
		printf("%lld\n",f[0]);
	}
	return 0;
}
