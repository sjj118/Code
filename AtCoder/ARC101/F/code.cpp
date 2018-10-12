#include<cstdio>
#include<algorithm>

using namespace std;

const int N=1e5+10,MOD=1e9+7;

int n,m,x[N],y[N],f[N];

struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
}p[N];
bool operator==(const Point&a,const Point&b){return a.x==b.x&&a.y==b.y;}
bool cmp(const Point&a,const Point&b){return a.x<b.x||(a.x==b.x&&a.y>b.y);}
struct Discretization{
    static bool cmp(int*a,int*b){return *a<*b;}
    int tot,*val[N],mv;
    void add(int&x){val[++tot]=&x;}
    void work(){
        sort(val+1,val+1+tot,cmp);
        for(int i=1,last=0;i<=tot;++i){
            if(*val[i]>last)++mv;
            last=*val[i];
            *val[i]=mv;
        }
    }
}Dl,Dr;
struct BIT{
    int arr[N];
    int lowbit(int x){return x&-x;}
    void add(int x,int t){
        for(;x<=Dr.mv;x+=lowbit(x))arr[x]=(arr[x]+t)%MOD;
    }
    int get(int x){
        int ret=0;
        for(;x;x-=lowbit(x))ret=(ret+arr[x])%MOD;
        return ret;
    }
}a;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&x[i]);
    for(int i=1;i<=m;++i)scanf("%d",&y[i]);
    int tot=0;
    for(int i=1;i<=n;++i){
        int t=lower_bound(y+1,y+1+m,x[i])-y;
        if(t==m+1||t==1)continue;
        p[++tot]=Point(x[i]-y[t-1],y[t]-x[i]);
        Dl.add(p[tot].x);
        Dr.add(p[tot].y);
    }
    n=tot;
    Dl.work();
    Dr.work();
    sort(p+1,p+1+n,cmp);
    n=unique(p+1,p+1+n)-p-1;
    int ans=1;
    for(int i=1;i<=n;++i){
        f[i]=(1+a.get(p[i].y-1))%MOD;
        ans=(ans+f[i])%MOD;
        a.add(p[i].y,f[i]);
    }
    printf("%d",ans);
    return 0;
}
