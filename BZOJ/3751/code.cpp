#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
namespace test{
	const int N=100000;
	bool s[N];
	int tot,prime[N];
	void pre(){
		rep(i,2,N-1){
			if(!s[i])prime[++tot]=i;
			for(int j=1;j<=tot&&i*prime[j]<N;++j){
				s[i*prime[j]]=1;
				if(i%prime[j]==0)break;
			}
		}
	}
}

const int N=100+10,M=1e6+10,tot=6,P[tot]={10007,21893,19997,14843,11261,30011};//,7901,4021,20719,10781};
inline bool vaild(char c){return c>='0'&&c<='9'||c=='-';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int a[N][tot],n,m;
bool ans[M],tmp[M];
int main(){
	//int sum=0;rep(i,0,tot)sum+=P[i];cout<<sum<<endl;
	//test::pre();
	scanf("%d%d",&n,&m);
	rep(i,0,n){
		char c=gc();
		int f=0;
		if(c=='-')f=1,c=getchar();
		while(vaild(c)){
			rep(j,0,tot-1)(a[i][j]=a[i][j]*10+c-'0')%=P[j];
			c=getchar();
		}
		if(f)rep(j,0,tot-1){a[i][j]=P[j]-a[i][j];if(a[i][j]==P[j])a[i][j]=0;}
	}
	rep(i,1,m)ans[i]=1;
	rep(i,0,tot-1){
		rep(j,1,m)tmp[j]=0;
		int fr=min(P[i],m);
		rep(j,1,fr){
			int sum=0,x=1;
			rep(k,0,n)(sum+=x*a[k][i])%=P[i],x=x*j%P[i];
			if(sum)continue;
			for(int k=j;k<=m;k+=P[i])tmp[k]=1;
		}
		rep(j,1,m)if(!tmp[j])ans[j]=0;
	}
	int cnt=0;
	rep(i,1,m)if(ans[i])++cnt;
	printf("%d\n",cnt);
	rep(i,1,m)if(ans[i])printf("%d\n",i);
	return 0;
}
