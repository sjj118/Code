#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=2e3+10;
typedef long long LL;
using namespace std;

char s[maxn];
int next[maxn][maxn],n,tw[maxn][maxn],sum[maxn];

int main(){
//	freopen("excellent.in","r",stdin);freopen("excellent.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		cls(s);cls(next);cls(tw);cls(sum);
		scanf("%s",s+1);n=strlen(s+1);
		rep(p,1,n){
			next[p][p]=p-1;
			for(int i=p+1,j=p-1;i<=n;++i){
				while(j>=p&&s[i]!=s[j+1])j=next[p][j];
				if(s[i]==s[j+1])++j;
				next[p][i]=j;
			}
		}
		rep(i,1,n)rep(j,i+1,n){
			if((j-i+1)%(j-next[i][j])==0&&((((j-i+1)/(j-next[i][j]))&1)==0))tw[i][j]=1;else tw[i][j]=0;
		}
		rep(i,1,n){
			sum[i]=0;
			rep(j,i+1,n)sum[i]+=tw[i][j];
		}
		LL ans=0;
		rep(i,1,n)rep(j,i+1,n)if(tw[i][j])ans+=sum[j+1];
		printf("%lld\n",ans);
	}
	return 0;
}
