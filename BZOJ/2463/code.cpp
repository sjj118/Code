#include<iostream>
#include<cstdio>
int n;
int main(){
	while(scanf("%d",&n)>0&&n){
		if(n&1)puts("Bob");else puts("Alice");
	}
	return 0;
}
