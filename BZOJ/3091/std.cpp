#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
 
typedef long long ll;
#define maxn 50010
int n,m,ch[maxn][2],size[maxn],fa[maxn],stack[maxn];
int side[maxn],next[maxn*2],toit[maxn*2],cnt;
ll key[maxn],id[maxn],s1[maxn],s2[maxn],s3[maxn];
ll lef[maxn],rig[maxn],sign1[maxn],sign2[maxn];
bool rev[maxn];
 
inline int getint()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
inline ll getlong()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
inline ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
 
inline void pushdown(int x)
{
    int lc = ch[x][0],rc = ch[x][1];
    if (rev[x])
    {
        id[x] = -id[x]; s2[x] = -s2[x];
        swap(lef[x],rig[x]);
        lef[x] = -lef[x]; rig[x] = -rig[x];
        swap(ch[x][0],ch[x][1]);
        if (lc) rev[lc] ^= 1,sign2[lc] = -sign2[lc];
        if (rc) rev[rc] ^= 1,sign2[rc] = -sign2[rc];
        rev[x] = false;
    }
    if (sign2[x])
    {
        lef[x] += sign2[x]; rig[x] += sign2[x]; id[x] += sign2[x];
        s3[x] += (sign2[x]*s2[x]<<1)+sign2[x]*sign2[x]*s1[x];
        s2[x] += sign2[x]*s1[x];
        if (lc) sign2[lc] += sign2[x];
        if (rc) sign2[rc] += sign2[x];
        sign2[x] = 0;
    }
    if (sign1[x])
    {
        s1[x] += sign1[x]*(ll)size[x];
        s2[x] += (ll)size[x]*(lef[x]+rig[x])/2*sign1[x];
        s3[x] += (rig[x]*(rig[x]+1)*((rig[x]<<1)+1)/6-(lef[x]-1)*lef[x]*((lef[x]<<1)-1)/6)*sign1[x];
        key[x] += sign1[x]; 
        if (lc) sign1[lc] += sign1[x];
        if (rc) sign1[rc] += sign1[x];
        sign1[x] = 0;
    }
}
 
inline void updata(int x)
{
    int lc = ch[x][0],rc = ch[x][1];
    if (lc) pushdown(lc); if (rc) pushdown(rc);
    size[x] = size[lc]+size[rc]+1;
    s1[x] = s1[lc]+s1[rc]+key[x];
    s2[x] = id[x]*key[x]+s2[lc]+s2[rc];
    s3[x] = id[x]*id[x]*key[x]+s3[lc]+s3[rc];
    lef[x] = rig[x] = id[x];
    if (lc) lef[x] = lef[lc];
    if (rc) rig[x] = rig[rc];
}
 
inline bool isroot(int a) { return ch[fa[a]][0] != a&&ch[fa[a]][1] != a; }
 
inline void rotate(int x)
{
    int y = fa[x],z = fa[y],l = ch[y][1]==x,r = l^1;
    if (!isroot(y)) ch[z][ch[z][1]==y] = x; fa[x] = z;
    if (ch[x][r]) fa[ch[x][r]] = y; ch[y][l] = ch[x][r];
    ch[x][r] = y; fa[y] = x;
    updata(y); updata(x);
}
 
inline void splay(int x)
{
    int top = 0,i;
    for (i = x;!isroot(i);i = fa[i]) stack[++top] = i;
    stack[++top] = i;
    while (top) pushdown(stack[top--]);
    while (!isroot(x))
    {
        int y = fa[x],z = fa[y];
        if (!isroot(y))
        {
            if ((ch[y][0]==x)^(ch[z][0]==y)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}
 
inline int access(int x)
{
    int t;
    for (t = 0;x;t = x,x = fa[x])
    {
        splay(x);
        if (ch[x][1]) sign2[ch[x][1]] -= size[ch[x][0]]+1;
        ch[x][1] = t; 
        if (t) sign2[t] += size[ch[x][0]]+1;
        updata(x);
    }
    return t;
}
 
inline void evert(int x)
{
    x = access(x);  rev[x] ^= 1;
    sign2[x] += rev[x]*(size[x]+1);
}
 
inline int find(int x)
{
    x = access(x);
    while (pushdown(x),ch[x][0]) x = ch[x][0];
    return x;
}
 
inline void cut(int x,int y)
{
    evert(x); access(y); splay(y);
    if (ch[y][0] != x||ch[x][1] != 0) return;
    ch[y][0] = fa[x] = 0;
    updata(x);
    sign2[y] -= size[x];
}
 
inline void link(int x,int y)
{
    if (find(x) == find(y)) return;
    evert(x); fa[x] = y;
}
 
inline void change(int x,int y,ll v)
{
    if (find(x) != find(y)) return;
    evert(x); x = access(y);
    sign1[x] += v;
    pushdown(x);
}
 
inline void ask(int x,int y)
{
    if (find(x) != find(y)) { printf("-1\n"); return; }
    evert(x); access(y); splay(x);
    ll up = -s3[x]+(ll)(size[x]+1)*s2[x],down = (ll)size[x]*(ll)(size[x]+1)>>1,d = gcd(up,down);
    up /= d; down /= d;
    printf("%lld/%lld\n",up,down);
}
 
inline void add(int a,int b) { next[++cnt] = side[a]; side[a] = cnt; toit[cnt] = b;  }
 
inline void ins(int a,int b) { add(a,b); add(b,a); }
 
inline void dfs(int now,int f)
{
    if (f) fa[now] = f;
    for (int i = side[now];i;i = next[i])
        if (toit[i] != f) dfs(toit[i],now);
}
 
int main()
{
	freopen("code.in","r",stdin);
	freopen("std.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i = 1;i <= n;++i)
    {
        key[i] = getlong();
        s1[i] = s2[i] = s3[i] = key[i];
        size[i] = lef[i] = rig[i] = id[i] = 1;
    }
    for (int i = 1;i < n;++i)
    {
        int a = getint(),b = getint();
        ins(a,b);
    }
    dfs(1,0);
    while (m--)
    {
        int opt = getint();
        if (opt == 3)
        {
            int u = getint(),v = getint(); ll d = getlong();
            change(u,v,d);
        }
        else
        {
            int u = getint(),v = getint();
            if (opt == 1) cut(u,v);
            else if (opt == 2) link(u,v);
            else ask(u,v);
        }
    }
    return 0;
}
