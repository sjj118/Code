#include<iostream>
#include<cstdio>
#include<cstring>
#define mo 51061
#define maxn 100010
#define lson son[k][0]
#define rson son[k][1]
#define ws(k) (son[pa[k]][1]==k)
#define canrot(k) (pa[k]&&(son[pa[k]][0]==k||son[pa[k]][1]==k))
#define buffersize 20*1024*1024
#define LL long long

using namespace std;

char buffer[buffersize],*now=buffer;
inline int readInt(){
	int x=0;
	while(*now<'0'||*now>'9')++now;
	for(;*now>='0'&&*now<='9';++now)x=x*10+*now-'0';
	return x;
}
inline char readChar(){
	for(;*now!='+'&&*now!='-'&&*now!='*'&&*now!='/';++now);
	return *now++;
}
int n,q;
struct LCT{
	int pa[maxn],son[maxn][2],rev[maxn];
	int val[maxn],sum[maxn],add[maxn],mul[maxn],size[maxn];
	void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	void molify_mul(int k,LL c){
		mul[k]=mul[k]*c%mo;
		add[k]=add[k]*c%mo;
		val[k]=val[k]*c%mo;
		sum[k]=sum[k]*c%mo;
	}
	void molify_add(int k,int c){
		add[k]=(add[k]+c)%mo;
		val[k]=(val[k]+c%mo);
		sum[k]=(sum[k]+(LL)(c)*size[k])%mo;
	}
	void molify_rev(int k,int c){
		rev[k]^=c;
		if(c)swap(lson,rson);
	}
	void pushdown(int k){
		if(rev[k]){molify_rev(lson,rev[k]);molify_rev(rson,rev[k]);rev[k]=0;}
		if(mul[k]!=1){molify_mul(lson,mul[k]);molify_mul(rson,mul[k]);mul[k]=1;}
		if(add[k]){molify_add(lson,add[k]);molify_add(rson,add[k]);add[k]=0;}
	}
	void pushup(int k){
		sum[0]=0;size[0]=0;
		sum[k]=(val[k]+sum[lson]+sum[rson])%mo;
		size[k]=size[lson]+size[rson]+1;
	}
	void rot(int k){
		int f=pa[k],gf=pa[f],w=ws(k);
		if(canrot(f))set(k,gf,ws(f));else pa[k]=gf;
		set(son[k][!w],f,w);
		set(f,k,!w);
		pushup(f);
	}
	int stack[maxn],top;
	void splay(int k){
		int t=stack[top++]=k;
		while(canrot(t))t=pa[t],stack[top++]=t;
		while(top)pushdown(stack[--top]);
		while(canrot(k)){
			if(canrot(pa[k])&&ws(k)==ws(pa[k]))rot(pa[k]);rot(k);
		}
		pushup(k);
	}
	int access(int k){
		int v=0;
		while(k){
			splay(k);
			rson=v;
			pushup(v=k);
			k=pa[k];
		}
		return v;
	}
	void makeroot(int k){
		molify_rev(access(k),1);
		splay(k);
	}
	int getroot(int k){
		for(k=access(k);pushdown(k),lson;k=lson);
		return k;
	}
	void link(int x,int y){
		makeroot(x);
		pa[x]=y;
	}
	void cut(int x,int y){
		makeroot(x);
		access(y);
		splay(y);
		pa[son[y][0]]=0;
		son[y][0]=0;
		pushup(y);
	}
	int select(int x,int y){
		makeroot(x);
		access(y);
		splay(y);
		return y;
	}
	void Add(int x,int y,int c){
		int k=select(x,y);
		molify_add(k,c);
	}
	void Mul(int x,int y,int c){
		int k=select(x,y);
		molify_mul(k,c);
	}
	LCT(){
		for(int i=0;i<maxn;++i)sum[i]=val[i]=mul[i]=size[i]=1;
	}
}T;

int main(){
	fread(buffer,sizeof(char),buffersize,stdin);
	n=readInt();q=readInt();
	for(int i=1;i<n;++i){
		int u=readInt(),v=readInt();
		T.link(u,v);
	}
	for(int i=1;i<=q;++i){
		char op=readChar();
		if(op=='+'){
			int u=readInt(),v=readInt(),c=readInt();
			T.Add(u,v,c);
		}else if(op=='-'){
			int u1=readInt(),v1=readInt(),u2=readInt(),v2=readInt();
			T.cut(u1,v1);T.link(u2,v2);
		}else if(op=='*'){
			int u=readInt(),v=readInt(),c=readInt();
			T.Mul(u,v,c);
		}else{
			int u=readInt(),v=readInt();
			printf("%d\n",T.sum[T.select(u,v)]);
		}
	}
	return 0;
}
