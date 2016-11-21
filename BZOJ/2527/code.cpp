#include<iostream>
#include<cstdio>
#include<vector>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int N=3e5+10,inf=1e9;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
int n,m,q,p[N];
vector<int> lp[N];
struct Meteors{
	int l,r,a;
}o[N];
int c[N];
int ans[N];
inline int lowbit(int x){return x&(-x);}
struct Bit{
	LL arr[N];
	void add(int x,LL y){
		for(;x<=m;x+=lowbit(x))arr[x]+=y;
	}
	void add(int l,int r,LL v){
		add(l,v);add(r+1,-v);
	}
	LL get(int x){
		LL ret=0;
		for(;x;x-=lowbit(x))ret+=arr[x];
		return ret;
	}
}bit;
void add(int l,int r,LL v){
	if(l<=r)bit.add(l,r,v);
	else bit.add(l,m,v),bit.add(1,r,v);
}
int T=0,tmp[N];
void solve(int l,int r,int ll,int rr){
	if(l==r){rep(i,ll,rr)ans[c[i]]=l;return;}
	int mid=(l+r)>>1;
	while(T<mid)++T,add(o[T].l,o[T].r,o[T].a);
	while(T>mid)add(o[T].l,o[T].r,-o[T].a),--T;
	rep(i,ll,rr)tmp[i]=c[i];
	int s=ll,t=rr;
	rep(i,ll,rr){
		LL cnt=0;
		rep(j,0,int(lp[tmp[i]].size())-1){cnt+=bit.get(lp[tmp[i]][j]);if(cnt>=p[tmp[i]])break;}
		if(cnt>=p[tmp[i]])c[s++]=tmp[i];else c[t--]=tmp[i];
	}
	solve(l,mid,ll,s-1);solve(mid+1,r,t+1,rr);
}
int main(){
	n=read();m=read();
	rep(i,1,m){int x=read();lp[x].push_back(i);}
	rep(i,1,n)p[i]=read();
	q=read();
	rep(i,1,q)o[i].l=read(),o[i].r=read(),o[i].a=read();
	rep(i,1,n)c[i]=i;
	solve(1,q+1,1,n);
	rep(i,1,n)if(ans[i]==q+1)puts("NIE");else printf("%d\n",ans[i]);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
