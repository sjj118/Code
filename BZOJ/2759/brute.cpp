#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=30000+10,mo=10007;
inline void ck(int&x,int p){if(x<0)x+=p;if(x>=p)x-=p;}
int n,q,k[N],p[N],b[N],inv[mo];
int dfs(int k){

}
int main(){
	inv[1]=1;rep(i,2,mo-1)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d%d",&k[i],&p[i],&b[i]);
	scanf("%d",&q);
	while(q--){
		char op;scanf("\n%c",&op);
		if(op=='A'){
			int a;scanf("%d",&a);
			printf("%d\n",dfs(a));
		}else{
			int a,ka,pa,ba;scanf("%d%d%d%d",&a,&ka,&pa,&ba);
			k[a]=ka;p[a]=pa;b[a]=ba;
		}
	}
	return 0;
}
