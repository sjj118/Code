#include<iostream>
#include<cstdio>
#include<algorithm>
#define ls (k<<1)
#define rs (k<<1|1)
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=2e5+10,maxp=16e5+10;
const LL mo=2147483648ll;
inline void up(int&x,int y){if(y>x)x=y;}
struct Answer{
	LL v;
	void update(){v%=mo;if(v<0)v+=mo;}
	Answer(LL x=0){v=x;update();}
	void output(){
		int a[20],l=0;
		LL x=v;
		while(x)a[++l]=x%10,x/=10;
		if(!l)putchar('0');
		while(l)putchar(a[l--]+'0');puts("");
	}
	void operator=(const int x){v=x;update();}
	void operator+=(const Answer&x){v+=x.v;update();}
	void operator-=(const Answer&x){v-=x.v;update();}
	void operator*=(const Answer&x){v*=x.v;update();}
	Answer operator+(const Answer&x){return Answer(x.v+v);}
	Answer operator-(const Answer&x){return Answer(x.v-v);}
	Answer operator*(const Answer&x){return Answer(x.v*v);}
};
int n,q,sign,dfn[maxn];
struct Interval{
	int l,r;
};
bool operator<(Interval a,Interval b){return a.l<b.l||a.l==b.l&&a.r<b.r;}
struct Graph{
	int tot,head[maxn],next[maxn<<1],to[maxn<<1],intime[maxn],outime[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		dfn[intime[k]=++sign]=k;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre)dfs(to[p],k);
		dfn[outime[k]=++sign]=-k;
	}
}G;
struct SGT{
	Answer val[maxp],f[maxp],add[maxp],sum[maxp];
	void pushup(int k,int l,int r){
		if(l==r){sum[k]=val[k]*f[k];return;};
		sum[k]=sum[ls]+sum[rs];f[k]=f[ls]+f[rs];
	}
	void build(int k,int l,int r){
		if(l==r){if(dfn[l]<0)dfn[l]=-dfn[l],f[k]=-1;else f[k]=1;val[k]=0;sum[k]=0;return;}
		int m=(l+r)>>1;
		build(ls,l,m);build(rs,m+1,r);
		pushup(k,l,r);
	}
	void modify_add(int k,int l,int r,const Answer&v){
		if(l==r)val[k]+=v;
		add[k]+=v;sum[k]+=f[k]*v;
	}
	void pushdown(int k,int l,int r){
		if(l==r)return;
		int m=(l+r)>>1;
		if(add[k].v)modify_add(ls,l,m,add[k]),modify_add(rs,m+1,r,add[k]),add[k]=0;
	}
	void modify(int ll,int rr,Answer v,int k,int l,int r){
		if(ll<=l&&r<=rr){modify_add(k,l,r,v);return;}
		pushdown(k,l,r);
		int m=(l+r)>>1;
		if(ll<=m)modify(ll,rr,v,ls,l,m);
		if(rr>m)modify(ll,rr,v,rs,m+1,r);
		pushup(k,l,r);
	}
	Answer query(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return sum[k];
		pushdown(k,l,r);
		int m=(l+r)>>1;
		if(rr<=m)return query(ll,rr,ls,l,m);
		if(ll>m)return query(ll,rr,rs,m+1,r);
		return query(ll,rr,ls,l,m)+query(ll,rr,rs,m+1,r);
	}
}T;
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.dfs(1,0);T.build(1,1,sign);
	scanf("%d",&q);
	while(q--){
		int op;scanf("%d",&op);
		if(op==0){
			int u,d;scanf("%d%d",&u,&d);
			T.modify(G.intime[u],G.outime[u],Answer(d),1,1,sign);
		}else{
			int k;scanf("%d",&k);
			Interval inter[6];rep(i,1,k)scanf("%d%d",&inter[i].l,&inter[i].r);
			rep(i,1,k){
				inter[i].l=G.intime[inter[i].l];inter[i].r=G.intime[inter[i].r];
				if(inter[i].l>inter[i].r)swap(inter[i].l,inter[i].r);
			}
			sort(inter+1,inter+1+k);
			Answer ans=0;
			rep(i,1,k){
				if(i<k&&inter[i].r>=inter[i+1].l)inter[i+1].l=inter[i].l,up(inter[i+1].r,inter[i].r);
				else ans+=T.query(inter[i].l,inter[i].r,1,1,sign);
			}
			ans.output();
		}
	}
}
