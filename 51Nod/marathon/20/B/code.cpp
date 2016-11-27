#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef unsigned int LL;
const int N=1e6+10;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,a[N];
LL s[N],f[N],s0[N],s1[N],s2[N],s3[N],s4[N],ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n)a[i]=read();
	rep(i,1,n)s[i]=s[i-1]+a[i],f[i]=f[i-1]+(LL)2*i*a[i];
	rep(r,1,n){
		ans+=f[r]*s0[a[r]]-s1[a[r]]-s[r]*s2[a[r]]+s3[a[r]]-r*s[r]*s0[a[r]]+r*s4[a[r]];
		++s0[a[r]];
		s1[a[r]]+=f[r-1];
		s2[a[r]]+=r;
		s3[a[r]]+=r*s[r-1];
		s4[a[r]]+=s[r-1];
	}
	cout<<ans;
	return 0;
}
