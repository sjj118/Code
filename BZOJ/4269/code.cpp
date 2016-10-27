#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{
	
const int N=1e5+10;
int n,a[N];
void Gauss(){
	int k=0;
	per(i,30,0){
		rep(j,k+1,n)if((a[j]>>i)&1){
			swap(a[++k],a[j]);
			break;
		}
		rep(j,k+1,n)if((a[j]>>i)&1)a[j]^=a[k];
	}
	n=k;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	Gauss();
	int ans=0;
	rep(i,1,n)if((ans^a[i])>ans)ans^=a[i];
	printf("%d %d",ans,ans^a[n]);
	return 0;
}

}
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	return sjj118::main();
}
