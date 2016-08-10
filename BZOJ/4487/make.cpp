#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
	srand(time(0));freopen("code.in","w",stdout);
	printf("%d %d %d\n",rand()%10+1,rand()%10+1,rand()%10+1);
	return 0;
}
