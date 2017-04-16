#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=200+10;
int n,m;
namespace Task1{
	int a[N][N],old[N][N],b[N];
	void solve(){
		rep(i,1,n)rep(j,1,n)old[i][j]=a[i][j];
		cls(b);
		rep(i,1,n)rep(j,1,n)b[j]|=a[i][j];
		rep(i,1,n){
			bool flag=1;
			rep(j,1,n)if(a[i][j])flag=0;
			if(!flag)continue;
			rep(j,1,n)if(!b[j]){
				b[j]=1;a[i][j]=1;
				break;
			}
		}
	}
}
namespace Task2{
	int a[N][N],old[N][N],b[N];
	void solve(){
		rep(i,1,n)rep(j,1,n)old[i][j]=a[i][j];
		cls(b);
		rep(i,1,n)rep(j,1,n)b[i+j]|=a[i][j];
		for(int i=1;;++i){
			//i=y-x+n
			bool flag=1;
			for(int k=n+2-i;k<=n+i;k+=2)if(a[(k-i+n)>>1][(k+i-n)>>1])flag=0;
			if(flag){
				for(int k=n+2-i;k<=n+i;k+=2)if(!b[k]){
					b[k]=1;a[(k-i+n)>>1][(k+i-n)>>1]=1;
					break;
				}
			}
			if(i==n)break;
			//i=x-y+n
			flag=1;
			for(int k=n+2-i;k<=n+i;k+=2)if(a[(k+i-n)>>1][(k-i+n)>>1])flag=0;
			if(flag){
				for(int k=n+2-i;k<=n+i;k+=2)if(!b[k]){
					b[k]=1;a[(k+i-n)>>1][(k-i+n)>>1]=1;
					break;
				}
			}
		}
	}
}
int main(){
	int tasknumber;scanf("%d",&tasknumber);
	rep(taskid,1,tasknumber){
		scanf("%d%d",&n,&m);
		cls(Task1::a);cls(Task2::a);
		rep(i,1,m){
			char c;int x,y;scanf("\n%c%d%d",&c,&x,&y);
			if(c=='x'||c=='o')Task1::a[x][y]=1;
			if(c=='+'||c=='o')Task2::a[x][y]=1;
		}
		Task1::solve();
		Task2::solve();
		int y=0,z=0;
		rep(i,1,n)rep(j,1,n)y+=Task1::a[i][j]+Task2::a[i][j];
		rep(i,1,n)rep(j,1,n)if(Task1::a[i][j]!=Task1::old[i][j]||Task2::a[i][j]!=Task2::old[i][j])++z;
		printf("Case #%d: %d %d\n",taskid,y,z);
		rep(i,1,n)rep(j,1,n)if(Task1::a[i][j]!=Task1::old[i][j]||Task2::a[i][j]!=Task2::old[i][j]){
			if(Task1::a[i][j]){
				if(Task2::a[i][j])printf("o %d %d\n",i,j);
				else printf("x %d %d\n",i,j);
			}else{
				if(Task2::a[i][j])printf("+ %d %d\n",i,j);
			}
		}
	}
	return 0;
}
