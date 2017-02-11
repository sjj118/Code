/**************************************************************
    Problem: 1023
    User: rausen
    Language: C++
    Result: Accepted
    Time:176 ms
    Memory:161276 kb
****************************************************************/
 
#include <cstdio>
#include <algorithm>
 
using namespace std;
const int N = 50005;
const int M = 20000005;
 
struct edges{
    int next, to;
}e[M];
int first[N], dep[N], f[N];
int dfn[N], low[N], fa[N];
int a[N * 2], q[N * 2], l, r;
int n, m, tot, cnt, ans;
 
inline int read(){
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
 
    while (ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
 
inline void add_edge(int X, int Y){
    e[++tot].next = first[X];
    first[X] = tot;
    e[tot].to = Y;
}
 
void add_Edges(int x, int y){
    add_edge(x, y);
    add_edge(y, x);
}
 
void DP(int root, int p){
    int T = dep[p] - dep[root] + 1;
    for (int i = p; i != root; i = fa[i])
        a[T--] = f[i];
    a[T] = f[root];
    T = dep[p] - dep[root] + 1;
    for (int i = 1; i <= T; ++i)
        a[i + T] = a[i];
    q[1] = l = r = 1;
    for (int i = 2; i <= 2 * T; ++i){
        while (l <= r && i - q[l] > T / 2) ++l;
        ans = max(ans, a[i] + a[q[l]] + i - q[l]);
        while (l <= r && a[q[r]] - q[r] <= a[i] - i) --r;
        q[++r] = i;
    }
    for (int i = 2; i <= T; ++i)
        f[root] = max(f[root], a[i] + min(i - 1, T - i + 1));
}
 
void dfs(int p){
    low[p] = dfn[p] = ++cnt;
    int x, y;
    for (x = first[p]; x; x = e[x].next)
        if ((y = e[x].to) != fa[p]){
            if (!dfn[y]){
                fa[y] = p, dep[y] = dep[p] + 1;
                dfs(y);
                low[p] = min(low[p], low[y]);
            }else low[p] = min(low[p], dfn[y]);
            if (dfn[p] < low[y]){
                ans = max(ans, f[p] + f[y] + 1);
                f[p] = max(f[p], f[y] + 1);
            }
        }
    for (x = first[p]; x; x = e[x].next)
        if (fa[(y = e[x].to)] != p && dfn[p] < dfn[y])
            DP(p, y);
}
 
int main(){
    n = read(), m = read();
    int k, X, Y, i, j;
    for (i = 1; i <= m; ++i){
        k = read(), X = read();
        for (j = 2; j <= k; ++j){
            Y = read();
            add_Edges(X, Y);
            X = Y;
        }
    }
    dfs(1);
    printf("%d", ans);
    return 0;
}
