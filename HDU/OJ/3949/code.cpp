#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
typedef long long LL;
const int N=1e4+10;
int n,q,flag;
LL a[N],wei[70];
inline LL min(LL a,LL b){return a<b?a:b;}
inline LL max(LL a,LL b){return a>b?a:b;}
void gauss(){
	int k=0;
	per(i,62,0){
		rep(j,k+1,n)if((a[j]>>i)&1){
			swap(a[++k],a[j]);
			wei[k]=i;
			break;
		}
		rep(j,k+1,n)if((a[j]>>i)&1)a[j]^=a[k];
	}
	if(k<n)flag=1;
	n=k;
}
void get(int w,LL k,LL&d){
	if(w>n)return;
	if((1<<(n-w))>=k){
		d=min(d,d^a[w]);
		get(w+1,k,d);
	}else{
		d=max(d,d^a[w]);
		get(w+1,k-(1<<(n-w)),d);
	}
}
int main(){
	int T;scanf("%d",&T);
	rep(cas,1,T){
		scanf("%d",&n);flag=0;
		rep(i,1,n)scanf("%lld",&a[i]);
		gauss();
		scanf("%d",&q);
		printf("Case #%d:\n",cas);
		rep(i,1,q){
			LL k;scanf("%lld",&k);
			if(!flag)++k;
			if(k>(1<<n))puts("-1");
			else{
				LL ans=0;get(1,k,ans);
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
