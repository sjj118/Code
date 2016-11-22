#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=3000+10;
int n,m,w[N][N];
bool del[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int u,v;scanf("%d%d",&u,&v);w[u][v]=w[v][u]=1;}
	rep(i,1,n)if(!del[i])rep(j,1,n)if(i!=j&&!del[j]&&!w[i][j]){del[i]=del[j]=1;break;}
	int cnt=0;
	rep(i,1,n)if(!del[i]){
		printf("%d ",i);
		if(++cnt==n/3)break;
	}
	return 0;
}
