#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#define maxn 300000
#define nlogn 2500000
#define lson son[k][0]
#define rson son[k][1]

using namespace std;

bool isNum(char c){
	return c>='0'&&c<='9';
}
int read(){
	int ans=0;
	char ch=getchar();
	while(!isNum(ch))ch=getchar();
	while(isNum(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans;
}
int n,m,k,dj[maxn],ndj[maxn],nqu[maxn],x[maxn],y[maxn],tot;
struct seq{
	int val[20];
} ques[maxn];
struct lisan{
	seq s;
	int pos;
} li[maxn<<1];
bool operator==(seq a,seq b){
	for(int i=0;i<k;++i)if(a.val[i]!=b.val[i])return 0;
	return 1;
}
bool operator<(seq a,seq b){
	for(int i=0;i<k;++i){
		if(a.val[i]<b.val[i])return 1;
		else if(a.val[i]>b.val[i])return 0;
	}
	return 0;
}
bool comp(lisan a,lisan b){
	return a.s<b.s;
}
struct segtree{
	int cnt,son[nlogn][2],val[nlogn],root[maxn];
	void build(int k,int l,int r){
		if(l==r)return;
		int m=(l+r)>>1;
		build(lson=++cnt,l,m);
		build(rson=++cnt,m+1,r);
	}
	int add(int p,int v,int k,int l,int r){
		int np=++cnt;
		val[np]=val[k];
		if(l==r)val[np]+=v;
		else{
			int m=(l+r)>>1;
			if(p<=m){
				son[np][0]=add(p,v,lson,l,m);
				son[np][1]=rson;
			}else{
				son[np][0]=lson;
				son[np][1]=add(p,v,rson,m+1,r);
			}
		}
		return np;
	}
	int query(int p,int k,int l,int r){
		if(l==r)return val[k];
		int m=(l+r)>>1;
		if(p<=m)return query(p,lson,l,m);
		else return query(p,rson,m+1,r);
	}
	bool ganga(int le,int ri,int chaof){
		return query(chaof,root[ri],1,tot)-query(chaof,root[le-1],1,tot)==0;
	}
} T;

int main(){
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;++i)dj[i]=read();
	for(int i=1;i<=n-k+1;++i)for(int j=0;j<k;++j) li[i].s.val[j]=dj[i+j],li[i].pos=i;
	for(int i=0;i<m;++i){
		x[i]=read();y[i]=read();
		for(int j=0;j<k;++j)ques[i].val[j]=read();
		for(int j=0;j<k;++j) li[n-k+2+i].s.val[j]=ques[i].val[j];
		li[n-k+2+i].pos=n-k+2+i;
	}
	sort(li+1,li+n+m-k+2,comp);
	tot=1;
	for(int i=1;i<=n+m-k+1;++i){
		if(li[i].pos<=n-k+1)ndj[li[i].pos]=tot;
		else nqu[li[i].pos-n+k-2]=tot;
		if(li[i].s<li[i+1].s)++tot;
	}
	T.build(T.root[0]=++T.cnt,1,tot);
	for(int i=1;i<=n;++i){
		T.root[i]=T.add(ndj[i],1,T.root[i-1],1,tot);
	}
	for(int i=0;i<m;++i){
		bool t=T.ganga(x[i],min(y[i],n-k+1),nqu[i]);
		if(t)puts("Yes");else puts("No");
	}
	return 0;
}
