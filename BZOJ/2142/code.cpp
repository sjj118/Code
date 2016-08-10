#include<iostream>
#include<cstdio>
#include<cmath>
typedef long long LL;
const int maxn=100,maxp=1e5+10;
using namespace std;

LL p,n,m,w[maxn],sum,prime[maxn],cnt[maxn],mod[maxn],a[maxn],fact[maxn][maxp],tot;
void get_factor(LL p){
	for(LL i=2;i*i<=p;++i)if(p%i==0){
		prime[++tot]=i;mod[tot]=1;
		while(p%i==0)p/=i,++cnt[tot],mod[tot]*=i;
		fact[tot][0]=1;for(int j=1;j<=mod[tot];++j){
			fact[tot][j]=fact[tot][j-1];
			if(j%prime[tot])fact[tot][j]=fact[tot][j]*j%mod[tot];
		}
	}
	if(p>1){
		prime[++tot]=p,cnt[tot]=1,mod[tot]=p;
		fact[tot][0]=1;for(int j=1;j<=mod[tot];++j){
			fact[tot][j]=fact[tot][j-1];
			if(j%prime[tot])fact[tot][j]=fact[tot][j]*j%mod[tot];
		}
	}
}
LL power(LL base,LL exp,LL mo){
	LL ans=1;
	while(exp){
		if(exp&1)ans=ans*base%mo;
		base=base*base%mo;
		exp>>=1;
	}
	return ans;
}
LL exgcd(LL a,LL b,LL&x,LL&y){
	if(!b)return x=1,y=0,a;
	LL d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
LL rev(LL a,LL p){
	LL x,y;
	if(exgcd(a,p,x,y)!=1)cerr<<"NO_REV"<<endl;
	return (x%p+p)%p;
}
LL CRT(){
	LL ans=0;
	for(int i=1;i<=tot;++i){
		LL m=p/mod[i];
		ans=(ans+m*rev(m,mod[i])%p*a[i]%p)%p;
	}
	return ans;
}
void factor(LL n,int k,LL&t,LL&u){
	if(!n)return;
	t=t*power(fact[k][mod[k]],n/mod[k],mod[k])%mod[k];
	t=t*fact[k][n%mod[k]]%mod[k];
	u+=n/prime[k];
	factor(n/prime[k],k,t,u);
}
LL C(LL n,LL m,int k){
	LL t1=1,u1=0,t2=1,u2=0,t3=1,u3=0;
	factor(n,k,t1,u1);factor(m,k,t2,u2);factor(n-m,k,t3,u3);
	return t1*rev(t2,mod[k])%mod[k]*rev(t3,mod[k])%mod[k]*power(prime[k],u1-u2-u3,mod[k])%mod[k];
}
LL C(LL n,LL m){
	for(int i=1;i<=tot;++i)a[i]=C(n,m,i);
	return CRT();
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%lld%lld%lld",&p,&n,&m);
	for(int i=1;i<=m;++i)scanf("%lld",&w[i]),sum+=w[i];
	if(sum>n)return puts("Impossible"),0;
	get_factor(p);
	LL ans=C(n,sum);
	for(int i=1;i<=m;++i)ans=ans*C(sum,w[i])%p,sum-=w[i];
	printf("%lld",ans);
	return 0;
}
