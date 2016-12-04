#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=3e4+10,alp=27;
inline void dn(int&x,int y){if(y<x)x=y;}
char s[N];
int n,a[N],b[N],lg[N];
LL ans;
struct RMinQ{
	int a[N][15];
	void build(int*r,int n){
		cls(a);
		rep(i,1,n)a[i][0]=r[i];
		for(int j=1,x=1;j<=14;++j,x<<=1){
			rep(i,1,n){
				a[i][j]=a[i][j-1];
				if(i+x<=n)dn(a[i][j],a[i+x][j-1]);
			}
		}
	}
	int rmq(int l,int r){
		int x=lg[r-l+1]-1;
		return min(a[l][x],a[r-(1<<x)+1][x]);
	}
};
struct SA{
	int sa[N],rank[N],hgt[N];
	RMinQ rhgt;
	int wa[N],wb[N],c[N];
	bool cmp(int*r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
	void build(int*a,int n,int m){
		cls(sa);cls(rank);cls(hgt);
		cls(wa);cls(wb);
		int *x=wa,*y=wb;
		cls(c);rep(i,1,n)++c[x[i]=a[i]];
		rep(i,1,m)c[i]+=c[i-1];
		per(i,n,1)sa[c[a[i]]--]=i;
		for(int p=1,j=1;p<n;m=p,j<<=1){
			p=0;rep(i,n-j+1,n)y[++p]=i;
			rep(i,1,n)if(sa[i]>j)y[++p]=sa[i]-j;
			cls(c);rep(i,1,n)++c[x[i]];
			rep(i,1,m)c[i]+=c[i-1];
			per(i,n,1)sa[c[x[y[i]]]--]=y[i];
			swap(x,y);x[sa[1]]=p=1;
			rep(i,2,n)x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p:++p;
		}
		rep(i,1,n)rank[sa[i]]=i;
		for(int k=0,i=1,j;i<=n;hgt[rank[i++]]=k)
			for(k?--k:k,j=sa[rank[i]-1];a[i+k]==a[j+k];++k);
		rhgt.build(hgt,n); 
	}
	int lcp(int a,int b){
		a=rank[a];b=rank[b];
		if(a>b)swap(a,b);
		return rhgt.rmq(a+1,b);
	}
}A,B;
int st[N],ed[N];
int main(){
	rep(i,1,N-1)lg[i]=lg[i>>1]+1;
	int T;scanf("%d",&T);
	while(T--){
		scanf("\n%s",s+1);n=strlen(s+1);
		cls(a);cls(b);
		rep(i,1,n)a[i]=s[i]-'a'+1;
		rep(i,1,n)b[i]=a[n-i+1];
		A.build(a,n,alp);B.build(b,n,alp);
		cls(st);cls(ed);
		rep(L,1,n){
			for(int j=1;j*L+L<=n;++j){
				int l=min(B.lcp(n-j*L+1,n-(j+1)*L+1),L),r=min(A.lcp(j*L+1,(j+1)*L+1),L);
				if(l+r>=L&&l)++st[j*L-l+1],--st[min(j*L,j*L-l+1+l+r-L)+1];
			}
			for(int j=1;j*L<=n;++j){
				int l=min(B.lcp(n-j*L+L+1,n-j*L+1),L),r=min(A.lcp(j*L+1,j*L-L+1),L);
				if(l+r>=L&&r)--ed[j*L+r+1],++ed[max(j*L+1,j*L+r-l-r+L)];
			}
		}
		rep(i,1,n)st[i]+=st[i-1],ed[i]+=ed[i-1];
		ans=0;
		rep(i,1,n-1)ans+=(LL)ed[i]*st[i+1];
		printf("%lld\n",ans);
	}
	return 0;
}
