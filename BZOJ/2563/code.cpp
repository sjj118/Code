#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=10000+10,M=1e5+10;
int n,m,v[N];
bool cmp(int a,int b){return a>b;}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&v[i]),v[i]*=2;
	rep(i,1,m){int a,b,c;scanf("%d%d%d",&a,&b,&c);v[a]+=c;v[b]+=c;}
	sort(v+1,v+1+n,cmp);
	int ans=0;
	rep(i,1,n>>1)ans+=v[i*2-1]-v[i*2];
	printf("%d",ans>>1);
	return 0;
}
