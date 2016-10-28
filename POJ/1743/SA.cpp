#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
const int N=2e4+10;
inline void up(int&x,int y){if(y>x)x=y;}
inline void dn(int&x,int y){if(y<x)x=y;}
int n,a[N];
struct SA{
	int sa[N],rank[N],hgt[N];
	int wa[N],wb[N],c[N];
	bool cmp(int*r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
	void build(int*a){
		int m=180,*x=wa,*y=wb;
		cls(c);rep(i,1,n)++c[x[i]=a[i]];
		rep(i,1,m)c[i]+=c[i-1];
		per(i,n,1)sa[c[a[i]]--]=i;
		for(int p=1,j=1;p<n;j<<=1,m=p){
			p=0;rep(i,n-j+1,n)y[++p]=i;
			rep(i,1,n)if(sa[i]>j)y[++p]=sa[i]-j;
			cls(c);rep(i,1,n)++c[x[i]];
			rep(i,1,m)c[i]+=c[i-1];
			per(i,n,1)sa[c[x[y[i]]]--]=y[i];
			swap(x,y);x[sa[1]]=p=1;
			rep(i,2,n)x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p:++p;
		}
		rep(i,1,n)rank[sa[i]]=i;
		for(int k=0,i=1,j;i<=n;hgt[rank[i++]]=k)
			for(k?--k:k,j=sa[rank[i]-1];a[i+k]==a[j+k];++k);
	}
	bool check(int x){
		for(int l=2,r=1;l<=n;l=r+2,r=l-1){
			if(hgt[l]<x)continue;
			while(hgt[r+1]>=x)++r;
			int minp=n,maxp=1;
			rep(i,l-1,r)up(maxp,sa[i]),dn(minp,sa[i]);
			if(maxp-minp>x)return 1;
		}
		return 0;
	}
	int LT(){
		int l=0,r=n;
		while(l<r){
			int m=(l+r+1)>>1;
			if(check(m))l=m;else r=m-1;
		}
		return l;
	}
}A;
int main(){
	while(scanf("%d",&n)>0&&n){
		rep(i,1,n)scanf("%d",&a[i]);
		rep(i,1,n-1)a[i]=a[i+1]-a[i]+88;--n;
		A.build(a);
		int ans=A.LT()+1;
		if(ans>=5)printf("%d\n",ans);else puts("0");
	}
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("SA.out","w",stdout);
	return sjj118::main();
}
