#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
typedef long long LL;
const int N=99,mo=1e9+7;
LL n,m,f[N][4];
int k,a[N],b[N],l;
int main(){
	int T;scanf("%d%d",&T,&k);
	while(T--){
		scanf("%lld%lld",&n,&m);
		if(m>n)m=n;l=0;
		LL tmp=n;
		while(tmp)a[++l]=tmp%k,tmp/=k;
		tmp=m;
		rep(i,1,l)b[i]=tmp%k,tmp/=k;
		rep(i,0,3)f[0][i]=1;
		rep(i,1,l){
			f[i][0]=k*(k+1)/2*f[i-1][0]%mo;
			f[i][1]=((k-b[i])*(b[i]*f[i-1][0]+f[i-1][1])+b[i]*(b[i]+1)/2*f[i-1][0])%mo;
			f[i][2]=(1*(a[i]+1)*f[i-1][2]+a[i]*(a[i]+1)/2*f[i-1][0])%mo;
			if(a[i]<b[i])f[i][3]=(
					+1*(a[i]+1)*f[i-1][2]
					+a[i]*(a[i]+1)/2*f[i-1][0]
			)%mo;
			else f[i][3]=(
					+1*1*f[i-1][3]
					+(a[i]-b[i])*1*f[i-1][1]
					+1*b[i]*f[i-1][2]
					+(a[i]-b[i])*b[i]*f[i-1][0]
					+b[i]*(b[i]+1)/2*f[i-1][0]
			)%mo;
		}
		n%=mo;m%=mo;
		LL sum=((mo+n-m)*(m+1)+(m+1)*(m+2)/2)%mo;
		printf("%lld\n",(mo+sum-f[l][3])%mo);
	}
	return 0;
}
