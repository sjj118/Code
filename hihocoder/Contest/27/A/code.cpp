#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::min;
const int N=1000+10,inf=1e9;
inline void up(int&x,int y){if(y>x)x=y;}
int n,a[N][N],u[N],b[N],ans;
int sta[N],top;
int main(){
	scanf("%d",&n);
	rep(i,1,n)rep(j,1,n)scanf("%d",&a[i][j]);
	rep(i,1,n)rep(j,1,n)a[i][j]-=i+j-n-n;
	rep(i,1,n){
		rep(j,1,n)if(a[i][j]==a[i-1][j])++u[j];else u[j]=1;
		cls(b);
		top=0;
		rep(j,1,n){
			while(top&&a[i][sta[top]]==a[i][j]&&u[sta[top]]>=u[j])--top;
			b[j]+=j-sta[top];
			sta[++top]=j;
		}
		top=0;
		per(j,n,1){
			while(top&&a[i][sta[top]]==a[i][j]&&u[sta[top]]>=u[j])--top;
			b[j]+=sta[top]-j;
			sta[++top]=j;
		}
		rep(j,1,n)up(ans,min(b[j]-1,u[j]));
	}
	printf("%d",ans);
	return 0;
}
