#include<iostream>
#include<cstdio>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,P=N<<1,alp=26;
inline bool vaild(char c){return c>='a'&&c<='z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline void dn(int&x,int y){if(y<x)x=y;}
int cas,s[N],t[N<<1],n;
struct SAM{
	int tot,step[P],son[P][alp],pr[P],mark[P],num[P];
	SAM(){tot=1;}
	int ins(int c,int p){
		int k=++tot;step[k]=step[p]+1;num[k]=1;
		while(p&&son[p][c]==0)son[p][c]=k,p=pr[p];
		if(p){
			int q=son[p][c];
			if(step[q]==step[p]+1)pr[k]=q;
			else{
				int nq=++tot;step[nq]=step[p]+1;
				memcpy(son[nq],son[q],sizeof(son[q]));
				pr[nq]=pr[q];pr[q]=pr[k]=nq;
				while(p&&son[p][c]==q)son[p][c]=nq,p=pr[p];
			}
		}else pr[k]=1;
		return k;
	}
	int q[P],c[P];
	void build(int*a,int n){
		int lst=1;
		rep(i,1,n)lst=ins(a[i],lst);
		rep(i,1,tot)++c[step[i]];
		rep(i,1,n)c[i]+=c[i-1];
		per(i,tot,1)q[c[step[i]]--]=i;
		per(i,tot,1)num[pr[q[i]]]+=num[q[i]];
	}
	int solve(int*a,int n){
		int k=1,l=0,ret=0;
		rep(i,1,n+n-1){
			++l;
			while(k>1&&son[k][a[i]]==0)k=pr[k];
			dn(l,step[k]+1);
			if(son[k][a[i]])k=son[k][a[i]];
			while(step[pr[k]]>=n)k=pr[k];
			dn(l,step[k]);
			if(l>=n){
				if(mark[k]!=cas)mark[k]=cas,ret+=num[k];
			}
		}
		return ret;
	}
}sam;
int main(){
	char c=gc();
	while(vaild(c))s[++n]=c-'a',c=getchar();
	sam.build(s,n);
	int T;scanf("%d",&T);
	for(cas=1;cas<=T;++cas){
		int m=0;
		c=gc();
		while(vaild(c))t[++m]=c-'a',c=getchar();
		rep(i,1,m-1)t[m+i]=t[i];
		printf("%d\n",sam.solve(t,m));
	}
	return 0;
}
