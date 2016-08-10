#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
typedef long long LL;
using namespace std;
int inf=50;
int rnd(){return (LL)rand()%inf*rand()%inf*rand()%inf;}
int main(){
	srand(time(0));freopen("code.in","w",stdout);
	printf("%d %d",rand()%50+1,rnd()+2);
	return 0;
}
