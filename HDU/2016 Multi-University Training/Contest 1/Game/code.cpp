#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int maxn=1e3+10;
char map[maxn][maxn];
LL sum[maxn][maxn],col[maxn],row[maxn];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,m;scanf("%d%d",&n,&m);
		rep(i,1,n)scanf("\n%s",map[i]+1);
		rep(i,1,n)rep(j,1,m)sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(map[i][j]=='#');
		cls(row);cls(col);LL ans=0;
		rep(i,1,n)rep(j,1,m)if(map[i][j]=='#')ans+=i*(sum[i-1][m]-sum[n][m]+sum[i][m])+j*(sum[n][j-1]-sum[n][m]+sum[n][j]);
		rep(i,1,n)rep(j,1,m)if(map[i][j]=='G')row[i]=j,col[j]=i;
		for(int l=1,r=0;l<=n;++l){
			LL tmp=0;
			while(r<l||r<n&&row[r+1]>row[r]){
				++r;tmp+=sum[r][row[r]]-sum[r-1][row[r]];
				ans+=2*tmp*(sum[r][m]-sum[r][row[r]]-sum[r-1][m]+sum[r-1][row[r]]);
			}
		}
		for(int l=1,r=0;l<=n;++l){
			LL tmp=0;
			while(r<l||r<n&&row[r+1]<row[r]){
				++r;ans+=2*tmp*(sum[r][row[r]]-sum[r-1][row[r]]);
				tmp+=sum[r][m]-sum[r][row[r]]-sum[r-1][m]+sum[r-1][row[r]];
			}
		}
		for(int l=1,r=0;l<=m;++l){
			LL tmp=0;
			while(r<l||r<m&&col[r+1]>col[r]){
				++r;tmp+=sum[col[r]][r]-sum[col[r]][r-1];
				ans+=2*tmp*(sum[n][r]-sum[col[r]][r]-sum[n][r-1]+sum[col[r]][r-1]);
			}
		}
		for(int l=1,r=0;l<=m;++l){
			LL tmp=0;
			while(r<l||r<m&&col[r+1]<col[r]){
				++r;ans+=2*tmp*(sum[col[r]][r]-sum[col[r]][r-1]);
				tmp+=(sum[n][r]-sum[col[r]][r]-sum[n][r-1]+sum[col[r]][r-1]);
			}
		}
		printf("%.4lf\n",ans*2.0/sum[n][m]/sum[n][m]);
	}
	return 0;
}
