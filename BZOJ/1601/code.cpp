#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 400
#define maxv 100000

using namespace std;

int n,tot,ans,cnt;
struct EDGE{
	int from,to,len;
} edge[maxv];
bool comp(EDGE a,EDGE b){
	return a.len<b.len;
}
int pa[maxn],rank[maxn];
int find(int a){
	if(pa[a])pa[a]=find(pa[a]);
	else return a;
	return pa[a];
}
void unio(int a,int b){
	a=find(a);b=find(b);
	if(rank[a]<rank[b])pa[a]=b,++rank[b];
	else pa[b]=a,++rank[a];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		edge[tot++]={n+1,i,x};
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int x;
			scanf("%d",&x);
			if(i<j)edge[tot++]={i,j,x};
		}
	}
	sort(edge,edge+tot,comp);
	for(int i=0;i<tot;++i){
		int a=edge[i].from,b=edge[i].to;
		if(find(a)!=find(b)){
			unio(a,b);
			ans+=edge[i].len;
			++cnt;
			if(cnt==n)break;
		}
	}
	printf("%d",ans);
	return 0;
} 
