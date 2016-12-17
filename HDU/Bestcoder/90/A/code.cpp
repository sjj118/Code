#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int _K=50268147,_B=6082187,_P=100000007;
const int N=1e6+10;
int _X;
inline int get_rand(int _l,int _r){
	_X=((long long)_K*_X+_B)%_P;
	return _X%(_r-_l+1)+_l;
}
int n,m,k,seed;
int x[N],y[N];
void Init(){
	scanf("%d%d%d%d",&n,&m,&k,&seed);
	_X=seed;
	for (int i=1;i<=k;++i)
		x[i]=get_rand(1,n),
		y[i]=get_rand(1,m);
}
bool vx[N],vy[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		Init();
		cls(vx);cls(vy);
		rep(i,1,k)vx[x[i]]=1,vy[y[i]]=1;
		int ax=0,ay=0;
		rep(i,1,n)ax+=1-vx[i];
		rep(i,1,m)ay+=1-vy[i];
		printf("%d %d\n",ax,ay);
	}
	return 0;
}
