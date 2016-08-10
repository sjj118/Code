#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
  
using namespace std;
  
typedef long long LL;
typedef double LF;
  
const int MaxP = 10201 + 15, MaxN1 = 8 + 5;
  
int T, p, n, n1, n2, m, Top, Ans;
int A[MaxN1];
  
LL Temp;
LL Fac[10][MaxP], Pr[10], Pi[10], Pa[10], Phi_Pi[10], Mi[10], Inv_Mi[10], Xi[10];
  
LL Pow(LL a, LL b, LL Mod)
{
    LL ret, f;
    ret = 1; f = a;
    while (b)
    {
        if (b & 1)
        {
            ret *= f;
            ret %= Mod;
        }
        b >>= 1;
        f *= f;
        f %= Mod;
    }
    return ret;
}
  
void Prepare()
{
    int x, SqrtX;
    x = p; SqrtX = (int)sqrt((LF)x);
    Top = 0;
    for (int i = 2; i <= SqrtX; ++i)
    {
        if (x % i != 0) continue;
        Pr[++Top] = i;
        Pa[Top] = 0;
        Pi[Top] = 1;
        while (x % i == 0)
        {
            ++Pa[Top];
            Pi[Top] *= i;
            x /= i;
        }
        Phi_Pi[Top] = Pi[Top] / Pr[Top] * (Pr[Top] - 1);
    }
    if (x > 1)
    {
        Pr[++Top] = x;
        Pa[Top] = 1;
        Pi[Top] = x;
        Phi_Pi[Top] = Pi[Top] - 1;
    }
    for (int i = 1; i <= Top; ++i)
    {
        Mi[i] = p / Pi[i];
        Inv_Mi[i] = Pow(Mi[i], Phi_Pi[i] - 1, Pi[i]);
        Fac[i][0] = 1;
        for (int j = 1; j < Pi[i]; ++j)
        {
            if (j % Pr[i] != 0) Fac[i][j] = Fac[i][j - 1] * j % Pi[i];
            else Fac[i][j] = Fac[i][j - 1];
        }
    }
}
  
struct ES
{
    LL e, f;
};
  
ES Calc(int x, int k)
{
    ES ret, tc;
    if (x < Pr[k])
    {
        ret.e = Fac[k][x];
        ret.f = 0;
        return ret;
    }
    ret.f = x / Pr[k];
    tc = Calc(x / Pr[k], k);
    ret.f += tc.f;
    ret.e = tc.e * Fac[k][x % Pi[k]] % Pi[k];
    ret.e = ret.e * Pow(Fac[k][Pi[k] - 1], x / Pi[k], Pi[k]) % Pi[k];
    return ret;
}
  
LL C(int x, int y, int k)
{
    LL ret;
    int pf;
    ES Ex, Ey, Exy;
    Ex = Calc(x, k);
    Ey = Calc(y, k);
    Exy = Calc(x - y, k);
    ret = Ex.e * Pow(Ey.e, Phi_Pi[k] - 1, Pi[k]) % Pi[k] * Pow(Exy.e, Phi_Pi[k] - 1, Pi[k]) % Pi[k];
    pf = Ex.f - Ey.f - Exy.f;
    if (pf >= Pa[k]) ret = 0;
    else ret = ret * Pow(Pr[k], pf, Pi[k]) % Pi[k];
    return ret;        
}
  
int C(int x, int y)
{
    if (x == y) return 1;
    if (x < y) return 0;
    if (y == 0) return 1;
    LL ret = 0;
    for (int i = 1; i <= Top; ++i) Xi[i] = C(x, y, i);
    for (int i = 1; i <= Top; ++i)
    {
        ret += Xi[i] * Mi[i] % p * Inv_Mi[i] % p;
        ret %= p;
    }
    return (int)ret;
}
  
void DFS(int x, int Cnt, int Sum)
{
    if (x == n1)
    {
        if (Cnt & 1) Temp -= C(m - Sum - 1, n - 1);
        else Temp += C(m - Sum - 1, n - 1);
        Temp = (Temp % p + p) % p;
        return;
    }
    DFS(x + 1, Cnt, Sum);
    DFS(x + 1, Cnt + 1, Sum + A[x + 1]);
}
  
int Solve()
{
    Temp = 0;
    DFS(1, 0, 0);
    DFS(1, 1, A[1]);   
    return (int)Temp;  
}
  
int main()
{
    scanf("%d%d", &T, &p);
    Prepare();
    for (int Case = 1; Case <= T; ++Case)
    {
        scanf("%d%d%d%d", &n, &n1, &n2, &m);
        for (int i = 1; i <= n1; ++i) scanf("%d", &A[i]);
        int Num;
        for (int i = 1; i <= n2; ++i)
        {
            scanf("%d", &Num);
            m -= Num - 1;
        }
        if (n1 > 0) Ans = Solve();
        else Ans = C(m - 1, n - 1);
        printf("%d\n", Ans);
    }
    return 0;
}
