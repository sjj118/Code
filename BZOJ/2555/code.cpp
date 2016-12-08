#include<iostream>
#include<cstdio>
#include<cstring>
#define ls son[k][0]
#define rs son[k][1]
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=6e5+10,L=3e6+10,P=N*2,alp=26;
inline bool vaild(char c){return c>='A'&&c<='Z';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int q,n,s[N],t[L],mask;
void decode(int*s,int mask,int n){
	rep(i,0,n-1){
		mask=(mask*131+i)%n;
		swap(s[i],s[mask]);
	}
}
struct LCT{
	int son[P][2],pa[P],val[P],rev[P],add[P];
	inline int ws(int k){return son[pa[k]][1]==k;}
	inline bool canrot(int k){return son[pa[k]][ws(k)]==k;}
	inline void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	inline void update(int k){}
	inline void modify_rev(int k){
		rev[k]^=1;swap(ls,rs);
	}
	inline void modify_add(int k,int v){
		add[k]+=v;val[k]+=v;
	}
	inline void maintain(int k){
		if(rev[k])rev[k]=0,modify_rev(ls),modify_rev(rs);
		if(add[k])modify_add(ls,add[k]),modify_add(rs,add[k]),add[k]=0;
	}
	inline void rot(int k){
		int f=pa[k],gf=pa[f],w=ws(k);
		if(canrot(f))set(k,gf,ws(f));else pa[k]=gf;
		set(son[k][!w],f,w);set(f,k,!w);
		update(f);
	}
	inline void preview(int k){
		if(canrot(k))preview(pa[k]);
		maintain(k);
	}
	inline void splay(int k){
		preview(k);
		while(canrot(k)){
			if(canrot(pa[k])&&ws(k)==ws(pa[k]))rot(pa[k]);rot(k);
		}
		update(k);
	}
	inline int access(int k){
		int v=0;
		while(k){
			splay(k);
			rs=v;
			update(v=k);
			k=pa[k];
		}
		return v;
	}
	inline int findroot(int k){
		for(k=access(k);ls;k=ls);
		return k;
	}
	inline void makeroot(int k){
		modify_rev(access(k));
	}
	inline void cut(int a,int b){
		makeroot(a);access(b);splay(a);
		son[a][1]=0;update(a);pa[b]=0;
	}
	inline void link(int a,int b){
		makeroot(a);splay(a);
		pa[a]=b;
	}
	inline void pathadd(int k,int v){
		makeroot(1);access(k);splay(k);
		modify_add(k,v);
	}
	inline int getval(int k){
		preview(k);
		return val[k];
	}
}T;
struct SAM{
	int tot,last,son[P][alp],len[P],pr[P];
	SAM(){tot=last=1;}
	void ins(int c,int l){
		int k=++tot;len[k]=l;
		while(last&&!son[last][c])son[last][c]=k,last=pr[last];
		if(last){
			int q=son[last][c];
			if(len[q]==len[last]+1)T.link(k,q),pr[k]=q;
			else{
				int nq=++tot;
				len[nq]=len[last]+1;
				memcpy(son[nq],son[q],sizeof(son[q]));
				pr[nq]=pr[q];T.link(nq,pr[nq]);T.preview(q);T.val[nq]=T.val[q];
				T.cut(q,pr[q]);pr[q]=pr[k]=nq;T.link(q,nq);T.link(k,nq);
				while(last&&son[last][c]==q)son[last][c]=nq,last=pr[last];
			}
		}else pr[k]=1,T.link(k,1);
		last=k;
		T.pathadd(k,1);
	}
	int go(int*s,int n){
		int k=1;
		rep(i,0,n-1)k=son[k][s[i]];
		return k;
	}
	int count(int*s,int n){
		int k=go(s,n);
		if(k==0)return 0;
		return T.getval(k);
	}
}sam;
int main(){
	scanf("%d",&q);
	char c=gc();
	while(vaild(c))sam.ins(c-'A',++n),c=getchar();
	while(q--){
		char op[10];scanf("\n%s",op);
		int l=0;
		char c=gc();
		while(vaild(c))t[l++]=c-'A',c=getchar();
		decode(t,mask,l);
		if(op[0]=='A'){
			rep(i,0,l-1)sam.ins(t[i],++n);
		}else{
			int ans=sam.count(t,l);
			mask^=ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}
