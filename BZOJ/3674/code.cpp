#include<iostream>
#include<cstdio>
#define ls son[k][0]
#define rs son[k][1]
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=2e5+10,maxp=1e7;
struct SGT{
	int tot,son[maxp][2],val[maxp],root[maxn];
	int modify(int p,int v,int k,int l,int r){
		int t=++tot;
		if(l==r){val[t]=v;return t;}
		int m=(l+r)>>1;
		if(p<=m)son[t][0]=modify(p,v,ls,l,m),son[t][1]=rs;
		else son[t][0]=ls,son[t][1]=modify(p,v,rs,m+1,r);
		return t;
	}
	int get(int p,int k,int l,int r){
		if(l==r)return val[k];
		int m=(l+r)>>1;
		if(p<=m)return get(p,ls,l,m);
		else return get(p,rs,m+1,r);
	}
}pa,rank;
int n,m,now,ans;
int PA(int k){return pa.get(k,pa.root[now],1,n);}
int modifyPA(int k,int v){pa.root[now]=pa.modify(k,v,pa.root[now],1,n);return v;}
int RANK(int k){return rank.get(k,rank.root[now],1,n);}
void modifyRANK(int k,int v){rank.root[now]=rank.modify(k,v,rank.root[now],1,n);}
int find(int k){return PA(k)==k?k:modifyPA(k,find(PA(k)));}
void unio(int a,int b){
	a=find(a);b=find(b);
	if(a==b)return;
	if(RANK(a)>RANK(b))swap(a,b);
	modifyPA(a,b);
	if(RANK(a)==RANK(b))modifyRANK(b,RANK(b)+1);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)pa.root[0]=pa.modify(i,i,pa.root[0],1,n);
	rep(i,1,m){
		int op;scanf("%d",&op);
		now=i;pa.root[i]=pa.root[i-1];rank.root[i]=rank.root[i-1];
		if(op==1){
			int a,b;scanf("%d%d",&a,&b);
			a^=ans;b^=ans;
			unio(a,b);
		}else if(op==2){
			int k;scanf("%d",&k);
			k^=ans;
			pa.root[i]=pa.root[k];rank.root[i]=rank.root[k];
		}else{
			int a,b;scanf("%d%d",&a,&b);
			a^=ans;b^=ans;
			ans=(find(a)==find(b));
			printf("%d\n",ans);
		}
	}
	return 0;
}
