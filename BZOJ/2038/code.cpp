#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn 50010
#define inf 1e9
#define ll long long
#define ull unsigned ll

using namespace std;

ull n,m,c[maxn],s,num[maxn];
ull gcd(ull a,ull b){
	if(!b)return a;
	return gcd(b,a%b);
}
struct Normal{
	ull p,q;
	void update(){
		ull d=gcd(p,q);
		if(d){
			p/=d;
			q/=d;
		}else{
			p=0;
			q=1;
		}
	}
};
struct query{
	ull l,r,pos;
	Normal ans;
} q[maxn];
bool comp(query a,query b){
	ull x1=a.l/s,x2=b.l/s;
	return x1<x2||x1==x2&&a.r<b.r;
}
ull home[maxn];
ull count(ull x){
	return x*(x-1)/2; 
}

int main(){
	scanf("%d%d",&n,&m);
	s=floor(sqrt(n));
	for(ull i=1;i<=n;++i)scanf("%d",&c[i]);
	for(ull i=0;i<m;++i)scanf("%d%d",&q[i].l,&q[i].r);
	for(ull i=0;i<m;++i)q[i].pos=i;
	sort(q,q+m,comp);
	ull len=q[0].r-q[0].l+1;
	q[0].ans.q=len*(len-1)/2;
	for(ull i=q[0].l;i<=q[0].r;++i){
		++num[c[i]];
		q[0].ans.p+=count(num[c[i]])-count(num[c[i]]-1);
	}
	for(ull i=1;i<m;++i){
		len=q[i].r-q[i].l+1;
		q[i].ans.q=len*(len-1)/2;
		q[i].ans.p=q[i-1].ans.p;
		if(q[i-1].l<q[i].l){
			for(ull j=q[i-1].l+1;j<=q[i].l;++j){
				--num[c[j-1]];
				q[i].ans.p+=count(num[c[j-1]])-count(num[c[j-1]]+1);
			}
		}else{
			for(ull j=q[i-1].l-1;j>=q[i].l;--j){
				++num[c[j]];
				q[i].ans.p+=count(num[c[j]])-count(num[c[j]]-1);
			}
		}
		if(q[i-1].r<q[i].r){
			for(ull j=q[i-1].r+1;j<=q[i].r;++j){
				++num[c[j]];
				q[i].ans.p+=count(num[c[j]])-count(num[c[j]]-1);
			}
		}else{
			for(ull j=q[i-1].r-1;j>=q[i].r;--j){
				--num[c[j+1]];
				q[i].ans.p+=count(num[c[j+1]])-count(num[c[j+1]]+1);
			}
		}
	}
	for(ull i=0;i<m;++i)home[q[i].pos]=i;
	for(ull i=0;i<m;++i){
		Normal ans=q[home[i]].ans;
		ans.update();
		printf("%llu/%llu\n",ans.p,ans.q);
	}
	return 0;
} 
