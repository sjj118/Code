#include<iostream>
#include<cstdio>
#include<algorithm>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=70000+10;
int n,q,a[N],b[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	scanf("%d",&q);
	int ans=0;
	while(q--){
		char op;scanf("\n%c",&op);
		if(op=='Q'){
			int x,y,k;scanf("%d%d%d",&x,&y,&k);
			//x^=ans;y^=ans;k^=ans;
			rep(i,x,y)b[i-x]=a[i];
			sort(b,b+y-x+1);
			printf("%d\n",ans=b[k-1]);
		}else if(op=='M'){
			int x,y;scanf("%d%d",&x,&y);
			//x^=ans;y^=ans;
			a[x]=y;
		}else{
			int x,y;scanf("%d%d",&x,&y);
			//x^=ans;y^=ans;
			per(i,n++,x)a[i+1]=a[i];
			a[x]=y;
		}
	}
	return 0;
}
