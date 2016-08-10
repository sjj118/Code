#include<iostream>
#include<cstdio>
#define maxp 20000010
#define lson son[k][0]
#define rson son[k][1]
#define LL long long

using namespace std;

int readint(){
	int f=1,tmp=0;char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp*f;
}
int n,m;
struct SegmentTree{
	int tot,root[400000],son[maxp][2];
	SegmentTree(){tot=1;}
	struct Node{
		LL sum:36,add:36;
	}mark[maxp];
	void molify_add(int k,int l,int r,LL c){
		mark[k].add+=c;
		mark[k].sum+=c*(r-l+1);
	}
	void pushdown(int k,int l,int r){
		if(mark[k].add&&l<r){
			int m=(l+r)>>1;
			if(!lson)lson=++tot;
			if(!rson)rson=++tot;
			molify_add(lson,l,m,mark[k].add);
			molify_add(rson,m+1,r,mark[k].add);
			mark[k].add=0;
		}
	}
	void pushup(int k,int l,int r){
		mark[k].sum=mark[lson].sum+mark[rson].sum+mark[k].add*(r-l+1);
	}
	LL query1(int a,int b,int&k,int l,int r){
		if(!k)return 0;
//		pushdown(k,l,r);
		if(a<=l&&r<=b)return mark[k].sum;
		else{
			int m=(l+r)>>1;
			LL ans=mark[k].add*(min(b,r)-max(a,l)+1);
			if(a<=m)ans+=query1(a,b,lson,l,m);
			if(b>m)ans+=query1(a,b,rson,m+1,r);
			return ans;
		}
	}
	int query2(int a,int b,LL p){
		int k=1,l=-n,r=n;
		while(l<r){
			int m=(l+r)>>1;
			LL val=query1(a,b,root[k<<1],1,n);
			if(val<p)p-=val,k=k<<1|1,l=m+1;
			else k=k<<1,r=m;
		}
		return l;
	}
	void molify1(int a,int b,int&k,int l,int r){
		if(!k)k=++tot;
		if(a<=l&&r<=b)molify_add(k,l,r,1);
		else{
			int m=(l+r)>>1;
			if(b>m)molify1(a,b,rson,m+1,r);
			if(a<=m)molify1(a,b,lson,l,m);
		}
		pushup(k,l,r);
	}
	void molify2(int a,int b,int c){
		int k=1,l=-n,r=n;
		while(l<r){
			molify1(a,b,root[k],1,n);
			int m=(l+r)>>1;
			if(c<=m)k=k<<1,r=m;
			else k=k<<1|1,l=m+1;
		}
		molify1(a,b,root[k],1,n);
	}
}T;

int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	n=readint();m=readint();
	for(int i=1;i<=m;++i){
		int op=readint(),a=readint(),b=readint(),c=readint();
		if(op==1)T.molify2(a,b,-c);
		else printf("%d\n",-T.query2(a,b,c));
	}
	return 0;
}
