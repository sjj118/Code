#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=1e6+10;
int n,m,C,s[N],t[N],a[N],b[N],ap[N],pre[N],pos[N],tot;
inline int cw(int l,int x){return x>=l?0:x;}
int main(){
	int cas;scanf("%d%d",&cas,&C);
	while(cas--){
		scanf("%d%d",&n,&m);
		rep(i,1,n)scanf("%d",&s[i]);
		rep(i,1,m)scanf("%d",&t[i]);
		cls(ap);rep(i,1,n)a[i]=i-ap[s[i]],ap[s[i]]=i;
		cls(ap);rep(i,1,m)b[i]=i-ap[t[i]],ap[t[i]]=i;
		pre[1]=0;tot=0;
		for(int i=2,j=0;i<=m;++i){
			while(j&&cw(j+1,b[j+1])!=cw(j+1,b[i]))j=pre[j];
			if(cw(j+1,b[j+1])==cw(j+1,b[i]))++j;
			pre[i]=j;
		}
		for(int i=1,j=0;i<=n;++i){
			while(j&&cw(j+1,b[j+1])!=cw(j+1,a[i]))j=pre[j];
			if(cw(j+1,b[j+1])==cw(j+1,a[i]))++j;
			if(j==m)pos[++tot]=i-j+1,j=pre[j];
		}
		printf("%d\n",tot);
		rep(i,1,tot)printf("%d ",pos[i]);puts("");
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
