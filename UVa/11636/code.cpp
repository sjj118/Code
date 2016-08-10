#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int t,n;

int main(){
	while(scanf("%d",&n)>=0&&n>=0){
		printf("Case %d: %d\n",++t,int(ceil(log(n)/log(2))));
	}
	return 0;
} 
