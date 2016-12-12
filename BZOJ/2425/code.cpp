#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=50+5;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int a[N],b[N],l;
LL C[N][N];
int main(){
	char c=gc();
	while(vaild(c))++b[a[++l]=c-'0'],c=getchar();
	rep(i,0,l){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	LL ans=0;
	rep(i,1,l){
		rep(j,0,a[i]-1)if(b[j]){
			--b[j];
			int t=l-i;
			LL tmp=1;
			rep(k,0,9)tmp*=C[t][b[k]],t-=b[k];
			ans+=tmp;
			++b[j];
		}
		--b[a[i]];
	}
	printf("%lld",ans);
	return 0;
}
