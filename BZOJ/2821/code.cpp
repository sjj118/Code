#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int maxn=1e5+10,B=320;
inline void swap(int&a,int&b){int t=a;a=b;b=t;}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
int n,c,q,ans,even[B][B],a[maxn],cnt[B][maxn],num[maxn],vis[maxn];
int main(){
	scanf("%d%d%d",&n,&c,&q);
	rep(i,1,n)scanf("%d",&a[i]);
	int fr=min(B-1,n);rep(i,1,fr)++cnt[0][a[i]];
	fr=n/B;rep(i,1,fr){
		rep(j,1,c)cnt[i][j]=cnt[i-1][j];
		int tr=B*i+B-1;rep(j,B*i,tr)++cnt[i][a[j]];
	}
	rep(i,0,fr){
		cls(num);
		rep(j,i,fr){
			if(j>i)even[i][j]=even[i][j-1];
			rep(k,j*B,j*B+B-1){
				if(num[a[k]]==0);
				else if(num[a[k]]&1)++even[i][j];
				else --even[i][j];
				++num[a[k]];
			}
		}
	}
	rep(m,1,q){
		int l,r;scanf("%d%d",&l,&r);
		l=(l+ans)%n+1;r=(r+ans)%n+1;
		if(l>r)swap(l,r);
		ans=0;
		if(l/B==r/B){
			rep(i,l,r){
				if(vis[a[i]]!=m)vis[a[i]]=m,num[a[i]]=0;
				if(num[a[i]]==0);
				else if(num[a[i]]&1)++ans;
				else --ans;
				++num[a[i]];
			}
		}else{
			ans=even[l/B+1][r/B-1];
			fr=l/B*B+B-1;rep(i,l,fr){
				if(vis[a[i]]!=m)vis[a[i]]=m,num[a[i]]=cnt[r/B-1][a[i]]-cnt[l/B][a[i]];
				if(num[a[i]]==0);
				else if(num[a[i]]&1)++ans;
				else --ans;
				++num[a[i]];
			}
			rep(i,r/B*B,r){
				if(vis[a[i]]!=m)vis[a[i]]=m,num[a[i]]=cnt[r/B-1][a[i]]-cnt[l/B][a[i]];
				if(num[a[i]]==0);
				else if(num[a[i]]&1)++ans;
				else --ans;
				++num[a[i]];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
