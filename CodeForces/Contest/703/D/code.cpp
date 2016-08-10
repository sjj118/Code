#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=1e6+10,ha=233333;
typedef long long LL;
using namespace std;
int n,m,a[maxn],next[maxn],sum[maxn],ans[maxn];
struct Query{
	int l,r,pos,ans;
}q[maxn];
bool operator<(Query a,Query b){return a.l<b.l;}
struct Hash{
	int tot,key[maxn],val[maxn],next[maxn],head[ha];
	void ins(int a,int b){
		int k=a%ha;
		for(int p=head[k];p;p=next[p])if(key[p]==a){val[p]=b;return;}
		val[++tot]=b;next[tot]=head[k];head[k]=tot;key[tot]=a;
	}
	int get(int a){
		int k=a%ha;
		for(int p=head[k];p;p=next[p])if(key[p]==a)return val[p];
		return n+1;
	}
}hash;
inline int lowbit(int x){return x&(-x);}
struct Bit{
	int arr[maxn];
	void add(int x,int t){
		for(;x<=n;x+=lowbit(x))arr[x]^=t;
	}
	int sum(int x){
		int tmp=0;
		for(;x;x-=lowbit(x))tmp^=arr[x];
		return tmp;
	}
}bit;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
	scanf("%d",&m);
	rep(i,1,m)scanf("%d%d",&q[i].l,&q[i].r),q[i].pos=i;
	sort(q+1,q+1+m);
	per(i,n,1){
		next[i]=hash.get(a[i]);
		bit.add(next[i],a[i]);bit.add(i,a[i]);
		hash.ins(a[i],i);
	}
	int j=1;
	rep(i,1,n){
		while(j<=m&&q[j].l==i)q[j].ans=sum[i-1]^sum[q[j].r]^bit.sum(q[j].r),++j;
		bit.add(i,a[i]);bit.add(next[i],a[i]);
	}
	rep(i,1,m)ans[q[i].pos]=q[i].ans;
	rep(i,1,m)printf("%d\n",ans[i]);
	return 0;
}
