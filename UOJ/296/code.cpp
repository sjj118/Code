#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=2e5+10,inf=2e9;
int n,q,a[N];
int s(int p,int r){
	if(p>r)return -inf;
	return a[p];
}
int solve(int l,int r){
	if(l==r)return l;
	int i=l,j=l+1;
	int ans=0;
	for(;i<=r&&j<=r;){
		int k=0;
		for(;s(i+k,r)==s(j+k,r);++k);
		if(s(i+k,r)>s(j+k,r)){i+=k+1;if(j<=r)ans=j;}
		else {j+=k+1;if(i<=r)ans=i;}
		if(i==j)++i;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n)scanf("%d",&a[i]);
	while(q--){
		int op;scanf("%d",&op);
		if(op==1){
			int l,r,d;scanf("%d%d%d",&l,&r,&d);
			rep(i,l,r)a[i]+=d;
		}else{
			int l,r;scanf("%d%d",&l,&r);
			printf("%d\n",solve(l,r));
		}
	}
	return 0;
}
