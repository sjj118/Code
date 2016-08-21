#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
#define cls(a) memset(a,0,sizeof(a))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int maxp=1e7,maxn=1e6+10,maxnm=1e6+10;
int n,m,q;
int root[maxnm],rootI[maxn],rootS[maxn];
struct SGT{
	int tot,son[maxp][2],val[maxp];
	int modify(int p,int x,int k,int l,int r){
		int t=++tot;
		if(l==r){val[t]=x;return t;}
		int m=(l+r)>>1;
		if(p<=m)son[t][0]=modify(p,x,son[k][0],l,m),son[t][1]=son[k][1];
		else son[t][0]=son[k][0],son[t][1]=modify(p,x,son[k][1],m+1,r);
		val[t]=val[son[t][0]]+val[son[t][1]];
		return t;
	}
	int get(int ll,int rr,int k,int l,int r){
		if(!k)return 0;
		if(ll<=l&&r<=rr)return val[k];
		int m=(l+r)>>1;
		if(rr<=m)return get(ll,rr,son[k][0],l,m);
		if(ll>m)return get(ll,rr,son[k][1],m+1,r);
		return get(ll,rr,son[k][0],l,m)+get(ll,rr,son[k][1],m+1,r);
	}
}T,I,S;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,q){
		int op;scanf("%d",&op);
		if(op==1){
			int x,y;scanf("%d%d",&x,&y);
			int t=I.get(x,x,rootI[i-1],1,n);
			root[i]=T.modify((x-1)*m+y,!t,root[i-1],1,n*m);
			rootI[i]=rootI[i-1];
			if(t)rootS[i]=S.modify(x,m-T.get((x-1)*m+1,x*m,root[i],1,n*m),rootS[i-1],1,n);
			else rootS[i]=S.modify(x,T.get((x-1)*m+1,x*m,root[i],1,n*m),rootS[i-1],1,n);
		}else if(op==2){
			int x,y;scanf("%d%d",&x,&y);
			int t=I.get(x,x,rootI[i-1],1,n);
			root[i]=T.modify((x-1)*m+y,t,root[i-1],1,n*m);
			rootI[i]=rootI[i-1];
			if(t)rootS[i]=S.modify(x,m-T.get((x-1)*m+1,x*m,root[i],1,n*m),rootS[i-1],1,n);
			else rootS[i]=S.modify(x,T.get((x-1)*m+1,x*m,root[i],1,n*m),rootS[i-1],1,n);
		}else if(op==3){
			int x;scanf("%d",&x);
			rootI[i]=I.modify(x,!I.get(x,x,rootI[i-1],1,n),rootI[i-1],1,n);
			int t=I.get(x,x,rootI[i],1,n);
			root[i]=root[i-1];
			rootS[i]=S.modify(x,T.get((x-1)*m+1,x*m,rootS[i-1],1,n*m),rootS[i-1],1,n);
			if(t)rootS[i]=S.modify(x,m-T.get((x-1)*m+1,x*m,root[i],1,n*m),rootS[i-1],1,n);
			else rootS[i]=S.modify(x,T.get((x-1)*m+1,x*m,root[i],1,n*m),rootS[i-1],1,n);
		}else{
			int x;scanf("%d",&x);
			root[i]=root[x];
			rootI[i]=rootI[x];
			rootS[i]=rootS[x];
		}
		printf("%d\n",S.val[rootS[i]]);
	}
	return 0;
}
