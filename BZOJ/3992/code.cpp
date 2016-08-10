#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int mo=1004535809,maxm=8000+10;
typedef long long LL;
using namespace std;

int n,m,x,S,s[maxm];
LL fact[maxm];
LL power(LL x,LL y,LL p){
	LL a=1;y%=p-1;
	while(y){
		if(y&1)a=a*x%p;
		x=x*x%p;
		y>>=1;
	}
	return a;
}
LL inv(LL n,LL mo){
	return power(n,mo-2,mo);
}
int prime[10],tot;
void get_factor(int p){
	for(int i=2;i*i<=p;++i)if(p%i==0){
		prime[++tot]=i;
		while(p%i==0)p/=i;
	}
	if(p>1)prime[++tot]=p;
}
int g,pow[maxm],ind[maxm];
bool checkg(int x){
	if(power(x,m-1,m)!=1)return 0;
	rep(i,1,tot)if(power(x,(m-1)/prime[i],m)==1)return 0;
	return 1;
}
void getg(){
	rep(i,2,m)if(checkg(i)){g=i;return;}
}
int fn,fm,L,R[maxm<<3];
LL f[maxm<<3],ans[maxm<<3];
void fft(LL*a,int f,int n){
	rep(i,0,n-1)if(R[i]<i)swap(a[i],a[R[i]]);
	for(int i=1;i<n;i<<=1){
		LL wn=power(3,(mo-1)/(i<<1),mo);
		if(f==-1)wn=power(wn,mo-2,mo);
		for(int j=0;j<n;j+=(i<<1)){
			LL w=1;
			for(int k=0;k<i;++k,w=w*wn%mo){
				LL x=a[j+k],y=w*a[j+k+i]%mo;
				a[j+k]=(x+y)%mo;a[j+k+i]=(x-y+mo)%mo;
			}
		}
	}
	LL tmp=inv(n,mo);
	if(f==-1)rep(i,0,n-1)a[i]=a[i]*tmp%mo;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&x,&S);
	rep(i,1,S)scanf("%d",&s[i]);
	bool flag=0;
	rep(i,1,S)if(s[i]==0)flag=1,s[i]=s[S--];
	if(x==0){
		if(flag)printf("%lld\n",power(n-1,S,mo));
		else puts("0");
		return 0;
	}
	get_factor(m-1);
	getg();pow[0]=1;
	rep(i,1,m-1)pow[i]=pow[i-1]*g%m;
	rep(i,0,m-2)ind[pow[i]]=i;--m;
	rep(i,1,S)f[ind[s[i]]]=1;x=ind[x];fm=m<<1;
	for(fn=1;fn<=fm;fn<<=1)++L;
	rep(i,0,fn-1)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	ans[0]=1;fft(f,1,fn);
	while(n){
		if(n&1){
			fft(ans,1,fn);
			rep(j,0,fn-1)ans[j]=ans[j]*f[j]%mo;
			fft(ans,-1,fn);
			rep(j,m,fn-1)ans[j%m]=(ans[j%m]+ans[j])%mo,ans[j]=0;
		}
		rep(j,0,fn-1)f[j]=f[j]*f[j]%mo;
		fft(f,-1,fn);
		rep(j,m,fn-1)f[j%m]=(f[j%m]+f[j])%mo,f[j]=0;
		fft(f,1,fn);
		n>>=1;
	}
	printf("%lld\n",ans[x]);
	return 0;
}
