#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
//#include<ctime>
#define ptime //cerr<<clock()<<endl
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
typedef long long LL;
const int N=1e5+10,V=1<<6;
int n,k,co[V],v,c[N];
struct Year{
	int v[6];
}a[N];
bool operator==(const Year&a,const Year&b){
	rep(i,0,5)if((v>>i)&1)if(a.v[i]!=b.v[i])return 0;
	return 1;
}
const int ha=2333333;
struct Hash{
	Year key[N];
	int tot,head[ha],val[N],next[N];
	int h(const Year&a){
		LL ret=0;
		rep(i,0,5)if((v>>i)&1)ret=(ret*131+a.v[i])%ha;
		return ret;
	}
	void ins(const Year&k){key[++tot]=k;int a=h(k);next[tot]=head[a];head[a]=tot;val[tot]=1;}
	int find(const Year&k){for(int p=head[h(k)];p;p=next[p])if(key[p]==k)return p;return 0;}
	void add(const Year&k){
		int t=find(k);
		if(t)++val[t];
		else ins(k);
	}
	void clear(){tot=0;cls(head);}
	LL count(){
		LL ret=0;
		rep(i,1,tot)ret+=(LL)val[i]*(val[i]-1)/2;
		return ret;
	}
}hash;
LL f[7],g[7],C[7][7];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)rep(j,0,5)scanf("%d",&a[i].v[j]);
	ptime;
	rep(i,0,6){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	rep(i,1,V-1)co[i]=co[i>>1]+(i&1);
	ptime;
	for(v=0;v<V;++v)if(co[v]>=k){
		hash.clear();
		rep(i,1,n)hash.add(a[i]);
		f[co[v]]+=hash.count();
	}
	ptime;
	per(i,6,0){
		g[i]=f[i];
		rep(j,i+1,6)g[i]-=g[j]*C[j][i];
	}
	printf("%lld",g[k]);
	return 0;
}
}
int main(){
//	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
