#include<iostream>
#include<cstdio>
#include<queue>
#define mp make_pair
#define fi first
#define se second
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef priority_queue<pii> Heap;
const int N=250000+10;
int n,a[N],b[N],x[N];
Heap heap;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	LL sum=0;int ans=0;
	rep(i,1,n){
		sum+=a[i];
		if(b[i]>sum){
			if(heap.size()){
				pii k=heap.top();
				if(k.fi>b[i]){
					heap.pop();
					x[k.se]=0;x[i]=1;
					sum+=k.fi;sum-=b[i];
					heap.push(mp(b[i],i));
				}
			}
		}else sum-=b[i],x[i]=1,++ans,heap.push(mp(b[i],i));
	}
	printf("%d\n",ans);
	rep(i,1,n)if(x[i])printf("%d ",i);
	return 0;
}
