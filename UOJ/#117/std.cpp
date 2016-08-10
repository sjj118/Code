#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200010;

int i,j,t,n,m,cnt;
int I[maxn],O[maxn];
bool V[maxn];

struct Node{int v,cnt;Node*next;}*E[maxn],G[maxn*4];
inline void ad(int u,int v,int w){
	G[++cnt].v=v;G[cnt].cnt=w;G[cnt].next=E[u];E[u]=&G[cnt];
	I[v]++;O[u]++;
}

int S[maxn],top;
int dfs(int u){
	for(Node*p=E[u];p;p=E[u]){
		while(p&&V[abs(p->cnt)])p=p->next;
		E[u]=p;
		if(p){
			V[abs(p->cnt)]=true;
			dfs(p->v);
			S[++top]=p->cnt;
		}
	}
}

int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	
	scanf("%d%d%d",&t,&n,&m);
	for(i=1;i<=m;i++){int u,v;
		scanf("%d%d",&u,&v);
		ad(u,v,i);if(t==1)ad(v,u,-i);
	}
	for(i=1;i<=n;i++)if((t==1&&(I[i]&1))||(t==2&&I[i]!=O[i])){puts("NO");return 0;}
	dfs(G[1].v);
	if(top<m){puts("NO");return 0;}
	puts("YES");
	while(top)printf("%d ",S[top--]);printf("\n");
	
	return 0;
}
