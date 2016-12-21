#include<bits/stdc++.h>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=0,inf=1e9,mo=0;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
int sg[1000],vis[110];
void brutesg(){
	sg[1]=0;
	rep(i,2,100){
		cls(vis);
		rep(j,1,i-1)vis[sg[j]^sg[i-j]]=1;
		rep(j,0,1000)if(!vis[j]){sg[i]=j;break;}
	}
}
int n;
int getsg(int x){return x&1^1;}
int main(){
	int tmp=0;
	n=read();
	rep(i,1,n){
		int x=read();
		tmp^=getsg(x);
		printf("%d\n",2-tmp);
	}
	return 0;
}
