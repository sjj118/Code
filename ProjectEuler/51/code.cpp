#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int inf=1e9,maxn=1e7,mo=0;
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
///*ÏßÐÔÉ¸
int tot,prime[maxn],miu[maxn],phi[maxn];
bool s[maxn];
void sieve(){
	miu[1]=phi[1]=s[1]=1;
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
int n,a[10],b[maxn],d[maxn];
bool dfs(int k,int x){
	if(k==n+1){
		if(x==-1)return 0;
		int cnt=0;
		if(a[1]==3&&a[2]==1&&a[3]==3&&a[4]==1&&a[5]==2&&a[6]==1&&b[1]==0&&b[2]==1&&b[3]==0&&b[4]==1&&b[5]==0&&b[6]==1){
			cerr<<endl;
		}
		rep(p,b[n],9){
			rep(i,1,n)if(b[i])d[i]=p;else d[i]=a[i];
			int tmp=0;
			per(i,n,1)tmp=tmp*10+d[i];
			if(!s[tmp])++cnt;
		}
		if(cnt==8){
			cerr<<endl;
		}
		return cnt==8;
	}
	if(dfs(k+1,x))return 1;
	if(x==-1||a[k]==x){
		b[k]=1;if(dfs(k+1,a[k]))return 1;;b[k]=0;
	}
	return 0;
}
int main(){
	sieve();
	rep(i,2,maxn-1)if(!s[i]){
		n=0;int x=i;
		while(x)a[++n]=x%10,x/=10;
		if(dfs(1,-1))printf("%d\n",i);
	}
	return 0;
}

