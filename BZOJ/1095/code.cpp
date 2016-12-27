#include<iostream>
#include<cstdio>
#include<queue>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,NLOGN=2e6;
inline void up(int&x,int y){if(y>x)x=y;}
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,q,on[N];
struct Heap{
	priority_queue<int>A,B;
	int size(){return A.size()-B.size();}
	void update(){while(B.size()&&A.top()==B.top())A.pop(),B.pop();}
	void push(int x){A.push(x);}
	void del(int x){B.push(x);}
	void pop(){update();A.pop();}
	int top(){if(size()==0)return -1;update();return A.top();}
	int top2(){
		if(size()==0)return -1;
		if(size()==1)return min(0,top());
		int x=top();pop();
		int y=top();push(x);
		if(y<0)return min(0,x);
		return x+y;
	}
}A,B[N],C[N];
struct LinkMap{
	int tot,head[N],to[NLOGN],next[NLOGN],len[NLOGN];
	void ins(int a,int b,int c){to[++tot]=b;next[tot]=head[a];head[a]=tot;len[tot]=c;}
}lp;
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],mark[N],size[N],weight[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	int getsize(int k,int pre,int rt,int l){
		size[k]=1;
		if(pre)lp.ins(k,rt,l);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!mark[to[p]])size[k]+=getsize(to[p],k,rt,l+1);
		return size[k];
	}
	int getcore(int k,int pre,int s){
		int ret=k;
		weight[k]=s-size[k];
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!mark[to[p]])up(weight[k],size[to[p]]);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!mark[to[p]]){
			int t=getcore(to[p],k,s);
			if(weight[t]<weight[ret])ret=t;
		}
		return ret;
	}
	void getC(int k,int pre,int rt,int l){
		C[rt].push(l);
		for(int p=head[k];p;p=next[p])if(to[p]!=pre&&!mark[to[p]])getC(to[p],k,rt,l+1);
	}
	void divide(int k){
		mark[k]=1;
		getsize(k,0,k,0);
		B[k].push(0);
		for(int p=head[k];p;p=next[p])if(!mark[to[p]]){
			int g=getcore(to[p],k,size[to[p]]);
			getC(to[p],k,g,1);
			int t=C[g].top();
			B[k].push(t);
			divide(g);
		}
		A.push(B[k].top2());
		mark[k]=0;
	}
}G;
void ins(int x){
	A.del(B[x].top2());
	B[x].push(0);
	A.push(B[x].top2());
	for(int g=x,k,p=lp.head[x];p;g=k,p=lp.next[p]){
		k=lp.to[p];
		A.del(B[k].top2());
		B[k].del(C[g].top());
		C[g].push(lp.len[p]);
		B[k].push(C[g].top());
		A.push(B[k].top2());
	}
}
void del(int x){
	A.del(B[x].top2());
	B[x].del(0);
	A.push(B[x].top2());
	for(int g=x,k,p=lp.head[x];p;g=k,p=lp.next[p]){
		k=lp.to[p];
		A.del(B[k].top2());
		B[k].del(C[g].top());
		C[g].del(lp.len[p]);
		B[k].push(C[g].top());
		A.push(B[k].top2());
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1)G.addedge(read(),read());
	G.divide(1);
	scanf("%d",&q);
	while(q--){
		char op;scanf("\n%c",&op);
		if(op=='C'){
			int x;scanf("%d",&x);
			if(on[x])ins(x);
			else del(x);
			on[x]^=1;
		}else{
			printf("%d\n",A.top());
		}
	}
	return 0;
}
