#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,C=1e6+10;
int n,q,a[N];
struct LinkMap{
	int tot,head[C],next[N],to[N],num[C],tail[C];
	void clear(){tot=0;cls(head);cls(num);cls(tail);}
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;++num[a];if(!tail[a])tail[a]=tot;}
	void changehead(int x,int y){if(x==y)return;head[y]=head[x];tail[y]=tail[x];head[x]=0;tail[x]=0;num[y]=num[x];num[x]=0;}
	int merge(int x,int y){next[tail[x]]=head[y];head[y]=0;tail[x]=tail[y];tail[y]=0;num[x]+=num[y];num[y]=0;return x;}
}lp;
inline int lowbit(int x){return x&(-x);}
struct Bit{
	int arr[N];
	void add(int x,int y){
		for(;x<=n;x+=lowbit(x))arr[x]+=y;
	}
	int sum(int x){
		int ret=0;
		for(;x;x-=lowbit(x))ret+=arr[x];
		return ret;
	}
	int sum(int x,int y){
		return sum(y)-sum(x-1);
	}
	void clear(){cls(arr);}
}bit;
struct UFS{
	int pa[N],rank[N];
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	void unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return;
		if(rank[a]<rank[b])swap(a,b);
		pa[b]=a;
		if(rank[a]==rank[b])++rank[a];
	}
}S;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		S.clear();
		bit.clear();lp.clear();
		rep(i,1,n)scanf("%d",&a[i]),lp.ins(a[i],i);
		rep(i,2,n)bit.add(i,a[i]!=a[i-1]);
		rep(i,1,C-1){
			for(int p=lp.head[i];p;p=lp.next[p])S.unio(lp.to[p],lp.to[lp.head[i]]);
		}
		while(q--){
			int op,x,y;scanf("%d%d%d",&op,&x,&y);
			if(op==1){
				if(x==y)continue;
				if(lp.num[x]==0)continue;
				if(lp.num[y]==0){lp.changehead(x,y);continue;}
				int a=x,b=y;
				if(lp.num[a]>lp.num[b])swap(a,b);
				int hb=S.find(lp.to[lp.head[b]]);
				for(int p=lp.head[a];p;p=lp.next[p]){
					int c=lp.to[p];
					if(c>1){
						int pa=S.find(c-1);
						if(pa==hb)bit.add(c,-1);
					}
					if(c<n){
						int pa=S.find(c+1);
						if(pa==hb)bit.add(c+1,-1);
					}
				}
				S.unio(lp.to[lp.head[x]],lp.to[lp.head[y]]);
				lp.changehead(lp.merge(x,y),y);
			}else{
				printf("%d\n",bit.sum(x+1,y)+1);
			}
		}
	}
	return 0;
}
