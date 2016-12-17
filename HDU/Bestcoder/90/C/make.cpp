#include<iostream>
#include<cstdio>
#include<cstdlib>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=100000,Q=100000,C=1e6;
int main(){
	freopen(".seed","r",stdin);int seed;scanf("%d",&seed);
	freopen(".seed","w",stdout);srand(seed);printf("%d",rand());
	fclose(stdin);fclose(stdout);
	freopen("code.in","w",stdout);
	int T=5;
	printf("%d\n",T);
	while(T--){
		//int n=rand()%N+1,q=rand()%Q+1;
		int n=N,q=Q;
		printf("%d %d\n",n,q);
		rep(i,1,n)printf("%d ",rand()%C+1);puts("");
		rep(i,1,q){
			int op=rand()%2+1;
			printf("%d ",op);
			if(op==1)printf("%d %d\n",rand()%C+1,rand()%C+1);
			else{
				int l=rand()%n+1,r=rand()%n+1;
				if(l>r)swap(l,r);
				printf("%d %d\n",l,r);
			}
		}
	}
	return 0;
}
