#include<cstdio>

typedef long long LL;

const int N=100000+10;
using namespace std;

int a,b,m,n;
int p[N],q[N];
int main(){
    scanf("%d%d",&a,&b);
    LL mx=1;
    while(mx*(mx+1)/2<=a+b)++mx;
    --mx;
    while(mx){
        if(a>=mx)a-=mx,p[++n]=mx;
        else b-=mx,q[++m]=mx;
        --mx;
    }
    printf("%d\n",n);
    for(int i=1;i<=n;++i)printf("%d ",p[i]);puts("");
    printf("%d\n",m);
    for(int i=1;i<=m;++i)printf("%d ",q[i]);
    return 0;
}
