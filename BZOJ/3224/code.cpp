#include<iostream>
#include<cstdio>
#include<cstdlib>
#define pii pair<int,int>
#define mp make_pair
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10;
struct Treap{
	int root,tot,ls[maxn],rs[maxn],rnd[maxn],key[maxn],size[maxn];
	int newnode(int v){int k=++tot;rnd[k]=rand();key[k]=v;size[k]=1;return k;}
	void update(int k){size[k]=size[ls[k]]+size[rs[k]]+1;}
	int merge(int a,int b){
		if(!a||!b)return a+b;
		if(rnd[a]<rnd[b])return rs[a]=merge(rs[a],b),update(a),a;
		else return ls[b]=merge(a,ls[b]),update(b),b;
	}
	pii split(int k,int p){
		if(p==0)return mp(0,k);
		int l=ls[k],r=rs[k];
		if(size[ls[k]]==p)return ls[k]=0,update(k),mp(l,k);
		if(size[ls[k]]+1==p)return rs[k]=0,update(k),mp(k,r);
		if(size[ls[k]]>p){
			pii ans=split(ls[k],p);ls[k]=ans.second;
			update(k);return mp(ans.first,k);
		}
		pii ans=split(rs[k],p-size[ls[k]]-1);rs[k]=ans.first;
		update(k);return mp(k,ans.second);
	}
	int rank(int x){
		int k=root,ans=1e9,tmp=0;
		while(k){
			if(key[k]==x)ans=tmp+size[ls[k]]+1;
			if(key[k]>=x)k=ls[k];
			else tmp+=size[ls[k]]+1,k=rs[k];
		}
		return ans==1e9?tmp:ans;
	}
	void insert(int x){
		pii tmp=split(root,rank(x));
		int k=newnode(x);
		root=merge(tmp.first,k);
		root=merge(root,tmp.second);
	}
	void del(int x){
		pii tmp=split(root,rank(x)-1),tmp2=split(tmp.second,1);
		root=merge(tmp.first,tmp2.second);
	}
	int pth(int p){
		int k=root;
		while(k){
			if(size[ls[k]]>=p)k=ls[k];
			else if(size[ls[k]]+1==p)return key[k];
			else p-=size[ls[k]]+1,k=rs[k];
		}
		return key[k];
	}
	int pre(int x){
		int k=root,ans=1e9;
		while(k){
			if(key[k]>=x)k=ls[k];
			else ans=key[k],k=rs[k];
		}
		return ans;
	}
	int suf(int x){
		int k=root,ans=1e9;
		while(k){
			if(key[k]<=x)k=rs[k];
			else ans=key[k],k=ls[k];
		}
		return ans;
	}
}T;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	int n;scanf("%d",&n);
	rep(i,1,n){
		int op,x;scanf("%d%d",&op,&x);
		if(op==1)T.insert(x);
		if(op==2)T.del(x);
		if(op==3)printf("%d\n",T.rank(x));
		if(op==4)printf("%d\n",T.pth(x));
		if(op==5)printf("%d\n",T.pre(x));
		if(op==6)printf("%d\n",T.suf(x));
	}
	return 0;
}
