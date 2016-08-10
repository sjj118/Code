#include<iostream>
#include<cstdio>
#include<algorithm>
#define lowbit(x) x&(-x)
#define maxn 2000
#define maxm 2000
#define inf 1e9

using namespace std;

int n;
int mat[maxn][maxn];

int main(){
	freopen("code.in","r",stdin);
	freopen("brute.out","w",stdout);
	scanf("%d",&n);
	int op;
	while(scanf("%d",&op)>0&&op!=3){
		if(op==1){
			int x,y,a;
			scanf("%d%d%d",&x,&y,&a);
			mat[x][y]+=a;
		}else{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int ans=0;
			for(int i=x1;i<=x2;++i){
				for(int j=y1;j<=y2;++j)ans+=mat[i][j];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
