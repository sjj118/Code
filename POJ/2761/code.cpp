#include<iostream>
#include<cstdio>
#include<algorithm>
#define ls son[k][0]
#define rs son[k][1]
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,M=5e4+10,P=32e5,inf=1e9+7;
inline bool vaild(char c){return c>='0'&&c<='9'||c=='-';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0,f=1;char c=gc();if(c=='-')f=-1,c=getchar();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret*f;}
int n,m;
int root[N];
struct SGT{
	int tot,son[P][2],val[P];
	void update(int k,int l,int r){
		if(l==r)return;
		val[k]=val[ls]+val[rs];
	}
	int modify_val(int p,int v,int k,int l,int r){
		int t=++tot;
		if(l==r){val[t]=val[k]+v;return t;}
		int m=(l+r)>>1;
		if(p<=m)son[t][0]=modify_val(p,v,ls,l,m),son[t][1]=rs;
		else son[t][0]=ls,son[t][1]=modify_val(p,v,rs,m+1,r);
		update(t,l,r);
		return t;
	}
	int query(int p,int k1,int k2,int l,int r){
		if(l==r)return l;
		int t=val[son[k1][0]]-val[son[k2][0]];
		int m=(l+r)>>1;
		if(t>=p)return query(p,son[k1][0],son[k2][0],l,m);
		else return query(p-t,son[k1][1],son[k2][1],m+1,r);
	}
}T;
bool cmp(int*a,int*b){return *a<*b;}
struct Lisan{
	int tot,*val[N],maxval,real[N];
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,cmp);
		for(int i=1,last=-inf;i<=tot;++i){
			if(*val[i]>last)real[++maxval]=*val[i];
			*val[i]=maxval;
		}
	}
}lisan;
int a[N];
int main(){
	n=read();m=read();
	rep(i,1,n)scanf("%d",&a[i]),lisan.ins(a[i]);
	lisan.work();
	rep(i,1,n)root[i]=T.modify_val(a[i],1,root[i-1],1,lisan.maxval);
	rep(i,1,m){
		int a,b,k;scanf("%d%d%d",&a,&b,&k);
		printf("%d\n",lisan.real[T.query(k,root[b],root[a-1],1,lisan.maxval)]);
	}
	return 0;
}
