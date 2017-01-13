#include <cstdio>
const int N = 100010, p = 998244353;
int b[2][N], a[N], n, m, inv[N], x, fac, d[N], ans;
int power(int t, int k)
{
	int f = 1;
	for (; k; k >>= 1, t = 1ll * t * t % p)
		if (k & 1)
			f = 1ll * f * t % p;
	return f;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i <= m; ++i)
		scanf("%d", &b[0][i]);
	a[0] = b[0][0];
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 0, t=i&1; j <= m - i; ++j)
			b[t][j] = (b[t^1][j+1] - b[t^1][j] + p) % p;
		a[i] = b[i&1][0];
	}
/*	for (int i = 0; i <=m; ++i,puts(""))
		for(int j=0;j<=m;j++)printf("%d ",a[i][j]);
*/
	for (int i = fac = 1; i <= m; ++i)
		fac = 1ll * fac * i % p;
	inv[m] = power(fac, p-2); //printf("%d\n",inv[m]);
	for (int i = m - 1; i >= 0; --i)
		inv[i] = 1ll * inv[i+1] * (i+1) % p;
	for (int i = 0; i <= m; ++i)
		d[i] = 1ll * a[i] * inv[i] % p;
//	for(int i=0;i<=m;i++)printf("%d ",d[i]);puts("");
	int fac_n = 1, powx = 1;
	for (int i = 0; i <= m; ++i)
	{
		ans = (ans + 1ll * fac_n * powx % p * d[i]) % p;
		powx = 1ll * powx * x % p;
		fac_n = 1ll * fac_n * (n-i+p) % p;
	}
	printf("%d\n", ans);
	return 0;
}
