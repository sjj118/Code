#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
using std::sort;
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
inline void up(int&x,int y){if(y>x)x=y;}
const int N=500+10,mo=1e9+7;
int n,a[N],b[N];
LL inv[N];
bool cmp(int*a,int*b){return *a<*b;}
struct Lisan{
	int tot,*val[N<<1],rl[N<<1],ml;
	void ins(int&x){val[++tot]=&x;}
	void work(){
		sort(val+1,val+1+tot,cmp);
		for(int i=1,lst=0;i<=tot;++i){
			if(*val[i]>lst)rl[++ml]=lst=*val[i];
			*val[i]=ml;
		}
	}
}li;
LL dp[N][N<<1];
int DP(){
	LL ret=0;
	rep(i,0,li.ml-1)dp[0][i]=1;
	rep(i,1,n){
		rep(j,1,li.ml-1)if(j>=a[i]){
			if(j<b[i]){
				int l=li.rl[j+1]-li.rl[j];
				int t=-1;
				LL tmp=1;
				per(k,i-1,0){
					if(a[k+1]<=j&&b[k+1]>j){
						++t;
						tmp=tmp*inv[t+1]%mo*(l+t)%mo;
					}
					dp[i][j]+=dp[k][j-1]*tmp;
					if(dp[i][j]>=(LL)mo*mo*8)dp[i][j]%=mo;
				}
			}
			dp[i][j]%=mo;
			ad(dp[i][j],dp[i][j-1],mo);
		}
		ad(ret,dp[i][li.ml-1],mo);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i],&b[i]),++b[i],li.ins(a[i]),li.ins(b[i]);
	li.work();
	inv[1]=1;rep(i,2,n)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
	printf("%d",DP());
	return 0;
}
