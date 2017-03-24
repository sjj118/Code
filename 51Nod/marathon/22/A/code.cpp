#include<cstdio>
#include<algorithm>
#include<assert.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::sort;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
const int N=1000+10;
int n,m[N],s[N][N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		m[i]=read();
		rep(j,1,m[i])s[i][j]=read();
		sort(s[i]+1,s[i]+1+m[i]);
	}
	int T;scanf("%d",&T);
	while(T--){
		int a,b,k;scanf("%d%d%d",&a,&b,&k);
		int ans=0;
		for(int i=1,j=1;;){
			if(i<=m[a]&&s[a][i]<=ans+1)ans=s[a][i]+ans,++i;
			else if(k){
				while(j+k<=m[b]&&s[b][j+1]<=ans+1)++j;
				if(j<=m[b]&&s[b][j]<=ans+1){
					ans=s[b][j]+ans;
				}else break;
				--k;
			}else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
