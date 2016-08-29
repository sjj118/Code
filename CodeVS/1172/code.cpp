#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
const int maxn=1e5;
bool s[maxn];
int tot,prime[maxn],u[maxn],d[maxn],p1,p2,p3,p4,c1[maxn],c2[maxn],c3[maxn],c4[maxn];
void sieve(){
	rep(i,2,maxn-1){
		if(!s[i])prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
void getfact(int p,int*c,int&s){
	rep(i,1,tot){
		c[i]=0;
		while(p%prime[i]==0)p/=prime[i],++c[i];
	}
	s=p;
}
int main(){
	sieve();
	int n;scanf("%d",&n);
	while(n--){
		int a0,a1,b0,b1;scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		if(a0%a1||b1%b0){puts("0");continue;}
		getfact(a0,c1,p1);getfact(a1,c2,p2);
		getfact(b0,c3,p3);getfact(b1,c4,p4);
		int tmp=tot+1;
		c1[tmp]=p1>1;c2[tmp]=p2>1;
		if(p4!=p1)++tmp;
		c3[tmp]=p3>1;c4[tmp]=p4>1;
		rep(i,1,tmp)if(c1[i]>c2[i])u[i]=d[i]=c2[i];else u[i]=1e9,d[i]=c1[i];
		rep(i,1,tmp)if(c3[i]<c4[i])up(d[i],c4[i]),dn(u[i],c4[i]);else dn(u[i],c3[i]);
		int ans=1;
		rep(i,1,tmp)if(u[i]>=d[i])ans*=(u[i]-d[i]+1);else{ans=0;break;}
		printf("%d\n",ans);
	}
	return 0;
}
