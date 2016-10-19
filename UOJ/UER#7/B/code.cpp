#include<bits/stdc++.h>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],h[maxn],cnt,mak[maxn];
struct Queue{
	int ql,qr,q[maxn];
	int front(){return q[ql];}
	int back(){return q[qr];}
	void pop_front(){++ql;}
	void pop_back(){--qr;}
	int size(){return qr-ql+1;}
	void push_front(int x){q[--ql]=x;}
	void push_back(int x){q[++qr]=x;}
	void clear(){ql=1;qr=0;}
}U,D;
int calc(int d){
	int ans=0;U.clear();D.clear();
	for(int l=1,r=0;l<=n;++l){
		while(l>r||(r<n&&h[r+1]-h[D.front()]<=d&&h[U.front()]-h[r+1]<=d)){
			++r;
			while(U.size()&&h[r]>=h[U.back()])U.pop_back();U.push_back(r);
			while(D.size()&&h[r]<=h[D.back()])D.pop_back();D.push_back(r);
		}
		if(D.front()==l)D.pop_front();
		if(U.front()==l)U.pop_front();
		ans=max(ans,r-l+1);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&h[i]);
	a[++cnt]=0;
	while(a[cnt]<1000000)a[cnt+1]=a[cnt]+a[cnt]/20+1,++cnt;
	rep(i,1,cnt){
		mak[i]=calc(a[i]);
	}
	for(int k=2,i=1;k<=n;++k){
		while(mak[i]<k)++i;
		printf("%d\n",a[i]);
	}
	return 0;
}
