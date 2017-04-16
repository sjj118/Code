#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef unsigned long long UL;
UL rnd(){return ((UL)rand()<<32)+rand();}
const int N=150000+10;
int n,m,val[N];
struct Graph{
	int tot,head[N],to[N<<1],next[N<<1];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b){ins(a,b);ins(b,a);}
	UL s[N];
	bool check(){
		rep(k,1,n)for(int p=head[k];p;p=next[p])s[to[p]]^=val[k];
		for(int p=1;p<=tot;p+=2){
			if((s[to[p]]^s[to[p+1]])!=(val[to[p]]^val[to[p+1]]))return 0;
		}
		return 1;
	}
}G;
int main(){
	srand(20000107);
	scanf("%d%d",&n,&m);
	rep(i,1,n)val[i]=rnd();
	rep(i,1,m){int a,b;scanf("%d%d",&a,&b);G.addedge(a,b);}
	if(G.check())puts("YES");else puts("NO");
	return 0;
}
