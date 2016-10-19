#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10;
inline bool vaild(char c){return c>='0'&&c<='9';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
inline int read(){int tmp=0;char c=gc();while(vaild(c))tmp=tmp*10+c-'0',c=getchar();return tmp;}
int n,a[maxn],ans[maxn],c[maxn],b[maxn],tot,ok[maxn];
bool check(int k){
	cls(c);cls(b);
	rep(i,0,k-1)++c[a[i]],++b[a[i]];
	rep(i,k,n-1){
		if(c[a[i]]==0||b[a[i]]/c[a[i]]!=i/k)return 0;
		++b[a[i]];
	}
	return 1;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);tot=0;
		rep(i,0,n-1)a[i]=read();
		bool first=1;cls(ok);
		for(int k=1;k*k<=n;++k)if(n%k==0){
			if(!ok[k]&&check(k)){
				ok[k]=1;
				for(int j=2;j*k<=n;++j)ok[k*j]=1;
			}
			int t=n/k;
			if(k*k!=n&&!ok[t]&&check(t)){
				ok[t]=1;
				for(int j=2;j*t<=n;++j)ok[t*j]=1;
			}
		}
		rep(i,1,n)if(ok[i]&&n%i==0){
			if(first)printf("%d",i),first=0;
			else printf(" %d",i);
		}
		puts("");
	}
	return 0;
}
