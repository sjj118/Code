#include<bits/stdc++.h>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=0,inf=1e9,mo=0;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n;
void work(int k){
	if(k&1)printf("I hate ");else printf("I love ");
	if(k==n){printf("it");return;}
	else printf("that ");
	work(k+1);
}
int main(){
	n=read();
	work(1);
	return 0;
}
