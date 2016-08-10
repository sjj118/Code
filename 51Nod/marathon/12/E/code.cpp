#include<iostream>
#include<cstdio>
#define mo 1000000007
#define LL long long

using namespace std;

int n,x,y;
int power(LL base,int exp){
	LL ans=1;
	while(exp){
		if(exp&1)ans=ans*base%mo;
		base=base*base%mo;
		exp>>=1;
	}
	return ans;
}

int main(){
	
	return 0;
}
