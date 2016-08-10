#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct seg1
{
    ll l:28, r:28, sum:36, lazy:36;
}p1[20000005];
struct operation
{
    ll op, l, r, val;
}op[50005];
ll n, p2[150005], ptot, cd[50005], ctot, ql, qr, val;
  
void push_up(ll o, ll l, ll r)
{
    p1[o].sum = p1[p1[o].l].sum + p1[p1[o].r].sum + p1[o].lazy * (r - l + 1);
}
  
void push_down(ll o, ll l, ll r)
{
    ll mid = (l + r) >> 1;
    if(!p1[o].l) p1[o].l = ++ptot;
    if(!p1[o].r) p1[o].r = ++ptot;
    if(p1[o].lazy)
    {
        p1[p1[o].l].lazy += p1[o].lazy;
        p1[p1[o].r].lazy += p1[o].lazy;
        p1[p1[o].l].sum += p1[o].lazy * (mid - l + 1);
        p1[p1[o].r].sum += p1[o].lazy * (r - mid);
        p1[o].lazy = 0;
    }
}
  
void update1(ll o, ll l, ll r)
{
    ll mid = (l + r) >> 1;
    if(ql <= l && r <= qr)
    {
        p1[o].sum += r - l + 1, p1[o].lazy++;
        return;
    }
    push_down(o, l, r);
    if(ql <= mid) update1(p1[o].l, l, mid);
    if(mid < qr) update1(p1[o].r, mid + 1, r);
    push_up(o, l, r);
}
  
void update2(ll o, ll l, ll r)
{
    ll mid = (l + r) >> 1;
    if(!p2[o]) p2[o] = ++ptot;
    update1(p2[o], 1, n);
    if(l == r) return;
    if(val <= mid) update2(o << 1, l, mid);
    else update2(o << 1 | 1, mid + 1, r);
}
  
ll query1(ll o, ll l, ll r)
{
    ll mid = (l + r) >> 1, cnt = 0;
    if(ql <= l && r <= qr) return p1[o].sum;
    push_down(o, l, r);
    if(ql <= mid) cnt = query1(p1[o].l, l, mid);
    if(mid < qr) cnt += query1(p1[o].r, mid + 1, r);
    return cnt;
}
  
ll query2(ll o, ll l, ll r, ll rk)
{
    ll mid = (l + r) >> 1;
    if(!p2[o]) p2[o] = ++ptot;
    val = query1(p2[o << 1 | 1], 1, n);
    if(l==r){
    	if(query1(p2[o],1,n)>=rk)return l;
    	else return -1;
    }
    if(val < rk) return query2(o << 1, l, mid, rk - val);
    return query2(o << 1 | 1, mid + 1, r, rk);
}
  
int main()
{
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
    ll m;
    scanf("%lld%lld", &n, &m);
    for(ll i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld%lld", &op[i].op, &op[i].l, &op[i].r, &op[i].val);
        if(op[i].op == 1) cd[++ctot] = op[i].val;
    }
    sort(cd + 1, cd + ctot + 1);
    for(int i = 1; i <= m; i++)
        if(op[i].op == 1)
            op[i].val = lower_bound(cd + 1, cd + ctot + 1, op[i].val) - cd;
    for(ll i = 1; i <= m; i++)
        if(op[i].op == 1)
        {
            ql = op[i].l, qr = op[i].r, val = op[i].val;
            update2(1, 1, ctot);
        }
        else
        {
            ql = op[i].l, qr = op[i].r;
            int t=query2(1, 1, ctot, op[i].val);
            if(t==-1)printf("%d\n",-n);else printf("%lld\n", cd[t]);
        }
    return 0;
}
