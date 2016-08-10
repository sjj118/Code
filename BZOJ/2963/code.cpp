#include<iostream>
#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
#define LL long long
int id(int a,int b){return a*9+b;}
LL C[137][137];
void initC(){
	for(int i=0;i<=136;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}
LL ansp,ansq;
LL gcd(LL a,LL b){
	if(!b)return a;
	return gcd(b,a%b);
}
int n,num[35];
void getpai(){
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	int x=c-'0',t;c=getchar();
	if(c=='m')t=0;if(c=='s')t=1;if(c=='p')t=2;if(c=='c')t=3;
	++num[id(t,x)];
}
namespace normal{
	int num[35];
	LL dfs2(int k,int p,int q){
		LL tmp=0;
		if(k==0){
			tmp=1;
			for(int i=1;i<=34;++i)tmp*=C[::num[i]][::num[i]-num[i]];
			return tmp;
		}
		if(p==3&&q==5)return 0;
		if(num[id(p,q)]>=3){
			num[id(p,q)]-=3;
			dfs2(k-1,p,q);
			num[id(p,q)]+=3;
		}
		if(q==7)tmp+=dfs2(k,p+1,1);
		else tmp+=dfs2(k,p,q+1);
		return tmp;
	}
	LL dfs(int k,int p,int q,int h){
		LL tmp=0;
		if(k==0||p==3){
			return dfs2(k,0,1);
		}
		if(q==7)tmp+=dfs(k,p+1,1,0);
		else tmp+=dfs(k,p,q+1,0);
		if(h<3){
			for(int i=0;i<3;++i)--num[id(p,q+i)];
			if(num[id(p,q)]>=0&&num[id(p,q+1)]>=0&&num[id(p,q+2)]>=0)tmp+=dfs(k-1,p,q,h+1);
			for(int i=0;i<3;++i)++num[id(p,q+i)];
		}
		return tmp;
	}
	LL getans(){
		for(int i=1;i<=35;++i)num[i]=::num[i];
		return dfs(4,0,1,0);
	}
}
namespace seven{
	int num[35];
	LL dp[35][8];
	LL getans(){
		for(int i=0;i<=34;++i)dp[i][0]=1;
		for(int i=1;i<=34;++i)num[i]=::num[i]*(::num[i]-1)/2;
		for(int i=1;i<=35;++i){
			for(int j=1;j<=min(7,i);++j)dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*num[i];
		}
		return dp[34][7];
	}
}
namespace peerless{
	int num[14];
	LL getans(){
		for(int i=0;i<=2;++i)num[i*2+1]=::num[id(i,1)],num[i*2+2]=::num[id(i,9)];
		for(int i=1;i<=7;++i)num[6+i]=::num[id(3,i)];
		LL mul=1,ans=0;for(int i=1;i<=13;++i)mul*=num[i];
		for(int i=1;i<=13;++i)ans+=mul*(num[i]-1)/2;
		return ans;
	}
}
int main(){
	initC();
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);memset(num,0,sizeof(num));
		for(int i=1;i<=n;++i)getpai();
		ansq=C[n][14];
		ansp=normal::getans()+seven::getans()+peerless::getans();
//		LL d=gcd(ansp,ansq);ansp/=d;ansq/=d;
		printf("%lld/%lld\n",ansp,ansq);
	}
	return 0;
}
