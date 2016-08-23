#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=12,maxv=1e6,ha=30007;
int map[maxn][maxn];
LL val[2][maxv];
struct Hash{
	int id,tot,head[ha],key[maxv],next[maxv];
	void clear(){tot=0;cls(head);}
	void ins(int a,LL b){key[++tot]=a;a%=ha;next[tot]=head[a];head[a]=tot;val[id][tot]=b;}
	int find(int a){for(int p=head[a%ha];p;p=next[p])if(key[p]==a)return p;return 0;}
	void add(int a,LL b){
		int t=find(a);
		if(t)val[id][t]+=b;
		else ins(a,b);
	}
}q[2];
int another(int k,int p){
	int kind=(k>>p)&3,cnt=1;
	while(cnt){if(kind==1)p+=2;else p-=2;if(((k>>p)&3)==kind)++cnt;else if(((k>>p)&3)==(kind^3))--cnt;}
	return p;
}
void output(int x){
	while(x)printf("%d",x&3),x>>=2;puts("");
}
int main(){
	int T;scanf("%d",&T);
	q[0].id=0;q[1].id=1;
	rep(cas,1,T){
		int n,m;scanf("%d%d",&n,&m);
		rep(i,1,n)rep(j,1,m)scanf("%d",&map[i][j]);
		int v=1<<((m+1)<<1);
		int x=0;q[x].clear();q[x].add(0,1);
		rep(i,1,n){
			rep(j,1,m){
				x^=1;q[x].clear();int l=(j-1)<<1,r=j<<1;
				rep(p,1,q[x^1].tot){
					int k=q[x^1].key[p];LL d=val[x^1][p];
					if(!((k>>l)&3)&&!((k>>r)&3)){
						if(map[i][j])q[x].add(k|(1<<l)|(2<<r),d);
						else q[x].add(k,d);
					}else if(!map[i][j])continue;
					else if(((k>>l)&3)&&((k>>r)&3)){
						if(((k>>l)&3)!=((k>>r)&3))q[x].add((k|(3<<l)|(3<<r))^(3<<l)^(3<<r),d);
						else if(((k>>l)&3)==1&&((k>>r)&3)==1)q[x].add((k|(3<<l)|(3<<r))^(3<<l)^(3<<r)^(3<<another(k,r)),d);
						else q[x].add((k|(3<<l)|(3<<r))^(3<<l)^(3<<r)^(3<<another(k,l)),d);
					}else{
						q[x].add(k,d);
						q[x].add((k|(3<<l)|(3<<r))^(3<<l)^(3<<r)^((k&(3<<l))<<2)^((k&(3<<r))>>2),d);
					}
				}
			}
			x^=1;q[x].clear();
			rep(p,1,q[x^1].tot)if((q[x^1].key[p]<<2)<v)q[x].add(q[x^1].key[p]<<2,val[x^1][p]);
		}
		printf("Case %d: There are %lld ways to eat the trees.\n",cas,val[x][q[x].find(0)]);
	}
	return 0;
}
