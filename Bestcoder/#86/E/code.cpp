#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ls son[0]
#define rs son[1]
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
const int maxn=1e5+10,mo=0;
using namespace std;
inline char gc(){char c=getchar();while(!(c>='0'&&c<='9'))c=getchar();return c;}
inline LL read(){LL tmp=0;char c=gc();while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();return tmp;}
struct Node *null;
struct Node{
	Node *pa,*son[2];
	int val;
	Node(){pa=ls=rs=null;}
}T[maxn];
int main(){
	int T=read();
	while(T--){
		
	}
	return 0;
}
