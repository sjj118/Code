#include<iostream>
#include<cstdio>
#include<algorithm>
#define mo 1000000007
#define LL long long
#define maxn 1010

using namespace std;

LL n,a[maxn],b[maxn];
LL dp[maxn][maxn<<1],cc[maxn][maxn<<1],c1[maxn][maxn],c2[maxn<<1][maxn];
bool comp(LL*a,LL*b){return *a<*b;}
struct Discrete{
	LL tot,*val[maxn<<1],maxval;
	LL real[maxn<<1];
	void ins(LL&x){val[tot++]=&x;}
	void work(){
		sort(val,val+tot,comp);
		for(LL i=0,last=-1e9;i<tot;++i){
			if(*val[i]>last)real[++maxval]=*val[i],last=*val[i];
			*val[i]=maxval;
		}
	}
}lisan;
LL power(LL base,LL exp){
	LL ans=1;
	while(exp){
		if(exp&1)ans=ans*base%mo;
		base=base*base%mo;
		exp>>=1;
	}
	return ans;
}
void pre(){
	for(int i=0;i<=n;++i){
		c1[i][0]=1;
		for(int j=1;j<=i;++j)c1[i][j]=(c1[i-1][j]+c1[i-1][j-1])%mo;
	}
	for(int i=1;i<=lisan.maxval;++i){
		c2[i][0]=1;
		for(int j=1;j<=n;++j)c2[i][j]=c2[i][j-1]*power(j,mo-2)%mo*(lisan.real[i]-lisan.real[i-1]-j+1)%mo;
	}
	for(int i=1;i<=lisan.maxval;++i)for(int j=0;j<=n;++j)for(int k=min(i,j);k>=0;--k)cc[i][j]=(cc[i][j]+c1[j][k]*c2[i][k+1])%mo;
}

int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)scanf("%lld%lld",&a[i],&b[i]),--a[i],lisan.ins(a[i]),lisan.ins(b[i]);
	lisan.work();
	pre();
	for(int i=0;i<=lisan.maxval;++i)dp[0][i]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=lisan.maxval;++j){
			if(a[i]<j&&j<=b[i])for(int k=i,cnt=0;k;--k,cnt+=((a[k]<j)&&(j<=b[k]))){
				dp[i][j]=(dp[i][j]+dp[k-1][j-1]*cc[j][cnt])%mo;
			}
			dp[i][j]=(dp[i][j]+dp[i][j-1])%mo;
		}
	}
	LL ans=0;
	for(int i=1;i<=n;++i)ans=(ans+dp[i][lisan.maxval])%mo;
	printf("%lld",ans);
	return 0;
}
