#include<cstdio>

using namespace std;

const int N=1e6+10;

int hp[N],n,m;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)scanf("%d",&hp[i]);
    LL sum=0;
    for(int i=1;i<=m;++i)sum+=hp[i];
    int t=(sum-1)/n+1;
    printf("%d\n",t);
    for(int i=1;i<=m;++i){

    }
    return 0;
}
