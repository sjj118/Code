#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

typedef long long LL;
const int N=5e4+10,B=300;
int n,m,k,a[N],c[N];
int ins(int x){
	x=a[x];
	++c[x];
	return 2*c[x]-1;
}
int del(int x){
	x=a[x];
	--c[x];
	return 2*c[x]+1;
}
LL Ans[N];
struct Query{
	int l,r,pos;
	LL ans;
}q[N];
bool operator<(const Query&a,const Query&b){return a.l/B<b.l/B||a.l/B==b.l/B&&a.r<b.r;}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d%d",&q[i].l,&q[i].r),q[i].pos=i;
	sort(q+1,q+1+m);
	int l=1,r=0;LL ans=0;
	rep(i,1,m){
		while(r<q[i].r)ans+=ins(++r);
		while(l>q[i].l)ans+=ins(--l);
		while(r>q[i].r)ans-=del(r--);
		while(l<q[i].l)ans-=del(l++);
		q[i].ans=ans;
	}
	rep(i,1,m)Ans[q[i].pos]=q[i].ans;
	rep(i,1,m)printf("%lld\n",Ans[i]);
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
