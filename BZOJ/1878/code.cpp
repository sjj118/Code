#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 50010
#define maxm 200010
#define maxv 1000010
#define lowbit(x) x&(-x)

using namespace std;

int n,m,a[maxn],head[maxv],next[maxn];
struct Query{
	int l,r,pos,ans;
}q[maxm];
bool comp(Query a,Query b){return a.l<b.l;}
struct Bit{
	int arr[maxn];
	void add(int x,int t){
		if(x)for(;x<=n;x+=lowbit(x))arr[x]+=t;
	}
	int sum(int x){
		int tmp=0;
		for(;x;x-=lowbit(x))tmp+=arr[x];
		return tmp;
	}
}bit;
int ans[maxm];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)scanf("%d%d",&q[i].l,&q[i].r),q[i].pos=i;
	sort(q+1,q+1+m,comp);
	for(int i=n;i;--i)next[i]=head[a[i]],head[a[i]]=i;
	for(int i=0;i<maxv;++i)bit.add(head[i],1);
	for(int i=1,j=1;i<=n;++i){
		while(j<=m&&q[j].l==i)q[j].ans=bit.sum(q[j].r),++j;
		bit.add(head[a[i]],-1);head[a[i]]=next[head[a[i]]];
		bit.add(head[a[i]],1);
	}
	for(int i=1;i<=m;++i)ans[q[i].pos]=q[i].ans;
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}
