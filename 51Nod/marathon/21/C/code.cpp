#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
const int mo=1e9+7;
LL n;
int main(){
    scanf("%lld",&n);
    if(n&1)puts("1");
    else{
        n/=2;
        printf("%lld",n%mo*((n+1)%mo)%mo);
    }
    return 0;
}
