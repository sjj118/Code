#include<bits/stdc++.h>
#define ls son[k][0]
#define rs son[k][1]
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=4e5+10;
int a[N];
struct Tree{
	int rt,tot,son[N][2],val[N];
	int merge(int x,int y){
		val[++tot]=0;
		son[tot][0]=x;son[tot][1]=y;
		return tot;
	}
	void build(int n){
		rep(i,1,n)val[++tot]=i;
		per(i,n,2){
			a[i-1]=merge(a[i],a[i-1]);
			swap(a[i-1],a[rand()%(i-1)+1]);
		}
		rt=a[1];
	}
	void output(int k){
		printf("%d\n",val[k]);
		if(!val[k])output(ls),output(rs);
	}
}G;
int main(){
	freopen("seed.txt","r",stdin);int seed;scanf("%d",&seed);
	freopen("seed.txt","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
//	int n=rand()%200000+1;
	int n=200;
	printf("%d\n",n);
	rep(i,1,n)a[i]=i;
	random_shuffle(a+1,a+1+n);
	G.build(n);
	G.output(G.rt);
	return 0;
}
