#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1000+10,maxv=2e6;
inline void up(int&x,int y){if(y>x)x=y;}
int n,k,a[maxn],c[maxv],ans;
const int ha=2333333;
struct HashMap{
	int tot,head[ha],next[maxv],key[maxv];
	int ins(int a){key[++tot]=a;a%=ha;next[tot]=head[a];head[a]=tot;return tot;}
	int find(int a){for(int p=head[a%ha];p;p=next[p])if(key[p]==a)return p;return 0;}
	int operator[](int x){
		int t=find(x);
		if(!t)t=ins(x);
		return t;
	}
}hm;
int main(){
	scanf("%d%d",&n,&k);
	if(k==0){puts("0");return 0;}
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		for(int p=1;p*p<=a[i];++p)if(a[i]%p==0){
			++c[hm[p]];
			if(p*p<a[i])++c[hm[a[i]/p]];	
		}
	}
	rep(i,1,hm.tot)if(c[i]>=k)up(ans,hm.key[i]);
	printf("%d",ans);
	return 0;
}
