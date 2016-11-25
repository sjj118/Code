#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int n=2000,m=2000,v=300,e=90000;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("classroom.in","w",stdout);
	n=rand()%n+1;m=rand()%m+1;
	printf("%d %d %d %d\n",n,m,v,e);
	rep(i,1,n)printf("%d ",rand()%v+1);puts("");
	rep(i,1,n)printf("%d ",rand()%v+1);puts("");
	rep(i,1,n)printf("%.3lf ",1.0*(rand()%10001)/10000);
	rep(i,1,v-1)printf("%d %d %d\n",rand()%i+1,i+1,rand()%100+1);
	rep(i,v,e)printf("%d %d %d\n",rand()%v+1,rand()%v+1,rand()%100+1);
	return 0;
}
