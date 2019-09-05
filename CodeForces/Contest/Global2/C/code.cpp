#include<cstdio>

using namespace std;

const int N=500+10;

int n,m;
int a[N][N],b[N][N];
bool check(){
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(a[i][j]!=b[i][j])return false;
    return true;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&b[i][j]);
    for(int i=1;i<n;++i)for(int j=1;j<m;++j){
        if(a[i][j]!=b[i][j]){
            a[i][j]^=1;
            a[i][j+1]^=1;
            a[i+1][j]^=1;
            a[i+1][j+1]^=1;
        }
    }
    if(check())puts("Yes");else puts("No");
    return 0;
}
