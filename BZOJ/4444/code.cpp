#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 610000
#define inf 1000000070

using namespace std;
struct Soilder{
	int l,r,id,f;
}a[maxn];
bool comp(Soilder a,Soilder b){
	return a.l<b.l;
}
struct Lisan{
	int x,id;
}li[maxn<<1];
bool comp2(Lisan a,Lisan b){
	return a.x<b.x;
}
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;
	sort(a+1,a+1+n,comp);
	for(int i=1;i<=n;++i)li[i*2-1].x=a[i].l,li[i*2-1].id=i*2-1,li[i*2].x=a[i].r,li[i*2].id=i*2;
	sort(li+1,li+1+n*2,comp2);m=0;li[0].x=-inf;
	for(int i=1;i<=n*2;++i){
		if(li[i].x>li[i-1].x)++m;
		if(li[i].id&1)a[li[i].id/2+1].l=m;
		else a[li[i].id/2].r=m;
	}
	for(int i=1;i<=n;++i)if(a[i].r<=a[i].l)a[i].r+=m;
	for(int i=1;i<=n;++i)a[i+m].l=a[i].l+m,a[i+m].r=a[i].r+m,a[i+m+m].l=a[i].l+m+m,a[i+m+m].r=a[i].r+m+m;
	
	return 0;
}
