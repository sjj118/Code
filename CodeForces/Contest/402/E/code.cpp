#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::reverse;
using std::swap;
using std::string;
using std::cin;
inline void up(int&x,int y){if(y>x)x=y;}
inline bool vaild(char c){return (c>='0'&&c<='9')||c=='?';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
const int N=1000+10,inf=1e9+7;
int n,c[10],h,lena;
int a[N],b[N][N],lenb[N];
int dp[N][N],wa[N],wb[N],d[10];
int calc(int x){
	int ret=0;
	while(x)ret+=c[x%10],x/=10;
	return ret;
}
char tmp[N];
int main(){
	scanf("%s",tmp+1);reverse(tmp+1,tmp+1+strlen(tmp+1));up(h,strlen(tmp+1));lena=strlen(tmp+1);
	int tl=strlen(tmp+1);rep(i,1,tl)a[i]=(tmp[i]=='?'?10:tmp[i]-'0');
	scanf("%d",&n);
	rep(i,1,n){
		scanf("\n%s",tmp+1);
		reverse(tmp+1,tmp+1+strlen(tmp+1));
		up(h,strlen(tmp+1));
		tl=strlen(tmp+1);lenb[i]=tl;
		rep(j,1,tl)b[i][j]=tmp[j]-'0';
	}
	rep(i,0,9)scanf("%d",&c[i]);
	int *x=wa,*y=wb;
	rep(i,1,n)x[i]=i;
	rep(i,0,h)rep(j,0,n)dp[i][j]=-inf;
	dp[0][0]=0;
	rep(i,0,h-1){
		int cl=0,cr=9;
		if(i+1==lena)cl=1;
		if(a[i+1]!=10)cl=cr=a[i+1];
		rep(p,cl,cr){
			int sum=0,jin=0;
			rep(j,1,n)if(i<lenb[x[j]]||i<lena)sum+=c[(b[x[j]][i+1]+p)%10],jin+=(b[x[j]][i+1]+p)/10;
			up(dp[i+1][jin],dp[i][0]+sum);
			rep(j,1,n)if(i<lenb[x[j]]||i<lena){
				jin+=((b[x[j]][i+1]+p)==9);
				sum+=c[(b[x[j]][i+1]+p+1)%10]-c[(b[x[j]][i+1]+p)%10];
				if(dp[i][j]>=0)up(dp[i+1][jin],dp[i][j]+sum);
			}
		}
		swap(x,y);
		cls(d);
		rep(j,1,n)++d[b[y[j]][i+1]];
		per(j,8,0)d[j]+=d[j+1];
		per(j,n,1)x[d[b[y[j]][i+1]]--]=y[j];
	}
	int ans=0;
	rep(i,0,n)up(ans,dp[h][i]+calc(i));
	printf("%d",ans);
	return 0;
}
