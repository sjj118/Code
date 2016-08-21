#include<bits/stdc++.h>
using namespace std;
int n=5e5,m=5e5;
int main(){
	srand(time(0));freopen("code.in","w",stdout);
	printf("%d %d\n",n,m);
	for(int i=1;i<=n/2-1;++i)printf("%d ",rand());
	for(int i=1;i<=n/2+1;++i)printf("%d ",rand());puts("");
	for(int i=1;i<=m;++i){
		int l=1,r=n;
		printf("%d %d\n",l,r);
	}
}
