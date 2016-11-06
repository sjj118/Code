#include<iostream>
#include<cstdio>
#include<cmath>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=5e5+10,inf=1e9;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,a[N],left[N],sta[N],top;
double fa[N],fb[N];
inline bool better(int m,int k,int p){
	return sqrt(m-k)+a[k]>sqrt(m-p)+a[p];
}
int find(int k,int p,int r){
	int l=k;
	while(l<r){
		int m=(l+r)>>1;
		if(better(m,k,p))r=m;else l=m+1;
	}
	return l;
}
void calc(double*f){
	left[0]=0;sta[top=0]=0;a[0]=-inf;
	rep(i,1,n){
		int last=n+1;
		while(top&&better(left[sta[top]],i,sta[top]))last=left[sta[top]]-1;
		left[i]=find(i,sta[top],last);if(left[i]<=n)sta[++top]=i;
	}
	per(i,n,1){
		if(i<left[sta[top]])--top;
		f[i]=a[sta[top]]+sqrt(i-sta[top])-a[i];
	}
}
int main(){
	n=read();
	rep(i,1,n)a[i]=read();
	calc(fa);
	rep(i,1,n>>1)swap(a[i],a[n-i+1]);
	calc(fb);
	rep(i,1,n)printf("%d\n",int(ceil(max(fa[i],fb[n-i+1]))));
	return 0;
}
}
int main(){
//	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
