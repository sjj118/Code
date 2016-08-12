#include<iostream>
#include<cstdio>
#define pii pair<int,int> 
#define mp make_pair
#define fi first
#define se second
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=50000+10,mo=10007,maxk=510;
inline int power(int x,int y,int p){int a=1;for(;y;y>>=1,x=x*x%p)if(y&1)a=a*x%p;return a;}
inline void ck(int&x){x%=mo;if(x<0)x+=mo;}
inline void ad(int&x,int y){x+=y;ck(x);}
int n,K,init[maxk],map[maxk][maxk],ans[maxn];
struct Calc{
	int c[maxk];
	void clear(){
		rep(i,0,K)c[i]=init[i];
	}
	void output(){rep(i,0,K)cerr<<c[i]<<" ";cerr<<endl;}
}val[maxn];
Calc operator+(const Calc&a,const int&x){
	Calc b;
	per(i,K,1)b.c[i]=(a.c[i]+a.c[i-1])%mo;b.c[0]=a.c[0];
	return b;
}
Calc operator+(const Calc&a,const Calc&b){
	Calc c;
	rep(i,0,K)c.c[i]=(a.c[i]+b.c[i])%mo;
	return c;
}
Calc operator-(const Calc&a,const Calc&b){
	Calc c;
	rep(i,0,K)c.c[i]=a.c[i]-b.c[i],ck(c.c[i]);
	return c;
}
struct Graph{
	int tot,head[maxn],to[maxn<<1],next[maxn<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	pii q[maxn];
	int ql,qr;
	void bfs(){
		ql=qr=0;q[qr++]=mp(1,0);
		while(ql!=qr){
			int k=q[ql].fi,pre=q[ql++].se;
			val[k].clear();
			for(int p=head[k];p;p=next[p])if(to[p]!=pre){
				q[qr++]=mp(to[p],k);
			}
		}
		per(i,qr-1,0){
			int k=q[i].fi,pre=q[i].se;
			for(int p=head[k];p;p=next[p])if(to[p]!=pre){
				val[k]=val[k]+(val[to[p]]+1);
			}
		}
	}
	void solve(){
		ql=qr=0;q[qr++]=mp(1,0);
		while(ql!=qr){
			int k=q[ql].fi,pre=q[ql++].se;
			ans[k]=val[k].c[K];
			for(int p=head[k];p;p=next[p])if(to[p]!=pre){
				val[to[p]]=val[to[p]]+((val[k]-(val[to[p]]+1))+1);
				q[qr++]=mp(to[p],k);
			}
		}
	}
}G;
int main(){
	scanf("%d%d",&n,&K);int L;scanf("%d",&L);
	int now,A,B,Q;scanf("%d%d%d%d",&now,&A,&B,&Q);
	rep(i,1,n-1){
		now=(now*A+B)%Q;int tmp=(i<L)?i:L; 
		int u=i-now%tmp,v=i+1; 
		G.addedge(u,v);
	}
	if(K==0){rep(i,1,n)printf("%d\n",n);return 0;}
	rep(i,0,K)map[K][i]=power(i,K,mo);
	per(i,K-1,0)rep(j,0,i)map[i][j]=map[i+1][j+1]-map[i+1][j],ck(map[i][j]);
	rep(i,0,K)init[i]=map[i][0];//rep(i,1,n)val[i].clear();
	G.bfs();
	G.solve();
	rep(i,1,n)printf("%d\n",ans[i]);
	return 0;
}
