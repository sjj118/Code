#include<iostream>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using std::swap;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed+time(0));printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int n=rand()%1000+1,m=rand()%1000+1;
	printf("%d\n",n);
	rep(i,1,n)printf("%d ",rand()%20001-10000);puts("");
	printf("%d\n",m);
	rep(i,1,m){
		int op=rand()%4+1;
		int x=rand()%n+1,y=rand()%n+1;
		if(x>y)swap(x,y);
		if(op==1){
			printf("Q %d %d\n",x,y);
		}else if(op==2){
			printf("A %d %d\n",x,y);
		}else if(op==3){
			int z=rand()%20001-10000;
			printf("P %d %d %d\n",x,y,z);
		}else{
			int z=rand()%20001-10000;
			printf("C %d %d %d\n",x,y,z);
		}
	}
	return 0;
}
