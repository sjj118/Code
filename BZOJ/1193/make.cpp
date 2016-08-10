#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
typedef long long LL;

using namespace std;
int inf=2e7,t=1e7;
int rnd(){return (LL)rand()*rand()%inf*rand()%inf;}
int main(){
	srand(time(0));freopen("code.in","w",stdout);
	printf("%d %d %d %d\n",rnd()%inf-t,rnd()%inf-t,rnd()%inf-t,rnd()%inf-t);
	return 0;
}
