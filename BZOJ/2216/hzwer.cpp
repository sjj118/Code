#include<ctime>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int a[500005];
double f[500005],g[500005];
struct data{int l,r,p;}q[500005];
double cal(int j,int i)
{
    return a[j]+sqrt(abs(i-j))-a[i];
}
int find(data t,int x)
{
    int l=t.l,r=t.r;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(cal(t.p,mid)>cal(x,mid))
            l=mid+1;
        else r=mid-1;
    }
    return l;
}
void dp(double *F)
{
    int head=1,tail=0;
    for(int i=1;i<=n;i++)
    {
        q[head].l++;
        if(head<=tail&&q[head].r<q[head].l)head++;
        if(head>tail||cal(i,n)>cal(q[tail].p,n))
        {
            while(head<=tail&&cal(q[tail].p,q[tail].l)<cal(i,q[tail].l))
                tail--;
            if(head>tail)
                q[++tail]=(data){i,n,i};
            else
            {
                int t=find(q[tail],i);
                q[tail].r=t-1;
                q[++tail]=(data){t,n,i};
            }
        }
        F[i]=cal(q[head].p,i);
    }
}
int main()
{
	freopen("code.in","r",stdin);freopen("hzwer.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
	cerr<<clock()<<endl;
    dp(f);
	cerr<<clock()<<endl;
    for(int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]);
	cerr<<clock()<<endl;
    dp(g);
	cerr<<clock()<<endl;
    for(int i=1;i<=n;i++)
        printf("%d\n",max(0,(int)ceil(max(f[i],g[n-i+1]))));
    return 0;
}
