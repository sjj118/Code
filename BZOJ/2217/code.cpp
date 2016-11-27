#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e6+10;
inline bool vaild(char c){return c=='T'||c=='W';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int n,m,a[N],s[N],b[N<<1],nx[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)a[i]=(gc()=='T'?2:1);
	rep(i,1,n)s[i]=s[i-1]+a[i];
	int tmp=n+1;
	per(i,n,1){
		if(a[i]==1)tmp=i;
		nx[i]=tmp;
	}
	b[s[n]]=n;for(int i=n-1,j=s[n]-1;i>=0;--i)while(j>=s[i])b[j--]=i;
	while(m--){
		int q;scanf("%d",&q);
		if(q>s[n]){puts("NIE");continue;}
		int l=1,r=b[q];
		if(s[r]==q){printf("%d %d\n",l,r);continue;}
		if(nx[r+1]-r<=nx[l]-l+1){
			if(nx[r+1]>n)puts("NIE");
			else printf("%d %d\n",l+nx[r+1]-r-1,nx[r+1]);
		}else{
			if(r+nx[l]-l+1<=n)printf("%d %d\n",nx[l]+1,r+nx[l]-l+1);
			else puts("NIE");
		}
	}
	return 0;
}
