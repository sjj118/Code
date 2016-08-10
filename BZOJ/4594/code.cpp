#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a))
#define maxn 100010

using namespace std;

int n,m;
struct Graph{
	int tot,head[maxn],to[maxn],next[maxn];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void clear(){tot=0;cls(head);}
	bool solve(int l,int r){
		if(r-l==1)return 1;
		int n,flag=0;
		if(to[head[l]]-l==r-to[head[l]])n=to[head[l]]-l;else n=to[head[l]]-to[next[head[l]]];
		for(int p=head[l];p;p=next[p],head[l]=p){
			if(to[p]<l+n)break;
			if((to[p]-l)%n)return 0;
			if(to[p]>n+l&&to[p]-to[next[p]]!=n)return 0;
			if(to[p]==n+l)flag=1;
		}
		if(!flag)return 0;
		for(int i=l+1;i<l+n;++i){
			flag=0;
			for(int p=head[i];p;p=next[p],head[i]=p){
				if(to[p]<l+n)break;
				if((to[p]-l)%n!=i-l)return 0;
				if(to[p]>i+n&&to[p]-to[next[p]]!=n)return 0;
				if(to[p]==n+i)flag=1;
			}
			if(!flag)return 0;
		}
		return solve(l,l+n)&&solve(l+n,r);
	}
}tG,G;
int edge[maxn],tot;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		G.clear();tG.clear();
		for(int i=1;i<=m;++i){
			int a,b;scanf("%d%d",&a,&b);
			if(a>b)swap(a,b);
			tG.ins(a,b);
		}
		for(int i=0;i<n;++i){
			tot=0;
			for(int p=tG.head[i];p;p=tG.next[p])edge[++tot]=tG.to[p];
			sort(edge+1,edge+1+tot);
			for(int j=1;j<=tot;++j)G.ins(i,edge[j]);
		}
		if(G.solve(0,n))printf("YES\n");else printf("NO\n");
	}
	return 0;
}
