#include<iostream>
#include<cstdio>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
inline int lowbit(int x){return x&(-x);}
inline void ck(int&x,int p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(int&x,int y,int p){x+=y;ck(x,p);}
const int maxn=16,maxv=32768+10,maxl=50+5,mo=1e6+3;
int n,k,l,v;
char s[maxv][maxl];
int dp[maxv];
int dfs(int p,int last,int v){
	if(p==k)return dp[v];
	int ans=0;
	rep(i,last+1,n)ad(ans,dfs(p+1,i,v|(1<<(i-1))),mo);
	return ans;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);v=1<<n;
		rep(i,0,n-1)scanf("%s",s[1<<i]+1);
		l=strlen(s[1]+1);
		rep(i,1,l)s[0][i]='?';s[0][l+1]='\0';
		rep(i,2,v-1)if(i-lowbit(i)){
			int a=lowbit(i),b=i-a;
			rep(j,1,l)if(s[a][j]==s[b][j])s[i][j]=s[a][j];
			else if(s[a][j]=='?')s[i][j]=s[b][j];
			else if(s[b][j]=='?')s[i][j]=s[a][j];
			else s[i][j]=0;
		}
		rep(i,0,v-1){
			dp[i]=1;rep(j,1,l)if(s[i][j]=='?')dp[i]=dp[i]*26%mo;else if(s[i][j]==0)dp[i]=0;
		}
		per(i,v-1,0)for(int j=i;j;j=(j-1)&i)ad(dp[i^j],-dp[i],mo);
		printf("%d\n",dfs(0,0,0));
	}
}
