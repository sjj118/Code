#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
inline bool vaild(char c){return c=='.'||c=='-'||c=='|'||c=='#';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n,m;
char a[N][N];
inline int ch(int d,int l,int r){
	return ((d|(3<<l)|(3<<r))^(3<<l)^(3<<r))|(((d>>l)&3)<<r)|(((d>>r)&3)<<l);
}
struct Hash{
	int tot,head[ha],next[N],key[N],
}hash[2];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)a[i][j]=gc();
	int x=0;
	rep(i,1,n){
		rep(j,1,m){
			hash[x^=1].clear();
			int l=(j-1)<<1,r=j<<1;
			rep(p,1,hash[x^1].tot){
				int d=hash[x^1].key[p],v=hash[x^1].val[p];
				if(a[i][j]=='#'){
					if(((d>>l)&1)==0&&((d>>r)&1)==0)hash[x][d]+=v;
				}else if(a[i][j]=='-'){
					if(((d>>l)&1)&&!((d>>r)&1))hash[x][ch(d,l,r)]+=v;
				}else if(a[i][j]=='|'){
					if(((d>>r)&1)&&!((d>>l)&1))hash[x][ch(d,l,r)]+=v;
				}else if(a[i][j]=='.'){
					if(((d>>l)&1)==0&&((d>>r)&1)==0)hash[x][d|(1<<l)|(2<<r)]+=v;
					else if(((d>>l)&1)&&((d>>r)&1))
				}
			}
		}
	}
	return 0;
}
