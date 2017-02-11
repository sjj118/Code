#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],na[N],nb[N];
int p1=1,p2=1;
void work(){
	if(p1>n)printf("%d ",b[p2++]);
	else if(p2>m)printf("%d ",a[p1++]);
	else if(a[p1]<b[p2])printf("%d ",a[p1++]);
	else if(b[p2]<a[p1])printf("%d ",b[p2++]);
	else if(a[p1]==b[p2]){
		int l1=na[p1],l2=nb[p2];
		bool f1=l1<=n&&a[l1]<a[p1],f2=l2<=m&&b[l2]<b[p2];
		if(f1&&f2){
			if(l1-p1<l2-p2){
				while(p1<l1)printf("%d ",a[p1++]);
			}
			if(l1-p1>l2-p2){
				while(p2<l2)printf("%d ",b[p2++]);
			}
			if(l1-p1==l2-p2){
				if(a[l1]<b[l2]){
					while(p1<l1)printf("%d ",a[p1++]);
				}else{
					while(p2<l2)printf("%d ",b[p2++]);
				}
			}
		}
		if(f1==1&&f2==0){
			while(p1<l1)printf("%d ",a[p1++]);
		}
		if(f1==0&&f2==1){
			while(p2<l2)printf("%d ",b[p2++]);
		}
		if(f1==0&&f2==0){
			while(p1<l1)printf("%d ",a[p1++]);
		}
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	scanf("%d",&m);
	rep(i,1,m)scanf("%d",&b[i]);
	per(i,n,1)na[i]=a[i+1]!=a[i]?i+1:na[i+1];
	per(i,m,1)nb[i]=b[i+1]!=b[i]?i+1:nb[i+1];
	while(p1<=n||p2<=m){
		work();
	}
	return 0;
}
