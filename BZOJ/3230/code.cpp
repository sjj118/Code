#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a))
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int N=1e5+10,inf=1e9;
typedef pair<int,int> pii;
inline bool vaild(char c){return c>='a'&&c<='z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n,q;
int a[N],b[N],lg[N];
struct RMinQ{
	int r[N][20];
	void build(int*a,int n){
		rep(i,1,n)r[i][0]=a[i];
		rep(j,1,19){
			rep(i,1,n)if(i+(1<<(j-1))<=n)r[i][j]=min(r[i][j-1],r[i+(1<<(j-1))][j-1]);else r[i][j]=r[i][j-1];
		}
	}
	int rmq(int a,int b){
		if(a>b)return inf;
		int l=lg[b-a+1]-1;
		return min(r[a][l],r[b-(1<<l)+1][l]);
	}
};
struct SA{
	int sa[N],rank[N],hgt[N];
	RMinQ rmq;
	int wa[N],wb[N],c[N];
	bool cmp(int*r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
	void build(int*a,int n,int m){
		int *x=wa,*y=wb;
		cls(c);rep(i,1,n)++c[x[i]=a[i]];
		rep(i,1,m)c[i]+=c[i-1];
		per(i,n,1)sa[c[x[i]]--]=i;
		for(int j=1,p=1;p<n;m=p,j<<=1){
			p=0;rep(i,n-j+1,n)y[++p]=i;
			rep(i,1,n)if(sa[i]>j)y[++p]=sa[i]-j;
			cls(c);rep(i,1,n)++c[x[i]];
			rep(i,1,m)c[i]+=c[i-1];
			per(i,n,1)sa[c[x[y[i]]]--]=y[i];
			swap(x,y);x[sa[1]]=p=1;
			rep(i,2,n)x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p:++p;
		}
		rep(i,1,n)rank[sa[i]]=i;
		for(int i=1,j,k=0;i<=n;hgt[rank[i++]]=k)for(k?--k:k,j=sa[rank[i]-1];a[i+k]==a[j+k];++k);
		rmq.build(hgt,n);
	}
	int lcp(int a,int b){
		a=rank[a];b=rank[b];
		if(a>b)swap(a,b);
		return rmq.rmq(a+1,b);
	}
}sa,sb;
int lcp(int a,int b){return sa.lcp(a,b);}
int lcs(int a,int b){return sb.lcp(n-a+1,n-b+1);}
LL st[N],len[N];
void initpos(){
	len[1]=0,st[1]=1;
	rep(i,2,n+1)len[i]=sa.hgt[i],st[i]=st[i-1]+n-sa.sa[i-1]+1-len[i-1];
}
pii getpos(LL x){
	int p=upper_bound(st+1,st+1+n+1,x)-st-1;
	if(p==n+1)return mp(-1,0);
	x-=st[p]-1;
	return mp(sa.sa[p],x+len[p]);
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n)lg[i]=lg[i>>1]+1;
	rep(i,1,n)a[i]=gc()-'a'+1,b[n-i+1]=a[i];
	sa.build(a,n,27);sb.build(b,n,27);
	initpos();
	while(q--){
		LL x,y;scanf("%lld%lld",&x,&y);
		pii a=getpos(x),b=getpos(y);
		if(b.fi==-1){puts("-1");continue;}
		int p=min(min(a.se,b.se),lcp(a.fi,b.fi)),q=min(min(a.se,b.se),lcs(a.fi+a.se-1,b.fi+b.se-1));
		printf("%lld\n",1ll*p*p+1ll*q*q);
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
