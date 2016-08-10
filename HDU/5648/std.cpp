#include<cstdio>
__int16 g[135000000];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        long long ans=0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int a=i|j;
            int b=i&j;
            int p=a*(a+1)/2+b;
            if(g[p]) ans+=g[p];
            else
            {
                while(b)
                {
                    int tmp=a%b;
                    a=b;
                    b=tmp;
                }
                ans+=g[p]=a;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
