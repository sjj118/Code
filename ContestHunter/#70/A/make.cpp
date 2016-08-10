#include<bits/stdc++.h>

using namespace std;

int n=9;

int main(){
	srand(time(0));freopen("code.in","w",stdout);
	printf("%d\n",n);
	for(int i=1;i<=n;++i)printf("%d ",rand()*rand()%n+1);
	return 0;
}
