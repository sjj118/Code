#include<iostream>
#include<cstdio>
#include<cstring>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int n,m;
char s[N],t[N];
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",t+1);m=strlen(t+1);
		rep(i,1,m-1)t[i+m]=t[i];
		int ans=0;
		rep(i,1,n-m+1){
			rep(j,1,m){
				bool flag=1;
				rep(k,0,m-1)if(s[i+k]!=t[j+k])flag=0;
				if(flag){++ans;break;}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
