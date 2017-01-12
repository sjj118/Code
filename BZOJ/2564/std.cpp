#include<cstdio>
#include<cmath>
#include<algorithm>
const int MAXN=500010;
typedef long long ll;
struct P{ll x,y;};
bool cmp(const P&a,const P&b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
P operator+(const P&a,const P&b){return (P){a.x+b.x,a.y+b.y};}
P operator-(const P&a,const P&b){return (P){a.x-b.x,a.y-b.y};}
ll dot(const P&a,const P&b){return a.x*b.x+a.y*b.y;}
ll cross(const P&a,const P&b){return a.x*b.y-a.y*b.x;}
void gettb(P*a,int n,P*t,int&t0)
{
    std::sort(a+1,a+1+n,cmp);int i,k;
    for(i=1;i<=n;i++)
    {
        while(t0>1&&cross(a[i]-t[t0-1],t[t0]-t[t0-1])>=0)t0--;
        t[++t0]=a[i];
    }k=t0;
    for(i=n-1;i;i--)
    {
        while(t0>k&&cross(a[i]-t[t0-1],t[t0]-t[t0-1])>=0)t0--;
        t[++t0]=a[i];
    }t0--;
}
 
P a[MAXN],b[MAXN],t[MAXN];
int n,m,t0=0;
int main()
{
    scanf("%d%d",&n,&m);int i,j;
    for(i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
    for(i=1;i<=m;i++)scanf("%lld%lld",&b[i].x,&b[i].y);
    gettb(a,n,t,t0);for(i=1;i<=t0;i++)a[i-1]=t[i];n=t0;t0=0;
    gettb(b,m,t,t0);for(i=1;i<=t0;i++)b[i-1]=t[i];m=t0;t0=0;
    P x,y;
    for(i=0,j=0,t[++t0]=a[i]+b[j];i<n||j<m;)
    {
        x=a[i%n]+b[(j+1)%m];
        y=a[(i+1)%n]+b[j%m];
        if(cross(x-t[t0],y-t[t0])>=0)
        {
            t[++t0]=x;j++;
        }
        else
        {
            t[++t0]=y;i++;
        }
    }t0--;ll s=0;
    for(i=2;i<t0;i++)s+=cross(t[i]-t[1],t[i+1]-t[1]);
    printf("%lld",s);
}
