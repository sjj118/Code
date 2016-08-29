#include<iostream>
#include<cstdio>
#define ls (son[k][0])
#define rs (son[k][1])
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=3e5+10;
int n,addall;
struct LeftistTree{
	int val[maxn],pa[maxn],son[maxn][2],dis[maxn],ma[maxn];
	LeftistTree(){dis[0]=-1;val[0]=-maxn;}
	void update(int k){
		if(dis[ls]<dis[rs])swap(ls,rs);
		dis[k]=dis[ls]+1;
	}
	void maintain(int k){
		val[ls]+=ma[k];ma[ls]+=ma[k];
		val[rs]+=ma[k];ma[rs]+=ma[k];
		ma[k]=0;
	}
	int stack[maxn],top;
	void solvetag(int k){
		while(k)stack[++top]=k,k=pa[k];
		while(top)maintain(stack[top--]);
	}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	int merge(int k,int p){
		if(val[k]<val[p])swap(k,p);
		if(p==0)return k;
		pa[rs=merge(rs,p)]=k;
		update(k);
		return k;
	}
}T;
struct Heap{
	int tot,key[maxn],pos[maxn];
	void pushdown(int k){
		while((k<<1)<=tot){
			if(((k<<1|1)>tot||T.val[key[k<<1]]>T.val[key[k<<1|1]])&&T.val[key[k<<1]]>T.val[key[k]])swap(key[k],key[k<<1]),swap(pos[key[k]],pos[key[k<<1]]),k=k<<1;
			else if((k<<1|1)<=tot&&T.val[key[k<<1|1]]>T.val[key[k]])swap(key[k],key[k<<1|1]),swap(pos[key[k]],pos[key[k<<1|1]]),k=k<<1|1;
			else break;
		}
	}
	void pushup(int k){
		while(k>1){
			if(T.val[key[k]]>T.val[key[k>>1]])swap(key[k],key[k>>1]),swap(pos[key[k]],pos[key[k>>1]]),k=k>>1;
			else break;
		}
	}
	void build(){
		tot=n;
		per(i,n,1)key[i]=i,pos[i]=i,pushdown(i);
	}
	void del(int k){
		k=pos[k];
		swap(key[k],key[tot]);swap(pos[key[k]],pos[key[tot]]);--tot;pushdown(k);
	}
	void push(int k){
		key[++tot]=k;pos[k]=tot;pushup(tot);
	}
}heap;
void unio(int a,int b){
	a=T.find(a);b=T.find(b);
	if(a==b)return;
	if(T.val[a]<T.val[b])swap(a,b);
	T.pa[b]=a;
	T.merge(a,b);
	heap.del(b);
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&T.val[i]),T.pa[i]=i;
	heap.build();
	int q;scanf("%d",&q);
	while(q--){
		char op[2];
		scanf("\n%s",op);
		if(op[0]=='U'){
			int x,y;scanf("%d%d",&x,&y);unio(x,y);
		}else if(op[0]=='A'){
			if(op[1]=='1'){
				int x,v;scanf("%d%d",&x,&v);
				heap.del(x);
				T.val[x]+=v;
				T.pushup(x);T.pushdown(x);
				heap.push(T.find(x));
			}else if(op[1]=='2'){
				int x,v;scanf("%d%d",&x,&v);
				x=T.find(x);T.val[x]+=v;T.ma[x]+=v;
				T.pushup(x);T.pushdown(x);heap.pushup(x);heap.pushdown(x);
			}else{
				int v;scanf("%d",&v);
				addall+=v;
			}
		}else if(op[0]=='F'){
			if(op[1]=='1'){
				int x;scanf("%d",&x);
				T.solvetag(x);
				printf("%d\n",T.val[x]+addall);
			}else if(op[1]=='2'){
				int x;scanf("%d",&x);
				x=T.find(x);printf("%d\n",addall+T.val[x]);
			}else{
				printf("%d\n",T.val[heap.key[1]]+addall);
			}
		}
	}
	return 0;
}  
