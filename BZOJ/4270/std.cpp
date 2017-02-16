#include <cstdio>
typedef long long ll;
void gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (b)
        gcd(b, a % b, d, y, x), y -= x * (a / b);
    else
        d = a, x = 1, y = 0;
}
ll get(ll d, ll m, ll l, ll r)
{
    if (l > r || l > m - 1)
        return -1;
    if (l == 0)
        return 0;
    if (d == 0)
        return -1;
    if (r / d > (l - 1) / d)
        return l - 1 - (l - 1) % d + d;
    ll next = get(m % d, d, d - 1 - (r - 1) % d, d - 1 - (l - 1) % d);
    if (next < 0)
        return -1;
    next -= (l + d - 1) / d * d;
    return (m - 1 - (next - 1) % m) % m;
}
int main()
{
    ll n;
    scanf("%lld", &n);
    while (n--)
    {
        ll m, d, l, r;
        scanf("%lld%lld%lld%lld", &m, &d, &l, &r);
        ll ans = get(d % m, m, l, r);
        if (ans >= 0)
        {
            ll g, x, y;
            gcd(d % m, m, g, x, y);
            m /= g;
            ans /= g;
            ans = ans * (x + m) % m;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
