#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
typedef long long LL;
using namespace std;
LL a,b,ans[10],g[10][2][15],f[2][15],l;
void calc(LL x){
	l=0;int a[15];cls(f);cls(g);
	while(x)a[++l]=x%10,x/=10;
	for(int i=1;i*2<=l;++i)swap(a[i],a[l-i+1]);
	f[1][0]=1;
	rep(i,1,l){
		rep(j,0,9){
			if(j==a[i]){
				f[0][i]+=f[0][i-1];
				f[1][i]+=f[1][i-1];
			}else if(j<a[i]){
				f[0][i]+=f[0][i-1]+f[1][i-1];
			}else{
				f[0][i]+=f[0][i-1];
			}
		}
	}
	rep(x,0,9){
		rep(i,1,l){
			rep(j,0,9){
				if(a[i]==j){
					if(j==x)g[x][0][i]+=f[0][i-1],g[x][1][i]+=f[1][i-1];
					g[x][0][i]+=g[x][0][i-1];
					g[x][1][i]+=g[x][1][i-1];
				}else if(j<a[i]){
					if(j==x)g[x][0][i]+=f[0][i-1]+f[1][i-1];
					g[x][0][i]+=g[x][0][i-1]+g[x][1][i-1];
				}else{
					if(j==x)g[x][0][i]+=f[0][i-1];
					g[x][0][i]+=g[x][0][i-1];
				}
			}
		}
	}
	LL tmp=1;
	per(i,l-1,1)g[0][0][l]-=i*9*tmp,tmp*=10;
	g[0][0][l]-=l;
}
int main(){
	scanf("%lld%lld",&a,&b);
	calc(b);
	rep(i,0,9)ans[i]+=g[i][0][l]+g[i][1][l];
	calc(a-1);
	rep(i,0,9)ans[i]-=g[i][0][l]+g[i][1][l];
	rep(i,0,8)printf("%lld ",ans[i]);printf("%lld",ans[9]);
	return 0;
}
