#include<bits/stdc++.h>

using namespace std;

int n=100;

int main(){
	srand(time(0));freopen("code.in","w",stdout);
	for(int i=1;i<=n;++i){
		int op=rand()%10;
		char c;
		if(op==0)c='B';
		else if(op==1)c='W';
		else c='?';
		printf("%c",c);
	}
	return 0;
}
