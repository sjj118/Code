#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10,P=N<<3;
int n,m,a[N];
#define ls (k<<1)
#define rs (k<<1|1)
struct SGT{
	LL mark[P],sum[P],fu[P];
	void update(int k){
		sum[k]=sum[ls]+sum[rs];
		fu[k]=fu[ls]+fu[rs];
	}
	void maintain_mark(int k,LL v,int l,int r){
		mark[k]+=v;
		sum[k]+=fu[k]*v;
	}
	void maintain(int k,int l,int r){
		int m=(l+r)>>1;
		if(mark[k])maintain_mark(ls,mark[k],l,m),maintain_mark(rs,mark[k],m+1,r),mark[k]=0;
	}
	void modify_mark(int ll,int rr,LL v,int k,int l,int r){
		if(ll<=l&&r<=rr){maintain_mark(k,v,l,r);return;}
		maintain(k,l,r);
		int m=(l+r)>>1;
		if(ll<=m)modify_mark(ll,rr,v,ls,l,m);
		if(rr>m)modify_mark(ll,rr,v,rs,m+1,r);
		update(k);
	}
	void modify_fu(int p,int v,int k,int l,int r){
		if(l==r){fu[k]=v;return;}
		maintain(k,l,r);
		int m=(l+r)>>1;
		if(p<=m)modify_fu(p,v,ls,l,m);
		else modify_fu(p,v,rs,m+1,r);
		update(k);
	}
	LL query_sum(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return sum[k];
		maintain(k,l,r);
		int m=(l+r)>>1;
		if(rr<=m)return query_sum(ll,rr,ls,l,m);
		if(ll>m)return query_sum(ll,rr,rs,m+1,r);
		return query_sum(ll,rr,ls,l,m)+query_sum(ll,rr,rs,m+1,r);
	}
}T;
int in[N],out[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],clo;
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		in[k]=++clo;
		T.modify_fu(clo,1,1,1,n<<1);
		T.modify_mark(clo,clo,a[k],1,1,n<<1);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k);
		out[k]=++clo;
		T.modify_fu(clo,-1,1,1,n<<1);
		T.modify_mark(clo,clo,a[k],1,1,n<<1);
	}
}G;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n-1){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
	G.dfs(1,0);
	rep(i,1,m){
		int op;scanf("%d",&op);
		if(op==1){
			int x,a;scanf("%d%d",&x,&a);
			T.modify_mark(in[x],in[x],a,1,1,n<<1);
			T.modify_mark(out[x],out[x],a,1,1,n<<1);
		}else if(op==2){
			int x,a;scanf("%d%d",&x,&a);
			T.modify_mark(in[x],out[x],a,1,1,n<<1);
		}else{
			int x;scanf("%d",&x);
			printf("%lld\n",T.query_sum(1,in[x],1,1,n<<1));
		}
	}
	return 0;
}
