#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=20000+10,inf=1e9+7;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,q,a[N];
bool cmp(int*a,int*b){return *a<*b;}
struct Lisan{
	int tot,*val[N],ml,rl[N];
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,cmp);
		for(int i=1,last=-inf;i<=tot;++i){
			if(*val[i]>last)last=rl[++ml]=*val[i];
			*val[i]=ml;
		}
	}
}lisan;
struct LinkMap{
	int tot,head[N],next[N],to[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
}lp;
int root[N];
const int P=1e7;
#define ls son[k][0]
#define rs son[k][1]
struct Data{
	int sum,ml,mr;
	Data(){}
	Data(int sum,int ml,int mr):sum(sum),ml(ml),mr(mr){}
};
Data operator+(const Data&a,const Data&b){
	Data ret;
	ret.sum=a.sum+b.sum;
	ret.ml=min(a.ml,a.sum+b.ml);
	ret.mr=min(b.mr,b.sum+a.mr);
	return ret;
}
struct SGT{
	int tot,son[P][2];
	Data data[P];
	void update(int k){
		data[k]=data[ls]+data[rs];
	}
	void build(int&k,int l,int r){
		if(!k)k=++tot;
		if(l==r){data[k]=Data(-1,-1,-1);return;}
		int m=(l+r)>>1;
		build(ls,l,m);build(rs,m+1,r);
		update(k);
	}
	int modify(int p,int v,int k,int l,int r){
		int t=++tot;
		data[t]=data[k];
		if(l==r){data[t].sum+=v;data[t].ml=data[t].mr=min(0,data[t].sum);return t;}
		int m=(l+r)>>1;
		if(p<=m)son[t][0]=modify(p,v,ls,l,m),son[t][1]=rs;
		else son[t][0]=ls,son[t][1]=modify(p,v,rs,m+1,r);
		update(t);
		return t;
	}
	Data query(int ll,int rr,int k,int l,int r){
		if(ll<=l&&r<=rr)return data[k];
		int m=(l+r)>>1;
		if(rr<=m)return query(ll,rr,ls,l,m);
		if(ll>m)return query(ll,rr,rs,m+1,r);
		return query(ll,rr,ls,l,m)+query(ll,rr,rs,m+1,r);
	}
}T;
int main(){
	n=read();
	rep(i,1,n)lisan.ins(a[i]=read());
	lisan.work();
	rep(i,1,n)lp.ins(a[i],i);
	T.build(root[0],1,n);
	rep(i,1,lisan.ml){
		root[i]=root[i-1];
		for(int p=lp.head[i];p;p=lp.next[p])root[i]=T.modify(lp.to[p],2,root[i],1,n);
	}
	scanf("%d",&q);
	int ans=0;
	while(q--){
		int x[4];rep(i,0,3)x[i]=(ans+read())%n+1;
		sort(x,x+4);
		int l=1,r=lisan.ml;
		while(l<r){
			int mid=(l+r)>>1;
			if(T.query(x[2]+1,x[3],root[mid],1,n).ml
			  +T.query(1,x[2],root[mid],1,n).sum
			  +T.query(x[0],x[1]-1,root[mid],1,n).mr
			  +T.query(x[1],n,root[mid],1,n).sum
			  -T.data[root[mid]].sum<=0)
				l=mid+1;else r=mid;
		}
		printf("%d\n",ans=lisan.rl[l]);
	}
	return 0;
}
