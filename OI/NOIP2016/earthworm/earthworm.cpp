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
namespace sjj118_brute{
	priority_queue<LL> heap;
	int main(){
		rep(i,1,n)heap.push(a[i]);
		rep(i,1,m){
			LL k=heap.top()+q*(i-1);heap.pop();
			if(i%t==0)printf("%lld ",k);
			LL x=u*k/v;
			heap.push(x-q*i);heap.push(k-x-q*i);
		}
		puts("");
		rep(i,1,n+m){
			if(i%t==0)printf("%lld ",heap.top()+q*m);
			heap.pop();
		}
		return 0;
	}
}
namespace sjj118_q0{
	const int A=1e7+10;
	int c[A];
	int main(){
		int high=A-1;
		rep(i,1,n)++c[a[i]];
		rep(i,1,m){
			while(c[high]==0)--c[high];
			if(i%t==0)printf("%lld ",k);
			LL x=u*k/v;
			heap.push(x-q*i);heap.push(k-x-q*i);
		}
		puts("");
		rep(i,1,n+m){
			if(i%t==0)printf("%lld ",heap.top()+q*m);
			heap.pop();
		}
		return 0;
	}
}
int main(){
	scanf("%d%d%lld%lld%lld%d",&n,&m,&q,&u,&v,&t);
	rep(i,1,n)scanf("%lld",&a[i]);
	if(q==0&&m>=1000000)return sjj118_q0::main();
	else return sjj118_brute::main(); 
}
