#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=100+10;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int lcm(int a,int b){return a/gcd(a,b)*b;}
int n,crush[N],ans=1,vis[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&crush[i]);
	rep(i,1,n)if(!vis[i]){
		int k=i,l=0;
		while(1){
			if(vis[k])break;
			++l;
			vis[k]=1;k=crush[k];
		}
		if(k!=i){puts("-1");return 0;}
		if(l&1)ans=lcm(ans,l);else ans=lcm(ans,l>>1);
	}
	printf("%d",ans);
	return 0;
}
