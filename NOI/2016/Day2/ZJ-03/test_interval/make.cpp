#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
typedef long long LL;
using namespace std;

int n=20,m=9,inf=1e9;
int rnd(){return (LL)rand()*rand()%inf*rand()%inf*rand()%inf;}

int main(){
	srand(time(0));freopen("interval.in","w",stdout);
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;++i){
		int l=rnd(),r=rnd()%(inf-l+1)+l;
		printf("%d %d\n",l,r);
	}
	return 0;
}
