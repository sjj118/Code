#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::sort;
const int N=2e5+10;
int n,m,a[N],ans[N],b[N],c[N];
bool cmp(int x,int y){return a[x]<a[y];}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)scanf("%d",&a[i]);
	rep(i,1,n+1)++c[a[i]];
	rep(i,1,m)c[i]+=c[i-1];
	per(i,n+1,1)b[c[a[i]]--]=i;
	int p=1;
	rep(i,1,n){
		p=b[p];
		ans[i]=a[b[p]];
	}
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}
