#include<cstdio>
#include<cstring>

const int N=300000+10;

inline void up(int&x,int y){if(y>x)x=y;}
using namespace std;

int n,c[N],f[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&c[i]);
    for(int i=1;i<=n;++i)if(!f[c[i]])f[c[i]]=i;
    int semn=0;
    for(int i=1;i<=n;++i)if(i!=c[1]&&f[i])if(semn==0||f[i]<semn)semn=f[i];
    int ans=0;
    for(int i=1;i<=n;++i){
        if(c[i]==c[1])up(ans,i-semn);
        else up(ans,i-1);
    }
    printf("%d",ans);
    return 0;
}
