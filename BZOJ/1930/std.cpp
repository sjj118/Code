#include <queue>  
#include <cstdio>  
#include <cctype>  
#include <cstring>  
#include <climits>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
   
#define INF 0x3f3f3f3f  
   
#define N 2010  
queue<int> q;  
int Edges = 0;  
struct Solver {  
    int head[N<<1], next[N*N], end[N*N], flow[N*N], cost[N*N], ind;  
    int d[N<<1], slack[N<<1], used[N<<1], id;  
    bool inq[N<<1];  
    void reset() {  
        ind = 0;  
        id = 1;  
        memset(used, 0, sizeof used);  
        memset(head, -1, sizeof head);  
    }  
    void addedge(int a, int b, int _f, int _c) {  
        int q = ind++;  
        end[q] = b;  
        next[q] = head[a];  
        head[a] = q;  
        flow[q] = _f;  
        cost[q] = _c;  
    }  
    void make(int a, int b, int _f, int _c) {  
        addedge(a, b, _f, _c);  
        addedge(b, a, 0, -_c);  
    }  
    void spfa(int S, int T) {  
        memset(d, 0x3f, sizeof d);  
        d[S] = 0;  
        inq[S] = 1, q.push(S);  
        int i, j;  
        while(!q.empty()) {  
            i = q.front();  
            q.pop();  
            inq[i] = 0;  
            for(j = head[i]; j != -1; j = next[j]) {  
                if (flow[j]) {  
                    if (d[end[j]] > d[i] + cost[j]) {  
                        d[end[j]] = d[i] + cost[j];  
                        if (!inq[end[j]]) {  
                            inq[end[j]] = 1;  
                            q.push(end[j]);  
                        }  
                    }  
                }  
            }  
        }  
        for(i = S; i <= T; ++i)  
            d[i] = d[T] - d[i];  
    }  
    bool Newlabel(int S, int T) {  
        int i, Min = INF;  
        for(i = S; i <= T; ++i)  
            if (used[i] != id && slack[i] < Min)  
                Min = slack[i];  
        if (Min == INF) return 0;  
        for(i = S; i <= T; ++i)  
            if (used[i] == id)  
                used[i] = -1, d[i] += Min;  
        return 1;  
    }  
    int Getflow(int p, int T, int maxflow) {  
        if (p == T)  
            return maxflow;  
        used[p] = id;  
        for(int j = head[p]; j != -1; j = next[j]) {  
            if (flow[j] && used[end[j]] != id && d[p] == d[end[j]] + cost[j]) {  
                int to = Getflow(end[j], T, maxflow > flow[j] ? flow[j] : maxflow);  
                if (to) {  
                    flow[j] -= to;  
                    flow[j ^ 1] += to;  
                    return to;  
                }  
            }  
            else if (flow[j])  
                slack[end[j]] = min(slack[end[j]], d[end[j]] + cost[j] - d[p]);  
        }  
        return 0;  
    }  
    int Mincost(int S, int T) {  
        int res = 0, get;  
        spfa(S, T);  
        do {  
            memset(slack, 0x3f, sizeof slack);  
            while((get = Getflow(S, T, INF)))  
                res += get * d[S], ++id;  
        }while(Newlabel(S, T));   
        return res;  
    }  
}G;  
   
struct Node {  
    int x, y;  
    void read() {  
        scanf("%d%d", &x, &y);  
    }  
    bool operator < (const Node &B) const {  
        return x < B.x || (x == B.x && y < B.y);  
    }  
}S[N];  
   
#define f(x) (x<<1)  
#define g(x) (x<<1^1)  
int main() {  
    int n;  
    scanf("%d", &n);  
       
    register int i, j;  
    for(i = 1; i <= n; ++i)  
        S[i].read();  
    sort(S + 1, S + n + 1);  
       
    G.reset();  
    G.make(0, 1, 2, 0);  
    for(i = 1; i <= n; ++i)  
        G.make(1, f(i), 1, 0), G.make(g(i), 2 * n + 2, 1, 0), G.make(f(i), g(i), 1, -1), G.make(f(i), g(i), 1, 0);  
       
    for(i = 1; i <= n; ++i) {  
        int Min = INF;  
        for(j = i + 1; j <= n; ++j) {  
            if (S[j].y < Min && S[j].y >= S[i].y)  
                G.make(g(i), f(j), 2, 0);  
            if (S[j].y >= S[i].y)  
                Min = min(Min, S[j].y);  
        }  
    }  
       
    printf("%d", -G.Mincost(0, 2 * n + 2));  
       
    return 0;  
}  
