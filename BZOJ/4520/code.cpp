#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<algorithm>
#define sqr(x) ((x)*(x))
#define K 2
#define maxp 100010
#define LL long long
#define lson son[k][0]
#define rson son[k][1]

using namespace std;

int n,m,Q;
struct KDtree{
	int tot,root,son[maxp][2],split[maxp];
	struct Vector{
		LL d[K];
		bool operator<(const Vector&b)const{return d[Q]<b.d[Q];}
		void read(){for(int i=0;i<K;++i)scanf("%lld",&d[i]);}
	}val[maxp],left[maxp],right[maxp];
	LL dis(Vector a,Vector b){return sqr(a.d[0]-b.d[0])+sqr(a.d[1]-b.d[1]);}
	void addNode(){val[++tot].read();}
	void pushup(int k){
		left[k]=right[k]=val[k];
		for(int i=0;i<K;++i){
			if(lson)left[k].d[i]=min(left[k].d[i],left[lson].d[i]),right[k].d[i]=max(right[k].d[i],right[lson].d[i]);
			if(rson)left[k].d[i]=min(left[k].d[i],left[rson].d[i]),right[k].d[i]=max(right[k].d[i],right[rson].d[i]);
		}
	}
	int getsplit(int l,int r){
		int dir=0;
		double det=1e50;
		for(int k=0;k<K;++k){
			double ave=0;for(int i=l;i<=r;++i)ave+=val[i].d[k];ave/=(r-l+1);
			double delta=0;for(int i=l;i<=r;++i)delta+=sqr(val[i].d[k]-ave);
			if(delta<det)det=delta,dir=k;
		}
		return dir;
	}
	void build(int&k,int l,int r){
		k=(l+r)>>1;Q=split[k]=getsplit(l,r);
		nth_element(val+l,val+k,val+r+1);
		if(l<k)build(lson,l,k-1);
		if(k<r)build(rson,k+1,r);
		pushup(k);
	}
	void build(){
		build(root,1,tot);
	}
	LL farthest(int k,Vector x){
		LL tmp=0;
		for(int i=0;i<K;++i)tmp+=max(sqr(x.d[i]-left[k].d[i]),sqr(x.d[i]-right[k].d[i]));
		return tmp;
	}
	priority_queue<LL,vector<LL>,greater<LL> > heap;
	void pth_longest(int k,const Vector&x,const int&p){
		if(heap.size()<p)heap.push(dis(x,val[k]));
		else if(dis(x,val[k])>heap.top())heap.pop(),heap.push(dis(x,val[k]));
		int a=rson,b=lson;
		if(x.d[split[k]]<val[k].d[split[k]])a=lson,b=rson;
		if(a)pth_longest(a,x,p);
		if(b&&farthest(b,x)>heap.top())pth_longest(b,x,p);
	}
}T;

int main(){
	scanf("%d%d",&n,&m);m*=2;
	for(int i=1;i<=n;++i)T.addNode();
	T.build();
	for(int i=1;i<=n;++i){
		KDtree::Vector x=T.val[i];
		T.pth_longest(T.root,x,m);
	}
	printf("%lld",T.heap.top());
	return 0;
}
