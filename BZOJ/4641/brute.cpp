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
int n,m,c,a[N],b[N],pos[N],tot,cw[N],wc[N];
int main(){
	int cas;scanf("%d%d",&cas,&c);
	while(cas--){
		scanf("%d%d",&n,&m);
		rep(i,1,n)scanf("%d",&a[i]);
		rep(i,1,m)scanf("%d",&b[i]);
		tot=0;
		rep(i,1,n-m+1){
			cls(cw);cls(wc);bool flag=1;
			rep(j,1,m){
				if(!cw[b[j]]&&!wc[a[i+j-1]])cw[b[j]]=a[i+j-1],wc[a[i+j-1]]=b[j];
				else if(cw[b[j]]!=a[i+j-1]){flag=0;break;}
			}
			if(flag)pos[++tot]=i;
		}
		printf("%d\n",tot);
		rep(i,1,tot)printf("%d ",pos[i]);puts("");
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
