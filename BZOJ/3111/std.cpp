#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define inf 1000000000

const int maxn=120;
int n,m,k,ans,a[maxn][maxn],f[maxn][25][maxn],g[maxn][25][maxn][2],s[maxn][maxn];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    k=k*2+1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]),s[i][j]=s[i-1][j]+a[i][j];
	for (int i=1;i<=k;i++)
		for (int j=1;j<=n;j++)
			f[0][i][j]=g[0][i][j][0]=g[0][i][j][1]=-inf;
	ans=-inf;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			for (int p=1;p<=k;p++){
				for (int h=i;h;h--)
					f[j][p][h]=max(f[j-1][p][h],g[j-1][p-1][h][p%2])+s[i][j]-s[h-1][j];
				g[j][p][1][0]=-inf;
				for (int h=2;h<=i;h++)			
					g[j][p][h][0]=max(g[j][p][h-1][0],f[j][p][h-1]);
				g[j][p][i][1]=-inf;
	   			for (int h=i-1;h;h--)
	   				g[j][p][h][1]=max(g[j][p][h+1][1],f[j][p][h+1]);
			}
			ans=max(ans,max(f[j][k][i],g[j][k][i][0]));
		}
    printf("%d",ans);
	return 0;
}
