#include<iostream>
#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=2e5+10;
int n,m,a[N],b[N];
char t[N],p[N];
bool check(int x){
	for(int i=1,j=1;i<=m;++i){
		while(j<=n&&(b[j]<=x||t[j]!=p[i]))++j;
		if(j>n)return 0;
		++j;
	}
	return 1;
}
int main(){
	scanf("%s",t+1);n=strlen(t+1);
	scanf("\n%s",p+1);m=strlen(p+1);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)b[a[i]]=i;
	int l=0,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;else r=mid-1;
	}
	printf("%d",l);
	return 0;
}
