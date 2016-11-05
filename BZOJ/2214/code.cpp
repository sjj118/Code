#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=2000+10,M=N*N;
int n,m,head,a[N],tmp[N];
inline int cw(int x){if(x<=0)x+=n;if(x>n)x-=n;return x;}
struct Query{
	int k,t;
	Query(){k=t=-1;}
	Query(int _k,int _t){k=_k;t=_t;}
	void output(){printf("%d%c ",k,'a'+t);}
}q[M];
void output(){
	rep(i,head,n)printf("%d ",a[i]);
	rep(i,1,head-1)printf("%d ",a[i]);
	puts("");
}
void kt(int k,int t){
	if(t==0)k%=n;else k%=3;
	if(k==0)return;
	if(q[m].t==t)q[m].k+=k;
	else q[++m]=Query(k,t);
	if(q[m].t==0)q[m].k%=n;else q[m].k%=3;
	if(q[m].k==0)--m;
	if(t==1){
		rep(i,1,k)swap(a[cw(head+2)],a[cw(head+1)]),swap(a[cw(head+1)],a[head]);
	}else head=cw(head-k);
//	output();
}
void mh(int x){
	if(x==head)return;
	kt(cw(head-x),0);
}
int nx1(int x){
	mh(cw(x-1));
	kt(1,1);
	return cw(x+1);
}
int nx2(int x){
	mh(x);
	kt(2,1);
	return cw(x+2);
}
int nxn(int n,int x){
	while(n>=2)n-=2,x=nx2(x);
	if(n)x=nx1(x);
	return x;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&tmp[i]);
	rep(i,1,n)if(tmp[i]==n)head=n-i+1;
	rep(i,head,n)a[i]=tmp[i-head+1];
	rep(i,1,head-1)a[i]=tmp[n-head+i+1];
//	printf("%d\n",head);
//	rep(i,1,n)printf("%d ",a[i]);
	per(i,n-1,3){
		int x;
		rep(j,1,n)if(a[j]==i)x=j;
		nxn(i-x,x);
	}
	if(a[1]!=1&&n%2==1)puts("NIE DA SIE");
	else{
		if(a[1]!=1)nxn(n-2,2);
		int x;
		rep(i,1,n)if(a[i]==1)x=i;
		mh(x);
		printf("%d\n",m);
		rep(i,1,m)q[i].output();
	}
	return 0;
}
}
int main(){
	freopen("shift.in","r",stdin);freopen("shift.out","w",stdout);
	return sjj118::main();
}
