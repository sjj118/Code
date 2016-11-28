#include<iostream>
#include<cstdio>
#include<queue>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n,m,t;
LL q,u,v,a[N];
inline void output(LL x){
	int a[20],l=0;
	while(x)a[++l]=x%10,x/=10;
	if(l==0)putchar('0');
	per(i,l,1)putchar(a[i]+'0');
	putchar(' ');
}
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline LL read(){LL ret=0;char c=gc();while(vaild(c))ret=ret*10+c-'0',c=getchar();return ret;}
namespace sjj118_brute{
priority_queue<LL> heap;
int main(){
	rep(i,1,n)heap.push(a[i]);
	rep(i,1,m){
		LL k=heap.top()+q*(i-1);heap.pop();
		if(i%t==0)output(k);
		LL x=u*k/v;
		heap.push(x-q*i);
		heap.push(k-x-q*i);
	}
	puts("");
	rep(i,1,n+m){
		if(i%t==0)output(heap.top()+q*m);
		heap.pop();
	}
	return 0;
}
}
namespace sjj118_q0{
	const int A=1e7+10;
	int c[A],high;
	int main(){
		high=A-1;
		rep(i,1,n)++c[a[i]];
		rep(i,1,m){
			while(c[high]==0)--high;
			--c[high];
			LL x=u*high/v;
			++c[x];++c[high-x];
			if(i%t==0)output(high);
		}
		puts("");
		rep(i,1,n+m){
			while(c[high]==0)--high;
			--c[high];
			if(i%t==0)output(high);
		}
		return 0;
	}
}
int main(){
	freopen("earthworm.in","r",stdin);freopen("earthworm.out","w",stdout);
	scanf("%d%d%lld%lld%lld%d",&n,&m,&q,&u,&v,&t);
	rep(i,1,n)a[i]=read();
	if(q==0&&m>=100000)return sjj118_q0::main();
	else return sjj118_brute::main();
}
