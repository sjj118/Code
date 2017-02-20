#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
using std::sort;
const int N=1e5+10; 
int n,a[N],b[N];
LL c[N];
bool cmp(int x,int y){return a[x]>a[y]||(a[x]==a[y]&&x<y);}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)b[i]=i;
	sort(b+1,b+1+n,cmp);
	int p=n+1;
	LL sum=0,cnt=0;
	rep(i,1,n){
		if(b[i]<p){
			c[p]=sum-cnt*a[b[i]];
			sum=cnt*a[b[i]];
			p=b[i];
		}
		++cnt;
		sum+=a[b[i]];
	}
	c[1]=sum;
	rep(i,1,n)printf("%lld\n",c[i]);
	return 0;
}
