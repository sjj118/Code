#include<iostream>
#include<cstdio>
#define maxc 110
#define maxn 310
#define lowbit(x) x&(-x)

using namespace std;

int n,m,q,a[maxn][maxn];
struct Bit{
	int arr[maxn][maxn];
	void add(int x,int y,int t){
		for(int i=x;i<=n;i+=lowbit(i))
			for(int j=y;j<=m;j+=lowbit(j))arr[i][j]+=t;
	}
	int sum(int x,int y){
		int tmp=0;
		for(int i=x;i;i-=lowbit(i))
			for(int j=y;j;j-=lowbit(j))tmp+=arr[i][j];
		return tmp;
	}
}bit[maxc];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
		int c;scanf("%d",&c);
		bit[c].add(i,j,1);a[i][j]=c;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int op;scanf("%d",&op);
		if(op==1){
			int x,y,c;scanf("%d%d%d",&x,&y,&c);
			bit[a[x][y]].add(x,y,-1);a[x][y]=c;
			bit[c].add(x,y,1);
		}else{
			int x1,x2,y1,y2,c;scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&c);
			printf("%d\n",bit[c].sum(x2,y2)-bit[c].sum(x1-1,y2)-bit[c].sum(x2,y1-1)+bit[c].sum(x1-1,y1-1));
		}
	}
	return 0;
}
