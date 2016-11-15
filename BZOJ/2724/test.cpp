#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace sjj118{

const int N=4e4+10,B=100,_B=N/B+10;
int n,m,ans,a[N],heav[_B][_B],cnt[N],lp[N],st[N];
bool cmp(int*a,int*b){return *a<*b;}
struct Lisan{
	int tot,*val[N],rv[N],mv;
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,cmp);
		for(int i=1,last=0;i<=tot;++i){
			if(*val[i]>last)last=rv[++mv]=*val[i];
			*val[i]=mv;
		}
	}
}lisan;
bool comp(int x,int y){return a[x]<a[y]||a[x]==a[y]&&x<y;}
int getnum(int x,int l,int r){
	return upper_bound(lp+st[x],lp+st[x+1],r)-lower_bound(lp+st[x],lp+st[x+1],l);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]),lisan.ins(a[i]);
	lisan.work();
	rep(i,1,n)lp[i]=i;
	sort(lp+1,lp+1+n,comp);
	for(int i=1,j=1;j<=lisan.mv+1;++j){
		while(i<=n&&a[lp[i]]<j)++i;st[j]=i;
	}
	per(i,n,1)st[a[lp[i]]]=i;
	int mb=n/B;rep(i,0,mb){
		rep(j,i,mb){
			if(j>i)heav[i][j]=heav[i][j-1];
			int rb=min(j*B+B-1,n);rep(k,j*B,rb){
				++cnt[a[k]];
				if(cnt[a[k]]>cnt[heav[i][j]]||cnt[a[k]]==cnt[heav[i][j]]&&a[k]<heav[i][j])heav[i][j]=a[k];
			}
		}
		cls(cnt);
	}
	while(m--){
		int l,r;scanf("%d%d",&l,&r);
		l=(l+ans-1)%n+1;r=(r+ans-1)%n+1;
		if(l>r)swap(l,r);
		ans=0;
		if(l/B==r/B){
			rep(i,l,r){++cnt[a[i]];if(cnt[a[i]]>cnt[ans]||cnt[a[i]]==cnt[ans]&&a[i]<ans)ans=a[i];}
			rep(i,l,r)--cnt[a[i]];
		}else{
			ans=heav[l/B+1][r/B-1];
			int rb=l/B*B+B-1;rep(i,l,rb){int t1=getnum(a[i],l,r),t2=getnum(ans,l,r);if(t1>t2||t1==t2&&a[i]<ans)ans=a[i];}
			rep(i,r/B*B,r){int t1=getnum(a[i],l,r),t2=getnum(ans,l,r);if(t1>t2||t1==t2&&a[i]<ans)ans=a[i];}
		}
		ans=lisan.rv[ans];
		printf("%d\n",ans);
	}
	return 0;
}
}
int main(){
	freopen("code.in","r",stdin);freopen("test.out","w",stdout);
	return sjj118::main();
}
