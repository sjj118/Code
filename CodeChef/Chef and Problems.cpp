#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#define maxn 100005

using namespace std;

int n,m,k,a[maxn],s;
struct query{
	int l,r,ans,pos;
} q[maxn];
struct link{
	int head[maxn],tail[maxn],next[maxn],pre[maxn],val[maxn];
	int tot1,tot2,s[maxn];
	int newMem(int x){
		int t;
		if(tot2)t=s[tot2--];
		else t=++tot1;
		val[t]=x;
		return t;
	}
	void delMem(int k){
		s[++tot2]=k;
	}
	void push_head(int x,int p){
		int t;
		next[t=newMem(p)]=head[x];
		pre[head[x]]=t;
		if(!head[x])tail[x]=t;
		head[x]=t;
	}
	void push_back(int x,int p){
		int t;
		pre[t=newMem(p)]=tail[x];
		next[tail[x]]=t;
		if(!tail[x])head[x]=t;
		tail[x]=t;
	}
	void pop_head(int x){
		int k=head[x];
		head[x]=next[head[x]];
		next[k]=0;
		pre[head[x]]=0;
		if(!head[x])tail[x]=0;
		delMem(k);
	}
	void pop_back(int x){
		int k=tail[x];
		tail[x]=pre[tail[x]];
		pre[k]=0;
		next[tail[x]]=0;
		if(!tail[x])head[x]=0;
		delMem(k);
	}
} L;
bool comp(query a,query b){
	int k1=a.l/s,k2=b.l/s;
	return k1<k2||k1==k2&&a.r<b.r;
}
int anss[maxn];
priority_queue<int> Q;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	s=floor(sqrt(n));
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=0;i<k;++i)scanf("%d%d",&q[i].l,&q[i].r),q[i].pos=i;
	sort(q,q+k,comp);
	int l=1,r=0,ans=0;
	for(int i=0;i<k;++i){
		while(l<q[i].l){
			L.pop_head(a[l++]);
		}
		while(q[i].l<l){
			
		}
		while(r<q[i].r){
			
		}
		while(q[i].r<r){
			
		}
		q[i].ans=ans;
	}
	for(int i=0;i<k;++i)anss[q[i].pos]=q[i].ans;
	for(int i=0;i<k;++i)printf("%d\n",anss[i]);
	return 0;
} 
