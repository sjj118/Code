#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2e5+10;
int n,m,a[N],num[2],flag;
map<int,int> s;
int findnext(int p){
	while(s.count(num[p]))num[p]+=2;
	if(num[p]>m)flag=1;
	return num[p];
}
int main(){
	num[0]=2;num[1]=1;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	int num=0;
	rep(i,1,n)num+=a[i]&1;
	int p,t=0;
	if(num*2>n)p=1;else p=0;
	t=abs(n/2-num);
	int ans=0;
	rep(i,1,n){
		if(s.count(a[i])){
			if((a[i]&1)==p&&t)a[s[a[i]]]=findnext(p^1),--t;
			else a[s[a[i]]]=findnext(a[i]&1);
			s[a[s[a[i]]]]=s[a[i]];
			++ans;
		}
		s[a[i]]=i;
	}
	rep(i,1,n)if(t&&(a[i]&1)==p){
		s.erase(a[i]);
		++ans;
		a[i]=findnext(p^1);
		s[a[i]]=i;
		--t;
	}
	if(flag)puts("-1");
	else{
		printf("%d\n",ans);
		rep(i,1,n)printf("%d ",a[i]);
	}
	return 0;
}
