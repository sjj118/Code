#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define lowbit(x) (x)&(-x)
#define ll long long
#define maxn 50010

using namespace std;

int n,m,arr[maxn],k;
int get(int x){
	int ans=0;
	while(x){
		ans+=arr[x];
		x-=lowbit(x);
	}
	return ans;
}
void add(int x,int t){
	while(x<=n){
		arr[x]+=t;
		x+=lowbit(x);
	}
}
struct query{
	int l,r,pos;
	ll ans;
} q[maxn];
bool comp(query a,query b){
	int k1=a.l/k,k2=b.l/k;
	return k1<k2||k1==k2&&a.r<b.r;
}
struct lisan{
	int s,k,pos;
} e[maxn];
bool comp2(lisan a,lisan b){
	return a.s<b.s;
}
int c[maxn],s[maxn];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&e[i].s);
	for(int i=1;i<=n;++i)e[i].pos=i;
	sort(e+1,e+n+1,comp2);
	e[1].k=1;
	for(int i=2;i<=n;++i)if(e[i-1].s==e[i].s)e[i].k=e[i-1].k;else e[i].k=e[i-1].k+1;
	for(int i=1;i<=n;++i)s[e[i].pos]=e[i].k;
	scanf("%d",&m);
	for(int i=0;i<m;++i)scanf("%d%d",&q[i].l,&q[i].r);
	for(int i=0;i<m;++i)q[i].pos=i;
	k=sqrt(n);
	sort(q,q+m,comp);
	int l=1,r=0;
	ll ans=0;
	for(int i=0;i<m;++i){
		while(r>q[i].r){
			add(s[r],-1);
			ans-=r-l-get(s[r]);
			--r;
		}
		while(r<q[i].r){
			++r;
			ans+=r-l-get(s[r]);
			add(s[r],1);
		}
		while(l<q[i].l){
			add(s[l],-1);
			ans-=get(s[l]-1);
			++l;
		}
		while(l>q[i].l){
			--l;
			ans+=get(s[l]-1);
			add(s[l],1);
		}
		q[i].ans=ans;
	}
	for(int i=0;i<m;++i)c[q[i].pos]=i;
	for(int i=0;i<m;++i)printf("%lld\n",q[c[i]].ans);
	return 0;
}
