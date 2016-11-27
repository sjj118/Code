#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e6+10;
int n,m,a[N];
char s[N];
int main(){
	scanf("%d%d",&n,&m);
	scanf("\n%s",s+1);
	rep(i,1,n)if(s[i]=='W')a[i]=1;else a[i]=2;
	while(m--){
		int q;scanf("%d",&q);
		bool flag=0;
		for(int l=1,r=0,sum=0;l<=n;sum-=a[l++]){
			while(r<n&&sum<q)sum+=a[++r];
			if(sum==q){
				flag=1;
				printf("%d %d\n",l,r);
				break;
			}
		}
		if(!flag)puts("NIE");
	}
	return 0;
}
