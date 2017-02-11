#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::map;
using std::sort;
const int N=60000+10,B=1000,alp=23;
inline bool vaild(char c){return c>='a'&&c<='z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n,m,a[N],b[N],now,ans;
int sum[(1<<alp)+10];
struct Query{
	int l,r;
	friend bool operator<(const Query&a,const Query&b){return a.l/B<b.l/B||(a.l/B==b.l/B&&a.r<b.r);}
}q[N];
int c[N];
bool cmp(int a,int b){return q[a]<q[b];}
void rins(int x){
    ++sum[now];
    now^=1<<x;
    ans+=sum[now];
    rep(i,0,alp-1)ans+=sum[now^(1<<i)];
}
void lins(int x){
    ++sum[now];
    now^=1<<x;
    ans+=sum[now];
    rep(i,0,alp-1)ans+=sum[now^(1<<i)];
}
void rdel(int x){
    rep(i,0,alp-1)ans-=sum[now^(1<<i)];
    ans-=sum[now];
    now^=1<<x;
    --sum[now];
}
void ldel(int x){
    rep(i,0,alp-1)ans-=sum[now^(1<<i)];
    ans-=sum[now];
    now^=1<<x;
    --sum[now];
}
bool comp(int*a,int*b){return *a<*b;}
struct Lisan{
	int tot,*val[N],ml;
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,comp);
		for(int i=1,lst=-1;i<=tot;++i){
			if(*val[i]>lst)lst=*val[i],++ml;
			*val[i]=ml-1;
		}
	}
}li;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)a[i]=gc()-'a',li.ins(a[i]);
	li.work();
	rep(i,1,m)scanf("%d%d",&q[i].l,&q[i].r);
	rep(i,1,m)b[i]=i;
	sort(b+1,b+1+m,cmp);
	int l=1,r=0;
	rep(i,1,m){
		while(r<q[b[i]].r)rins(a[++r]);
		while(l>q[b[i]].l)lins(a[--l]);
		while(r>q[b[i]].r)rdel(a[r--]);
		while(l<q[b[i]].l)ldel(a[l++]);
		c[b[i]]=ans;
	}
	rep(i,1,m)printf("%d\n",c[i]);
	return 0;
}
