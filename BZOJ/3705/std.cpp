
#include <cstdio>
#include <cstring>

template<class T>
inline T min(T a, T b) {
    return (a < b ? a : b);
}

const int kMaxN = 1000, kMaxM = 1000;
const int kMaxR = kMaxN * 2 - 1, kMaxC = kMaxM * 2 - 1;
const int kBufSize = 1999;
int n, m, v[kMaxR][kMaxC];
int row[kMaxR][kMaxC], col[kMaxC][kMaxR];
int tmp[kBufSize];
int g[11][kBufSize], log2[kBufSize + 1];
int f[kMaxR][kMaxC];

void PreCalc(int *arr, int sz) {
    for (int i = 1, k = 0; i < sz; ++ i) {
        int p = k + arr[k];
        if (p > i && i + arr[2 * k - i] < p) arr[i] = arr[2 * k - i];
        else {
            if (p > i) arr[i] = p - i;
            while (i - arr[i] - 1 >= 0 && i + arr[i] + 1 < sz && tmp[i - arr[i] - 1] == tmp[i + arr[i] + 1]) ++ arr[i];
            k = i;
        }
    }
}

inline int AskMin(int l, int r) {
    int st = log2[r - l + 1];
    return min(g[st][l], g[st][r - (1 << st) + 1]);
}

int main() {
    for (int i = 2; i <= kBufSize; ++ i) {
        log2[i] = log2[i - 1];
        if (!(i & (i - 1))) ++ log2[i];
    }
    scanf("%d%d", &n, &m);
    n = n * 2 - 1, m = m * 2 - 1;
    for (int i = 0; i < n; i += 2)
        for (int j = 0; j < m; j += 2) scanf("%d", &v[i][j]);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) tmp[j] = v[i][j];
        PreCalc(row[i], m);
    }
    for (int j = 0; j < m; ++ j) {
        for (int i = 0; i < n; ++ i) tmp[i] = v[i][j];
        PreCalc(col[j], n);
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) g[0][j] = col[j][i];
        for (int k = 1; (1 << k) <= m; ++ k)
            for (int j = 0; j < m; ++ j) {
                g[k][j] = g[k - 1][j];
                if (j + (1 << (k - 1)) < m) g[k][j] = min(g[k][j], g[k - 1][j + (1 << (k - 1))]);
            }
        for (int j = 0, las = 0; j < m; ++ j) {
            while (AskMin(las, j) < j - las) ++ las;
            f[i][j] = min(f[i][j], j - las);
        }
        for (int j = m - 1, las = m - 1; j >= 0; -- j) {
            while (AskMin(j, las) < las - j) -- las;
            f[i][j] = min(f[i][j], las - j);
        }
    }
    for (int j = 0; j < m; ++ j) {
        for (int i = 0; i < n; ++ i) g[0][i] = row[i][j];
        for (int k = 1; (1 << k) <= n; ++ k)
            for (int i = 0; i < n; ++ i) {
                g[k][i] = g[k - 1][i];
                if (i + (1 << (k - 1)) < n) g[k][i] = min(g[k][i], g[k - 1][i + (1 << (k - 1))]);
            }
        for (int i = 0, las = 0; i < n; ++ i) {
            while (AskMin(las, i) < i - las) ++ las;
            f[i][j] = min(f[i][j], i - las);
        }
        for (int i = n - 1, las = n - 1; i >= 0; -- i) {
            while (AskMin(i, las) < las - i) -- las;
            f[i][j] = min(f[i][j], las - i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j)
            if (v[i][j])
                ans += (f[i][j] >> 1) + 1;
            else if ((i & 1) && (j & 1))
                ans += (f[i][j] + 1) >> 1;
    printf("%d", ans);
    return 0;
}
