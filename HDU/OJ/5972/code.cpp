#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=1000+10,M=5e6+10;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n,a[N][10],b[M],m,next[N];
inline bool cmp(int x,int y){
	rep(i,0,9)if(a[x][i]&&a[y][i])return 1;
	return 0;
}
int main(){
	while(scanf("%d",&n)>0){
		cls(a);
		rep(i,1,n){
			int x;scanf("%d",&x);
			rep(j,1,x)a[i][gc()-'0']=1;
		}
		char c=gc();m=0;
		while(vaild(c))b[++m]=c-'0',c=getchar();
		next[1]=0;
		for(int i=2,j=0;i<=n;++i){
			while(j&&!cmp(i,j+1))j=next[j];
			if(cmp(i,j+1))++j;
			next[i]=j;
		}
		for(int i=1,j=0;i<=m;++i){
			while(j&&!a[j+1][b[i]])j=next[j];
			if(a[j+1][b[i]])++j;
			if(j==n){rep(k,i-n+1,i)putchar(b[k]+'0');puts("");j=next[j];}
		}
	}
	return 0;
}
}
int main(){
	return sjj118::main();
}
