#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100010
#define maxm 4000010

using namespace std;

int n,m;
struct Graph{
	int tot,head[maxn],next[maxm],to[maxm];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
}G;
struct UFS{
	int pa[maxn],rank[maxn];
	int head,next[maxn],pre[maxn],sign[maxn],size[maxn];
	int find(int k){return pa[k]==k?k:find(pa[k]);}
	void init(){
		for(int i=1;i<=n;++i)pa[i]=i,size[i]=1;
		for(int i=1;i<n;++i)next[i]=i+1,pre[i]=i-1;pre[n]=n-1;head=1;
	}
	void del(int k){
		if(head==k)head=next[k];else next[pre[k]]=next[k];
		pre[next[k]]=pre[k];
	}
	void unio(int a,int b){
		a=find(a);b=find(b);
		if(rank[a]<rank[b])swap(a,b);
		pa[b]=a;size[a]+=size[b];sign[a]+=sign[b];
		if(rank[a]==rank[b])++rank[a];
		del(b);
	}
}S;
int tot,num[maxn];

int main(){
	scanf("%d%d",&n,&m);
	S.init();
	for(int i=1;i<=m;++i){
		int a,b;scanf("%d%d",&a,&b);
		G.addedge(a,b);
	}
	for(int k=1;k<=n;++k){
		for(int p=S.head;p;p=S.next[p])S.sign[p]=0;
		for(int p=G.head[k];p;p=G.next[p])++S.sign[S.find(G.to[p])];
		for(int p=S.head;p;p=S.next[p])if(p!=S.find(k)&&S.sign[p]<S.size[p])S.unio(k,p);
	}
	for(int p=S.head;p;p=S.next[p])num[++tot]=S.size[p];
	sort(num+1,num+1+tot);
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i)printf("%d ",num[i]);
	return 0;
}
