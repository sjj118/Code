#include<iostream>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int T=500;printf("%d\n",T);
	while(T--){
		int n=1000,m=1000-1;printf("%d %d\n",n,m);
		rep(i,1,n)printf("%d ",rand()%n+1);puts("");
		rep(i,1,n-1)printf("%d ",rand()%i+1);puts("");
		rep(i,1,m)printf("%d %d\n",rand()%n+1,rand()%n);
		puts("");puts("");
	}
	return 0;
}
