#include<cstdio>
#include<algorithm>
#include<functional>

using namespace std;

const int N=1000+10;

int n,h,a[N];

bool canPut(int n){
    sort(a+1,a+1+n,greater<int>());
    int l=h;
    for(int i=1;i<=n;i+=2){
        l-=a[i];
        if(l<0)return false;
    }
    return true;
}

int main(){
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    int k=0;
    while(k<n&&canPut(k+1))++k;
    printf("%d",k);
    return 0;
}
