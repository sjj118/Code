#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 16384 + 5
#define Mod 1004535809
#define g 3
 
int n, p, x, m, len, w, d, root, inv_len, ans;
int T[N], Num[N], Pos[N];
int A[N], B[N], C[N], Rev[N], e[2][N];
 
inline int power(int u, int v, int p)
{
    int res = 1;
    for (; v; v >>= 1)
    {
        if (v & 1) res = (LL) res * u % p;
        u = (LL) u * u % p;
    }
    return res;
}
 
inline void Init()
{
    scanf("%d%d%d%d", &n, &p, &x, &m);
    for (int i = 1; i <= m; i ++)
        scanf("%d", T + i);
    for (len = p << 1; len != (len & -len); len += (len & -len)) ;
    for (int i = len; i > 1; i >>= 1) d ++;
    inv_len = power(len, Mod - 2, Mod);
    w = power(g, (Mod - 1) / len, Mod);
}
 
inline bool Judge(int x, int p)
{
    for (int i = 2; i * i <= p; i ++)
        if ((p - 1) % i == 0 && power(x, (p - 1) / i, p) == 1) return 0;
    return 1;
}
 
inline int Find_Root(int p)
{
    if (p == 2) return 1;
    int res = 2;
    for (; !Judge(res, p); res ++) ;
    return res;
}
 
inline void Prepare()
{
    root = Find_Root(p);
    for (int i = 0; i < p - 1; i ++)
    {
        Num[i] = !i ? 1 : Num[i - 1] * root % p;
        Pos[Num[i]] = i;
    }
}
 
inline int Inc(int u, int v)
{
    return u + v - (u + v >= Mod ? Mod : 0);
}
 
inline void FFT(int *Ar, int op)
{
    for (int i = 0; i < len; i ++)
        if (Rev[i] > i) swap(Ar[i], Ar[Rev[i]]);
    for (int k = 1, s = 1; k < len; k <<= 1, s ++)
        for (int i = 0; i < len; i ++)
        {
            if (i & k) continue ;
            int t = (i & k - 1) << d - s;
            int u = Inc(Ar[i], (LL) Ar[i + k] * e[op][t] % Mod);
            int v = Inc(Ar[i], Mod - ((LL) Ar[i + k] * e[op][t] % Mod));
            Ar[i] = u, Ar[i + k] = v;
        }
}
 
inline void Convol(int *U, int *V)
{
    for (int i = 0; i < len; i ++)
        C[i] = V[i];
    FFT(U, 0), FFT(C, 0);
    for (int i = 0; i < len; i ++)
        U[i] = (LL) U[i] * C[i] % Mod;
    FFT(U, 1);
    for (int i = 0; i < len; i ++)
        U[i] = (LL) U[i] * inv_len % Mod;
    for (int i = len - 1; i >= p - 1; i --)
    {
        U[i - p + 1] = Inc(U[i - p + 1], U[i]);
        U[i] = 0;
    }
}
 
inline void Solve()
{
    A[0] = 1;
    for (int i = 1; i <= m; i ++)
    {
        if (T[i] == 0) continue ;
        B[Pos[T[i]]] ++;
    }
    for (int i = 0, inv_w = power(w, Mod - 2, Mod); i < len; i ++)
    {
        e[0][i] = !i ? 1 : (LL) e[0][i - 1] * w % Mod;
        e[1][i] = !i ? 1 : (LL) e[1][i - 1] * inv_w % Mod;
        for (int j = 0; j < d; j ++)
            if ((i >> j) & 1) Rev[i] += 1 << (d - j - 1);
    }
    for (; n; n >>= 1)
    {
        if (n & 1) Convol(A, B);
        Convol(B, B);
    }
    ans = A[Pos[x]];
}
 
int main()
{
        freopen("code.in", "r", stdin);
        freopen("std.out", "w", stdout);
     
    Init();
    Prepare();
    Solve();
    printf("%d\n", ans);
     
    return 0;
}
