#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long int lli;
lli p;

lli pow_mod(lli a, lli b) {
	lli ret = 1;
	for(; b; b>>=1, a = a*a % p)
		if(b & 1) ret = ret*a % p;
	return ret;
}

lli log_mod(lli a, lli b) {
	lli m, v, e = 1;
	m = (lli)(sqrt(p) + 0.5);
	v = pow_mod(pow_mod(a, m), p-2);
	map <lli,lli> x;
	x[1] = 0;
	for(int i = 1; i < m; i++) {
		e = e*a % p;
		if(!x.count(e)) x[e] = i;
	}
	for(int i = 0; i < m; i++) {
		if(x.count(b)) return i*m + x[b];
		b = b*v % p;
	}
	return -2;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		lli a, b, x1, xn;
		scanf("%lld %lld %lld %lld %lld", &p, &a, &b, &x1, &xn);
		if(x1 == xn) { puts("1"); continue; }
		if(a == 0) {
			if(xn == b) puts("2"); else puts("-1");
			continue;
		}
		if(a == 1) {
			int ans = ((xn-x1)%p+b) * pow_mod(b, p-2) % p;
			if(ans < 0) ans += p;
			if(ans > 0) printf("%d\n", ans);
			else if(b == 0) puts("-1");
			else printf("%d\n", p);
			continue;
		}
		lli aa = (xn*(1-a)-b) % p, bb = pow_mod((x1*(1-a)-b) % p, p-2);
		printf("%lld\n", log_mod(a, aa * bb % p) + 1);
	}
	return 0;
}
