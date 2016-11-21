#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#ifdef WIN32
    #define LL "%I64d"
#else
    #define LL "%lld"
#endif

#ifdef CT
    #define debug(...) printf(__VA_ARGS__)
    #define setfile() 
#else
    #define debug(...)
    #define filename ""
    #define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);
#endif

#define R register
#define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 15, stdin), S == T) ? EOF : *S++)
#define dmax(_a, _b) ((_a) > (_b) ? (_a) : (_b))
#define dmin(_a, _b) ((_a) < (_b) ? (_a) : (_b))
#define cmax(_a, _b) (_a < (_b) ? _a = (_b), 0 : 0)
#define cmin(_a, _b) (_a > (_b) ? _a = (_b), 0 : 0)
char B[1 << 15], *S = B, *T = B;
inline int FastIn()
{
    R char ch; R int cnt = 0; R bool minus = 0;
    while (ch = getc(), (ch < '0' || ch > '9') && ch != '-') ;
    ch == '-' ? minus = 1 : cnt = ch - '0';
    while (ch = getc(), ch >= '0' && ch <= '9') cnt = cnt * 10 + ch - '0';
    return minus ? -cnt : cnt;
}
#define maxn 210
#define maxm 10010
int n, m, Fa[maxn];
struct Poi
{
    int x, y;
    inline bool operator < (const Poi &that) const
    {
        return x * y == that.x * that.y ? x < that.x : x * y < that.x * that.y;
    }
    inline Poi operator - (const Poi &that) const
    {
        return (Poi) {x - that.x, y - that.y};
    }
    inline int operator * (const Poi &that) const
    {
        return x * that.y - y * that.x;
    }
}ans, xx, yy;
struct Edge
{
    int a, b, c, t, w;
    inline bool operator < (const Edge &that) const {return w < that.w; }
}e[maxm];
int Find(R int x) {return Fa[x] == x ? x : Fa[x] = Find(Fa[x]); }
inline Poi mst()
{
    std::sort(e + 1, e + m + 1);
    for (R int i = 1; i <= n; ++i) Fa[i] = i;
    R int ans1 = 0, ans2 = 0, ncnt = 0;
    for (R int i = 1; i <= m && ncnt < n; ++i)
    {
        R int f1 = Find(e[i].a), f2 = Find(e[i].b);
        if (f1 != f2)
        {
            ans1 += e[i].c;
            ans2 += e[i].t;
            Fa[f1] = f2;
            ++ncnt;
        }
    }
    R Poi ret = (Poi) {ans1, ans2};
    ans = dmin(ans, ret);
    return ret;
}
void solve(R Poi a, R Poi b, R int dep)
{
    for (R int i = 1; i <= m; ++i)
        e[i].w = e[i].t * (b.x - a.x) - e[i].c * (b.y - a.y);
    R Poi c = mst();
    if ((b - a) * (c - a) < 0 && dep <= 10) solve(a, c, dep + 1), solve(c, b, dep + 1);
}
int main()
{
//  setfile();
	freopen("code.in","r",stdin);
    n = FastIn(), m = FastIn();
    ans = (Poi) {23333, 66666};
    for (R int i = 1; i <= m; ++i)
        e[i] = (Edge) {FastIn() + 1, FastIn() + 1, FastIn(), FastIn(), 0};
    for (R int i = 1; i <= m; ++i) e[i].w = e[i].c; xx = mst();
    for (R int i = 1; i <= m; ++i) e[i].w = e[i].t; yy = mst();
    solve(xx, yy, 0);
    printf("%d %d\n", ans.x, ans.y );
    return 0;
}
