#include<bits/stdc++.h>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=3e5+10,inf=1e9,mo=0;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,q,mt,t;
int head[maxn],next[maxn],to[maxn],tot;
void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
inline int lowbit(int x){return x&(-x);}
struct Bit{
	int arr[maxn];
	void add(int x,int t){
		for(;x<=q;x+=lowbit(x))arr[x]+=t;
	}
	int get(int x){
		int tmp=0;
		for(;x;x-=lowbit(x))tmp+=arr[x];
		return tmp;
	}
}bit;
int main(){
	n=read();q=read();
	rep(i,1,q){
		int type=read(),x=read();
		if(type==1)ins(x,++t),bit.add(t,1);
		if(type==2){for(int p=head[x];p;p=next[p])bit.add(to[p],-1);head[x]=0;}
		if(type==3)mt=max(mt,x);
		printf("%d\n",bit.get(t)-bit.get(mt));
	}
	return 0;
}
