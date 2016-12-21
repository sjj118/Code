#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
#define cls(a) memset(a,0,sizeof(a))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
int n,m,k,storge[maxn];
struct Edge{
	int u,v,l;
}e[maxn];
bool operator<(Edge a,Edge b){return a.l<b.l;}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].l);
	}
	sort(e+1,e+1+m);
	rep(i,1,k){int x;scanf("%d",&x);storge[x]=1;}
	int ans=-1;
	rep(i,1,m)if(storge[e[i].u]+storge[e[i].v]==1){printf("%d",e[i].l);return 0;}
	printf("-1");
	return 0;
}
