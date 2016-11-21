#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=4e4+10;
int n,m,a[N],cnt[N],ans;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	while(m--){
		int l,r;scanf("%d%d",&l,&r);
		l=(l+ans-1)%n+1;r=(r+ans-1)%n+1;
		if(l>r)swap(l,r);
		cls(cnt);
		ans=0;
		rep(i,l,r){
			++cnt[a[i]];
			if(cnt[a[i]]>cnt[ans]||cnt[a[i]]==cnt[ans]&&a[i]<ans)ans=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	return sjj118::main();
}
