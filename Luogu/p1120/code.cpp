#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=70;
int n,a[maxn],suml,l;
bool vis[maxn];
bool f[3500];
bool quickcheck(int b,int l){
	rep(i,1,l)f[i]=0;f[0]=1;
	rep(i,b,n)if(!vis[i]&&l>=a[i]){
		rep(j,0,l-a[i])if(f[j])f[j+a[i]]=1;
	}
	return f[l];
}
bool dfs(int mu,int last,int r){
	if(mu==0)return 1;
	if(r==0){
		rep(i,1,n)if(!vis[i]){vis[i]=1;quickcheck(i+1,l-a[i]);int t=dfs(mu-1,i,l-a[i]);vis[i]=0;return t;}
		return 1;
	}
	if(f[r]==0)return 0;
	rep(i,last+1,n)if(!vis[i]){
		if(a[i]>r)break;
		vis[i]=1;
		if(dfs(mu,i,r-a[i]))return 1;
		vis[i]=0;
	}
	return 0;
}
bool check(int a){
	l=a;quickcheck(1,l);
	if(dfs(suml/l,0,l))return 1;
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;){
		scanf("%d",&a[i]);
		if(a[i]>50)--n;else ++i;
	}
	rep(i,1,n)suml+=a[i];
	sort(a+1,a+1+n);
	rep(l,a[n],suml)if(suml%l==0){
		if(check(l)){printf("%d",l);break;}
	}
	return 0;
}
