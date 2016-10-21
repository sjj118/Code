#include<iostream>
#include<cstdio>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,maxm=1e6+10,maxq=1e5+10;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
int n,m,q;
struct Edge{
	int x,y,t;
	Edge(){x=y=t=0;}
	Edge(int x,int y,int t){this->x=x;this->y=y;this->t=t;}
}e[maxm];
bool operator<(const Edge&a,const Edge&b){return a.t<b.t;}
struct Operation{
	int k,x,y,ans;
	Operation(){k=x=y=0;}
	Operation(int k,int x,int y){this->k=k;this->x=x;this->y=y;}
}o[maxq];
const int ha=2333333;
struct HashMap{
	int tot,head[ha],next[maxq<<1];
	pii key[maxq<<1];
	int h(pii a){return (a.fi*13131+a.se)%ha;}
	int ins(pii a){key[++tot]=a;int x=h(a);next[tot]=head[x];head[x]=tot;return tot;}
	int find(pii k){for(int p=head[h(k)];p;p=next[p])if(key[p]==k)return p;return 0;}
}fake;
struct UFS{
	int pa[maxn],rank[maxn];
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	bool unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return 0;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
		return 1;
	}
}S;
struct LCT{

}T;
int main(){
	n=read();m=read();q=read();
	rep(i,1,m)e[i]=Edge(read(),read(),read());
	rep(i,1,q)o[i]=Operation(read(),read(),read());
	rep(i,1,q)if(o[i].k==2)fake.ins(mp(o[i].x,o[i].y));
	sort(e+1,e+1+m);
	rep(i,1,m)if(!fake.find(mp(e[i].x,e[i].y))&&!fake.find(mp(e[i].y,e[i].x))&&S.unio(e[i].x,e[i].y))T.link(e[i].x,n+i),T.link(n+i,e[i].y);
	return 0;
}
