#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
const int maxv=1048576,maxn=20;
inline int lowbit(int x){return x&(-x);}
int sg[maxv+10],hash[maxn+2];
int main(){
	sg[0]=0;
	rep(i,1,maxv-1){
		cls(hash);
		for(int j=0,k=0,tmp=1;j<20;++j,tmp<<=1)if(i&tmp){
			if(k)hash[sg[i^tmp^k]]=1;
		}else k=tmp;
		rep(j,0,maxn)if(!hash[j]){sg[i]=j;break;}
	}
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		int ans=0;
		rep(i,1,n){
			int m,tmp=0;scanf("%d",&m);
			rep(j,1,m){
				int x;scanf("%d",&x);tmp^=1<<(20-x);
			}
			ans^=sg[tmp];
		}
		if(ans)printf("YES\n");else printf("NO\n");
	}
}
