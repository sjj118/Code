#include<bits/stdc++.h>

using namespace std;
int n=100;

int main(){
	srand(time(0));freopen("excellent.in","w",stdout);
	printf("1\n");
	for(int i=1;i<=n;++i)printf("%c",rand()%2+'a');
	return 0;
}
