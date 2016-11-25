#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct node
{
    int a[1100],l;
    node()
    {
        memset(a,0,sizeof(a));
        l = 1;
    }
    friend inline node operator *(int x,node &y)
    {
        node ret; ret.l = y.l+1;
        for (int i = 1;i <= y.l;++i)
        {
            ret.a[i] += y.a[i]*x;
            ret.a[i+1] += ret.a[i]/10;
            ret.a[i] %= 10;
        }
        if (ret.a[ret.l] == 0) ret.l--;
        return ret;
    }
    friend inline node operator -(node x,node y)
    {
        node z; z.l = max(x.l,y.l);
        for (int i = 1;i <= z.l;++i)
        {
            z.a[i] = x.a[i]-y.a[i];
            while (z.a[i] < 0)
                z.a[i] += 10,x.a[i+1]--;
        }
        while (z.l > 1&&z.a[z.l] == 0)z.l--;
        return z;
    }
    friend inline node operator +(node &x,int y)
    {
        node ret = x;
        ret.a[1] += y;
        for (int i = 1;i <= ret.l;++i)
        {
            if (ret.a[i] >= 10)
                ret.a[i]-=10,ret.a[i+1]++;
            else break;
        }
        if (ret.a[ret.l+1]) ret.l++;
        return ret;
    }
    inline void print()
    {
        for (int i = l;i >= 1;--i)
            printf("%d",this->a[i]);
    }
};

int n;
node g[110];
node ans;

void Readdata()
{
    scanf("%d",&n);
}

void Solve()
{
    g[1]=g[1]+3;
    g[2]=g[2]+8;
    if(n<=2){
        g[n].print();
        return;
    }
    for(int i=3;i<=n;i++)
        g[i]=3*g[i-1]-g[i-2];
    ans=3*g[n-1]-2*g[n-2];
    ans=ans+(-2);
    ans.print();
}

void Close()
{
    fclose(stdin);
    fclose(stdout);
}

int main()

{
    Readdata();
    Solve();
    Close();
}
