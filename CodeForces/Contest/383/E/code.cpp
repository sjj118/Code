#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<assert.h>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10,inf=1e9,B=320;
inline void dn(int&x,int y){if(y<x)x=y;}
char s[N],t[N];
int q,n,m,lg[N];
struct RMinQ{
	int r[N][20];
	void build(int*a,int n){
		rep(i,0,n)r[i][0]=a[i];
		rep(i,1,19){
			int x=1<<(i-1);
			rep(j,0,n){
				if(j+x<=n)r[j][i]=min(r[j][i-1],r[j+x][i-1]);
				else r[j][i]=r[j][i-1];
			}
		}
	}
	int rmq(int a,int b){
		if(a>b)return inf;
		int x=lg[b-a+1]-1;
		return min(r[a][x],r[b-(1<<x)+1][x]);
	}
}st;
struct SA{
	int a[N],sa[N],rank[N],hgt[N];
	int wa[N],wb[N],c[N];
	RMinQ rmq;
	inline bool cmp(int*r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
	void build(int n,int m){
		int*x=wa,*y=wb;
		cls(c);rep(i,1,n)++c[x[i]=a[i]];
		rep(i,1,m)c[i]+=c[i-1];
		per(i,n,1)sa[c[x[i]]--]=i;
		for(int j=1,p=1;p<n;j<<=1,m=p){
			p=0;rep(i,n-j+1,n)y[++p]=i;
			rep(i,1,n)if(sa[i]>j)y[++p]=sa[i]-j;
			cls(c);rep(i,1,n)++c[x[i]];
			rep(i,1,m)c[i]+=c[i-1];
			per(i,n,1)sa[c[x[y[i]]]--]=y[i];
			swap(x,y);x[sa[1]]=p=1;
			rep(i,2,n)x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p:++p;
		}
		rep(i,1,n)rank[sa[i]]=i;
		for(int i=1,j,k=0;i<=n;hgt[rank[i++]]=k)
			for(k?--k:k,j=sa[rank[i]-1];a[i+k]==a[j+k];++k);
		rmq.build(hgt,n);
	}
	int lcp(int a,int b){
		a=rank[a];b=rank[b];
		if(a>b)swap(a,b);
		return rmq.rmq(a+1,b);
	}
	int comp(int x,int y,int l){
		int t=lcp(x,y);
		if(t>=l)return 0;
		return a[x+t]<a[y+t]?1:-1;
	}
}sa;
int compare(int a,int b){
	int f=1;
	if(a>b)swap(a,b),f=-1;
	if(b-a<=m){
		int t=sa.comp(n+2,a+1,b-a);
		if(t)return f*t;
		t=sa.comp(n+2+b-a,n+2,m-(b-a));
		if(t)return f*t;
		t=sa.comp(a+1,n+2+m-(b-a),b-a);
		if(t)return f*t;
		return 0;
	}else{
		int t=sa.comp(n+2,a+1,m);
		if(t)return f*t;
		t=sa.comp(a+1,a+1+m,b-a-m);
		if(t)return f*t;
		t=sa.comp(b+1-m,n+2,m);
		if(t)return f*t;
		return 0;
	}
}
bool cmp(int a,int b){
	int t=compare(a,b);
	if(!t)return a<b;
	return t>0;
}
int a[N],b[N],tst[N],tot;
struct Query{
	int l,r,k,x,y,id,ans;
	Query(){ans=inf;}
}Q[N];
bool operator<(const Query&a,const Query&b){return a.k<b.k;}
int main(){
	rep(i,1,N-1)lg[i]=lg[i>>1]+1;
	scanf("%s %s %d",s+1,t+1,&q);
	n=strlen(s+1);m=strlen(t+1);
	rep(i,1,n)sa.a[i]=s[i]-'a'+1;
	sa.a[n+1]=30;rep(i,1,m)sa.a[n+1+i]=t[i]-'a'+1;
	sa.build(n+m+1,30);
	rep(i,0,n)a[i]=i;
	sort(a,a+1+n,cmp);
	rep(i,0,n)b[a[i]]=i;
	rep(i,1,q)scanf("%d%d%d%d%d",&Q[i].l,&Q[i].r,&Q[i].k,&Q[i].x,&Q[i].y),Q[i].id=i;
	sort(Q+1,Q+1+q);
	Q[q+1].k=inf;
	int l=1,r=0;
	rep(k,1,B-1){
		while(Q[l].k<k)++l;
		while(Q[r+1].k<=k)++r;
		rep(i,0,k-1){
			int tot=0;
			for(int j=0;j*k+i<=n;++j)tst[++tot]=b[j*k+i];
			st.build(tst,tot);
			rep(j,l,r)if(i>=Q[j].x&&i<=Q[j].y)dn(Q[j].ans,st.rmq((Q[j].l-i+k-1)/k+1,(Q[j].r-i+k)/k));
		}
	}
	st.build(b,n);
	rep(i,r+1,q){
		for(int j=0;j*Q[i].k<=n;++j)dn(Q[i].ans,st.rmq(max(Q[i].l,j*Q[i].k+Q[i].x),min(Q[i].r,j*Q[i].k+Q[i].y)));
	}
	rep(i,1,q)tst[Q[i].id]=Q[i].ans;
	rep(i,1,q)printf("%d ",tst[i]==inf?-1:a[tst[i]]);
	return 0;
}
