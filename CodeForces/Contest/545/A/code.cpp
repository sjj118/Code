#include<cstdio>
#include<algorithm>

using namespace std;

const int N=1000+10;

int n,m;
int row[N][N],col[N][N];
const int inf=1e9;
struct Discretizator{
    int tot,*val[N],mx;
    void init(){tot=mx=0;}
    void add(int&x){val[tot++]=&x;}
    void work(){
        sort(val,val+tot,[](int*a,int*b)->bool{return *a<*b;});
        for(int i=0,last=-inf;i<tot;++i){
            if(*val[i]>last)last=*val[i],++mx;
            *val[i]=mx;
        }
    }
}dt;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&row[i][j]);
    for(int i=1;i<=m;++i)for(int j=1;j<=n;++j)col[i][j]=row[j][i];
    for(int i=1;i<=n;++i){
        dt.init();
        for(int j=1;j<=m;++j)dt.add(row[i][j]);
        dt.work();
        row[i][0]=dt.mx;
    }
    for(int i=1;i<=m;++i){
        dt.init();
        for(int j=1;j<=n;++j)dt.add(col[i][j]);
        dt.work();
        col[i][0]=dt.mx;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            int x=row[i][j];
            int y=col[j][i];
            int ans=0;
            if(x>y)ans=max(row[i][0],col[j][0]+x-y);
            else ans=max(col[j][0],row[i][0]+y-x);
            printf("%d ",ans);
        }
        puts("");
    }
    return 0;
}
