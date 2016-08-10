#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const LL inf=1e14;
LL rnd(){return (LL)rand()%inf*rand()%inf*rand()%inf*rand()%inf*rand()%inf*rand()%inf;}
int main(){
	srand(time(0));freopen("code.in","w",stdout);
	LL l=rnd()+1,r=l+rnd()%10000000;
	printf("%lld %lld",l,r);
	return 0;
}
