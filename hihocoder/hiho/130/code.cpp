#include<iostream>
#include<cstdio>
#include<cstring>
#include<assert.h>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e6+10,mo=1e9+7,alp=10,P=N<<1;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n,s[N];
LL ans,sum1[N],sum2[N],pw10[N],_pw10[N];
struct SAM{
	int tot,last,son[P][alp],pr[P],step[P],right[P];
	void ins(int c,int p){
		int k=++tot;step[k]=step[last]+1;right[k]=p;
		while(last&&!son[last][c])son[last][c]=k,last=pr[last];
		if(last){
			int q=son[last][c];
			if(step[q]==step[last]+1)pr[k]=q;
			else{
				int nq=++tot;
				step[nq]=step[last]+1;
				right[nq]=right[q];
				memcpy(son[nq],son[q],sizeof(son[q]));
				pr[nq]=pr[q];
				pr[q]=pr[k]=nq;
				while(last&&son[last][c]==q)son[last][c]=nq,last=pr[last];
			}
		}else pr[k]=1;
		last=k;
	}
	void build(int*s,int n,int p){
		last=1;
		rep(i,1,n)ins(s[i],p+i);
	}
	int calc1(int a,int b){
		return (LL)(sum1[b]-sum1[a-1])*_pw10[n-b]%mo;
	}
	int calc2(int a,int b){
		return (LL)(sum2[b]-sum2[a-1])*_pw10[n-b]%mo;
	}
	int calc3(int a,int b){
		return (calc2(a,b)-(LL)calc1(a,b)*(a-1)%mo)%mo;
	}
	int count(int n){
		rep(i,1,n)sum1[i]=(sum1[i-1]+(LL)pw10[n-i]*s[i])%mo;
		rep(i,1,n)sum2[i]=(sum2[i-1]+(LL)pw10[n-i]*s[i]%mo*i)%mo;
		LL ret=0;
		rep(i,2,tot){
			(ret+=(calc3(right[i]-step[i]+1,right[i])-calc3(right[i]-step[pr[i]]+1,right[i]))%mo)%=mo;
		}
		return ret;
	}
	void clear(){rep(i,1,tot)cls(son[i]);tot=1;}
}sam;
LL power(LL x,LL y,LL p){LL a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
const int _10=power(10,mo-2,mo);
int main(){
	int T;scanf("%d",&T);
	pw10[0]=1;rep(i,1,N-1)pw10[i]=(LL)pw10[i-1]*10%mo;
	_pw10[0]=1;rep(i,1,N-1)_pw10[i]=(LL)_pw10[i-1]*_10%mo;
	sam.clear();
	while(T--){
		char c=gc();int lastn=n;
		while(vaild(c))s[++n]=c-'0',c=getchar();
		sam.build(s+lastn,n-lastn,lastn);
	}
	ans=sam.count(n);
	if(ans<0)ans+=mo;
	printf("%lld",ans);
	return 0;
}
