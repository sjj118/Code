#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=30;
inline bool vaild(char c){return (c>='A'&&c<='Z')||c=='?';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
int r,c,a[N][N],b[N],tot;
void work(int u,int d,int r){
	static int b[N];
	int tot=0;
	b[0]=0;
	rep(i,1,c)if(a[r][i]!='?')b[++tot]=i;
	b[tot+1]=c;
	rep(i,u,d){
		rep(k,1,tot-1)rep(j,b[k-1]+1,b[k])a[i][j]=a[r][b[k]];
		rep(j,b[tot-1]+1,b[tot+1])a[i][j]=a[r][b[tot]];
	}
}
int main(){
	int tasknumber;scanf("%d",&tasknumber);
	rep(taskid,1,tasknumber){
		scanf("%d%d",&r,&c);
		rep(i,1,r)rep(j,1,c)a[i][j]=gc();
		tot=0;
		b[0]=0;
		rep(i,1,r)rep(j,1,c)if(a[i][j]!='?')if(b[tot]!=i)b[++tot]=i;
		b[tot+1]=r;
		rep(i,1,tot-1)work(b[i-1]+1,b[i],b[i]);
		work(b[tot-1]+1,b[tot+1],b[tot]);
		printf("Case #%d:\n",taskid);
		rep(i,1,r){
			rep(j,1,c)putchar(a[i][j]);
			puts("");
		}
	}
	return 0;
}
