#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	//int n=rand()%35000+1,q=rand()%70000+1;
	int n=35000,q=70000;
	printf("%d\n",n);
	rep(i,1,n)printf("%d ",rand()%70000);puts("");
	printf("%d\n",q);
	rep(i,1,q){
		int op=rand()%3+1;
		if(op==1){
			int l=rand()%n+1,r=rand()%n+1;
			if(l>r)swap(l,r);
			printf("Q %d %d %d\n",l,r,rand()%(r-l+1)+1);
		}else if(op==2){
			printf("M %d %d\n",rand()%n+1,rand()%70000);
		}else{
			++n;
			printf("I %d %d\n",rand()%n+1,rand()%70000);
		}
	}
	return 0;
}
