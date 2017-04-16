#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<cstdlib>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int mo=1e9+7,N=300+10;
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
int n,m;
struct UFS{
	int pa[N],rank[N];
	void clear(){rep(i,1,n)pa[i]=i,rank[i]=0;}
	int find(int k){return pa[k]==k?k:pa[k]=find(pa[k]);}
	void unio(int a,int b){
		a=find(a);b=find(b);
		if(a==b)return;
		if(rank[a]>rank[b])swap(a,b);
		pa[a]=b;
		if(rank[a]==rank[b])++rank[b];
	}
}S;
struct Edge{
	int u,v;
}e[N][N];
bool w[N][N][N];
LL dp[2][N][N];
class TreeMoving {
public:
	int X[N];
	int count(int _n, vector <int> roots, vector <int> a, vector <int> b, vector <int> c) {
		n=_n;
		m=roots.size();
		rep(i,0,m-1){
			X[0]=c[i];
			rep(k,1,n-2)X[k]=(a[i]*X[k-1]+b[i])%mo;
			rep(j,0,n-2)e[i][j].u=(roots[i]+j+1)%n,e[i][j].v=(roots[i]+(X[j]%(j+1)))%n;
		}
		rep(i,0,m-1){
			rep(j,0,n-2){
				S.clear();
				rep(k,0,n-2)if(k!=j)S.unio(e[(i+1)%m][k].u,e[(i+1)%m][k].v);
				rep(k,0,n-2)if(S.find(e[i][k].u)!=S.find(e[i][k].v))w[i][k][j]=1;
			}
		}
		rep(i,0,n-1)dp[0][i][i]=1;
		rep(i,1,m-2){
			cls(dp[i&1]);
			rep(j,0,n-1)rep(k,0,n-1)ad(dp[i&1][j][k],);
		}
	}
};
int main(){
	return 0;
}
