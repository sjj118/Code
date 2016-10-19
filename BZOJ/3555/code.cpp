#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define phh pair<LL,LL>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef unsigned long long LL;
const int maxn=3e4+10,maxl=200+10,alp=64,base=131;
inline int cw(char c){
	if(c>='0'&&c<='9')return c-'0';
	if(c>='a'&&c<='z')return c-'a'+10;
	if(c>='A'&&c<='Z')return c-'A'+36;
	if(c=='_')return 62;
	if(c=='@')return 63;
	return -1;
}
int n,l,s;
int a[maxn][maxl];
LL P[maxn][maxl],S[maxn][maxl];
const int ha=23333;
struct HashMap{
	int tot,head[ha],val[maxn],next[maxn];
	phh key[maxn];
	int h(phh x){
		return (131131ll*x.fi+x.se)%ha;
	}
	int ins(phh k){
		key[++tot]=k;
		int a=h(k);
		next[tot]=head[a];head[a]=tot;
		return tot;
	}
	int find(phh k){
		int a=h(k);
		for(int p=head[a];p;p=next[p])if(key[p]==k)return p;
		return -1;
	}
	void inc(phh k){
		int t=find(k);
		if(t==-1)t=ins(k);
		++val[t];
	}
	void clear(){tot=0;cls(head);cls(val);}
}hm;
int main(){
	scanf("%d%d%d",&n,&l,&s);
	rep(i,1,n){
		rep(j,1,l){
			int t=cw(getchar());
			while(t==-1)t=cw(getchar());
			a[i][j]=t;
		}
	}
	rep(i,1,n){
		rep(j,1,l)P[i][j]=P[i][j-1]*base+a[i][j];
		per(j,l,1)S[i][j]=S[i][j+1]*base+a[i][j];
	}
	int ans=0;
	rep(i,1,l){
		hm.clear();
		rep(j,1,n)hm.inc(mp(P[j][i-1],S[j][i+1]));
		rep(j,1,hm.tot)ans+=hm.val[j]*(hm.val[j]-1)/2;
	}
	printf("%d",ans);
	return 0;
}
