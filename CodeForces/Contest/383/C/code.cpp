#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],col[N<<1],ano[N<<1];
inline int nxt(int x){
	if(x&1)return x+1;else return x-1;
}
void dfs(int k){
	if(!col[nxt(k)])col[nxt(k)]=3-col[k],dfs(nxt(k));
	if(!col[ano[k]])col[ano[k]]=3-col[k],dfs(ano[k]);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i],&b[i]),ano[a[i]]=b[i],ano[b[i]]=a[i];
	rep(i,1,n<<1)if(!col[i])col[i]=1,dfs(i);
	rep(i,1,n)printf("%d %d\n",col[a[i]],col[b[i]]);
	return 0;
}
