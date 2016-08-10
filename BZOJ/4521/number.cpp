#include<iostream>
#include<cstdio>
#define maxn 12
#define LL long long

using namespace std;

int L[maxn],R[maxn],dp[maxn][maxn][maxn][2][4][4];
void getnum(int*a){
	char c=getchar();int tmp=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')a[++tmp]=c-'0',c=getchar();
}
int s48(int x){
	if(x==4)return 1;
	if(x==8)return 2;
	return 0;
}
int bes(int k,int x){
	int tmp=0;
	if(L[k]==x)tmp|=1;
	if(R[k]==x)tmp|=2;
	return tmp;
}
int newl(int l,int a,int b){
	if(a==b)return l+1;
	return 1;
}

int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	getnum(L);getnum(R);
	for(int i=L[1];i<=R[1];++i){
		dp[1][i][1][0][s48(i)][bes(1,i)]=1;
	}
	for(int i=1;i<=10;++i){
		for(int j=0;j<=9;++j)if(i>1||j){
			for(int k=1;k<=i;++k){
				for(int l=0;l<=1;++l){
					for(int t48=0;t48<4;++t48){
						for(int b=0;b<4;++b)if(dp[i][j][k][l][t48][b]){
							int bl=0,br=9;
							if(b==1)bl=L[i+1];
							if(b==2)br=R[i+1];
							if(b==3)bl=L[i+1],br=R[i+1];
							for(int c=bl;c<=br;++c){
								dp[i+1][c][newl(k,j,c)][l|(newl(k,j,c)==3)][t48|s48(c)][b&bes(i+1,c)]+=dp[i][j][k][l][t48][b];
							}
						}
					}
				}
			}
		}
	}
	LL ans=0;
	for(int i=0;i<=9;++i)for(int j=1;j<=11;++j)for(int k=0;k<=2;++k)for(int b=0;b<=3;++b)ans+=dp[11][i][j][1][k][b];
	printf("%lld",ans);
	return 0;
}
