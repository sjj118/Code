#include<iostream>
#include<cstdio>
const int maxn=20,maxp=1e5;
typedef long long LL;
using namespace std;
 
int n1,n2,a[maxn],tot;
LL prime[maxn],cnt[maxn],mod[maxn],fact[maxn][maxp],val[maxn],p,n,m,ans;
inline void ck(LL&x,LL mo){if(x>=mo)x-=mo;if(x<0)x+=mo;}
inline void ad(LL&x,LL y,LL mo){x=x+y;ck(x,mo);}
LL exgcd(LL a,LL b,LL&x,LL&y){
    if(!b)return x=1,y=0,a;
    LL d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
LL rev(LL n,LL mo){
    LL x,y;
    if(exgcd(n,mo,x,y)>1)return 1;
    return x<0?x+mo:x;
}
void get_factor(LL n){
    for(LL i=2;i*i<=n;++i)if(n%i==0){
        prime[++tot]=i;mod[tot]=1;
        while(n%i==0)n/=i,++cnt[tot],mod[tot]*=i;
        fact[tot][0]=1;for(LL j=1;j<=mod[tot];++j)if(j%prime[tot])fact[tot][j]=fact[tot][j-1]*j%mod[tot];else fact[tot][j]=fact[tot][j-1];
    }
    if(n>1){
		prime[++tot]=n,mod[tot]=n,cnt[tot]=1;
		fact[tot][0]=1;for(LL j=1;j<=mod[tot];++j)if(j%prime[tot])fact[tot][j]=fact[tot][j-1]*j%mod[tot];else fact[tot][j]=fact[tot][j-1];
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
LL CRT(){
    LL ans=0;
    for(int i=1;i<=tot;++i){
        LL M=p/mod[i];
        ad(ans,M*rev(M,mod[i])%p*val[i]%p,p);
    }
    return ans;
}
LL C(LL n,LL m){
    if(m>n)return 0;
    for(int i=1;i<=tot;++i)val[i]=C(n,m,i);
    return CRT();
}
int f=1; 
void dfs(int k){
    if(k==n1+1)return ad(ans,f*C(m-1,n-1),p);
    dfs(k+1);
    f=-f;m-=a[k];
    dfs(k+1);
    f=-f;m+=a[k];
}
 
int main(){
    int T;scanf("%d%lld",&T,&p);get_factor(p);
    while(T--){
        scanf("%lld%d%d%lld",&n,&n1,&n2,&m);ans=0;
        for(int i=1;i<=n1+n2;++i)scanf("%d",&a[i]);
        for(int i=n1+1;i<=n1+n2;++i)m-=a[i]-1;
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
