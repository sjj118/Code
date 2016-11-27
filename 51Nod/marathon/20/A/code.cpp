#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10,mo=1e9+7;
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
int n,k;
LL fact[N],_fact[N],inv[N],ans;
inline LL C(LL n,LL m){
	if(m>n)return 0;
	return fact[n]*_fact[m]%mo*_fact[n-m]%mo;
}
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1],size[N];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	void dfs(int k,int pre){
		size[k]=1;
		for(int p=head[k];p;p=next[p])if(to[p]!=pre){
			dfs(to[p],k);
			size[k]+=size[to[p]];
			ad(ans,C(n,::k)-C(size[to[p]],::k)-C(n-size[to[p]],::k),mo);
		}
	}
}G;
int main(){
	scanf("%d%d",&n,&k);
	inv[1]=1;rep(i,2,n)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
	fact[0]=1;rep(i,1,n)fact[i]=fact[i-1]*i%mo;
	_fact[0]=1;rep(i,1,n)_fact[i]=_fact[i-1]*inv[i]%mo;
	rep(i,1,n-1){int u,v;scanf("%d%d",&u,&v);G.addedge(u,v);}
	G.dfs(1,0);
	printf("%lld",ans);
	return 0;
}
