#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
const int maxn=1e6+10,maxm=1e6+10;
inline void up(int&x,int y){if(y>x)x=y;}
using namespace std;
int n,m,a[maxn],b[maxn],da[maxn],db[maxn],pa[maxn],pb[maxn],c[maxm],la[maxm],lb[maxn];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n)scanf("%d",&a[i]);
		rep(i,1,m)scanf("%d",&b[i]);
		cls(c);
		rep(i,1,n)pa[i]=c[a[i]-1],c[a[i]]=i;
		cls(c);
		rep(i,1,m)pb[i]=c[b[i]-1],c[b[i]]=i;
		rep(i,1,n)da[i]=da[pa[i]]+1;
		rep(i,1,m)db[i]=db[pb[i]]+1;
		cls(la);cls(lb);
		rep(i,1,n)up(la[a[i]],da[i]);
		rep(i,1,m)up(lb[b[i]],db[i]);
		int ans=0;
		rep(i,1,maxm-1)up(ans,min(la[i],lb[i]));
		printf("%d\n",ans);
	}
	return 0;
}
