#include<iostream>
#include<cstdio>
#include<cstring>
#define lc(t) ((t) << 1)
#define rc(t) (((t) << 1) | 1)
#define N 2000010
#define INF 1000000000
#define LL long long

template <class T> inline T &read(T &x)
{
    static int f;
    static char c; 
    for (f = 1; !isdigit(c = getchar()); ) {
        if (c == '-')
            f = -1;
    }
    for (x = 0; isdigit(c); c = getchar()) {
        x = x * 10 + c - 48;
    }
    return x *= f;
}
 
template <class T> inline void write(T x, const char p = '\n')
{
    static int top;
    static int s[30];
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    do s[++ top] = x % 10 + 48;
    while (x /= 10);
    while (top)
        putchar(s[top --]);
    putchar(p);
}

using namespace std;
int n, m;
int mn[N], mx[N], cn[N], cx[N], sn[N], sx[N]; LL sum[N];
int t_a[N], t_n[N], t_x[N], i_n[N], i_x[N];
int lb[N], rb[N];
inline void upd(register int t)
{
    sum[t] = sum[lc(t)] + sum[rc(t)];
    if (mn[lc(t)] == mn[rc(t)]) 
        mn[t] = mn[lc(t)], cn[t] = cn[lc(t)] + cn[rc(t)], sn[t] = min(sn[lc(t)], sn[rc(t)]);
    else if (mn[lc(t)] < mn[rc(t)]) 
        mn[t] = mn[lc(t)], cn[t] = cn[lc(t)], sn[t] = min(sn[lc(t)], mn[rc(t)]);
    else 
        mn[t] = mn[rc(t)], cn[t] = cn[rc(t)], sn[t] = min(mn[lc(t)], sn[rc(t)]);
    
    
    if (mx[lc(t)] == mx[rc(t)]) 
        mx[t] = mx[lc(t)], cx[t] = cx[lc(t)] + cx[rc(t)], sx[t] = max(sx[lc(t)], sx[rc(t)]);
    else if (mx[lc(t)] > mx[rc(t)]) 
        mx[t] = mx[lc(t)], cx[t] = cx[lc(t)], sx[t] = max(sx[lc(t)], mx[rc(t)]);
    else 
        mx[t] = mx[rc(t)], cx[t] = cx[rc(t)], sx[t] = max(mx[lc(t)], sx[rc(t)]);
    
}
void build(int t, int l, int r)
{
    lb[t] = l; rb[t] = r;
    if (l == r) 
    {
        int x;
        read(x);
        mn[t] = mx[t] = sum[t] = x; cn[t] = cx[t] = 1; sn[t] = INF; sx[t] = -INF;
    }
    else 
    {
        build(lc(t), l, (l + r) / 2);
        build(rc(t), (l + r) / 2 + 1, r);
        upd(t);
    }
}
inline void add(register int t, int d)
{
    sum[t] += (LL)d * (rb[t] - lb[t] + 1);
    mn[t] += d; mx[t] += d; sn[t] += d; sx[t] += d;
    t_a[t] += d;
}

template <class T> inline void chkmin(T &x, T y) { x > y && (x = y); }
template <class T> inline void chkmax(T &x, T y) { x < y && (x = y); }
inline void m_x(register int t, int d)
{
    sum[t] += (LL)cn[t] * (d - mn[t]);
    mn[t] = d; chkmax(mx[t], d);
    if (mx[t] == mn[t])
    {
        cx[t] = cn[t] = rb[t] - lb[t] + 1;
        sum[t] = (LL)mx[t] * (rb[t] - lb[t] + 1);
        sn[t] = INF; sx[t] = -INF;
    }
    else chkmax(sx[t], d);
}
inline void m_n(register int t, int d)
{
    sum[t] += (LL)cx[t] * (d - mx[t]);
    mx[t] = d; chkmin(mn[t], d);
    if (mx[t] == mn[t])
    {
        cx[t] = cn[t] = rb[t] - lb[t] + 1;
        sum[t] = (LL)mx[t] * (rb[t] - lb[t] + 1);
        sn[t] = INF; sx[t] = -INF;
    }
    else chkmin(sn[t], d);
}
inline void psdw(register int t)
{
    if (t_a[t])
    {
        add(lc(t), t_a[t]);
        add(rc(t), t_a[t]);
        t_a[t] = 0;
    }
    if (mx[lc(t)] > mx[t] && sx[lc(t)] < mx[t]) m_n(lc(t), mx[t]);
    if (mx[rc(t)] > mx[t] && sx[rc(t)] < mx[t]) m_n(rc(t), mx[t]);
    if (mn[lc(t)] < mn[t] && sn[lc(t)] > mn[t]) m_x(lc(t), mn[t]);
    if (mn[rc(t)] < mn[t] && sn[rc(t)] > mn[t]) m_x(rc(t), mn[t]);
}
namespace segment
{
    int l, r, d;
    void seg_add(int t)
    {
        if (l <= lb[t] && rb[t] <= r)
        {
            add(t, d);
            return;
        }
        psdw(t);
        if (l <= rb[lc(t)]) seg_add(lc(t));
        if (r >= lb[rc(t)]) seg_add(rc(t));
        upd(t);
    }
    void seg_m_x(int t)
    {
        if (mn[t] >= d) return;
        if (l <= lb[t] && rb[t] <= r && sn[t] > d)
        {
            m_x(t, d);
            return;
        }
        psdw(t);
        if (l <= rb[lc(t)]) seg_m_x(lc(t));
        if (r >= lb[rc(t)]) seg_m_x(rc(t));
        upd(t);
    }
    void seg_m_n(int t)
    {
        if (mx[t] <= d) return;
        if (l <= lb[t] && rb[t] <= r && sx[t] < d)
        {
            m_n(t, d);
            return;
        }
        psdw(t);
        if (l <= rb[lc(t)]) seg_m_n(lc(t));
        if (r >= lb[rc(t)]) seg_m_n(rc(t));
        upd(t);
    }
    LL get_sum(int t)
    {
        if (l <= lb[t] && rb[t] <= r)
        {
            return sum[t];
        }
        LL d = 0;
        psdw(t);
        if (l <= rb[lc(t)]) d += get_sum(lc(t));
        if (r >= lb[rc(t)]) d += get_sum(rc(t));
        return d;
    }
    int get_max(int t)
    {
        if (l <= lb[t] && rb[t] <= r)
        {
            return mx[t];
        }
        int d = -INF;
        psdw(t);
        if (l <= rb[lc(t)]) d = max(d, get_max(lc(t)));
        if (r >= lb[rc(t)]) d = max(d, get_max(rc(t)));
        return d;
    }
    int get_min(int t)
    {
        if (l <= lb[t] && rb[t] <= r)
        {
            return mn[t];
        }
        int d = INF;
        psdw(t);
        if (l <= rb[lc(t)]) d = min(d, get_min(lc(t)));
        if (r >= lb[rc(t)]) d = min(d, get_min(rc(t)));
        return d;
    }
}

int main()
{
    read(n);
    build(1, 1, n);
    read(m);
    while (m --)
    {
        using namespace segment;
        int opt;
        read(opt); read(l); read(r);
        if (opt <= 3) read(d);
        switch (opt)
        {
            case 1: seg_add(1); break;
            case 2: seg_m_x(1); break;
            case 3: seg_m_n(1); break;
            case 4: write(get_sum(1)); break;
            case 5: write(get_max(1)); break;
            case 6: write(get_min(1)); break;
        }
    }
    //write(c, ' '); write(d);
}
