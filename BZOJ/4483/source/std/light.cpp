#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef double LD;

const LD pi = acos(-1);

struct PI{LD x,y; PI(LD X=0, LD Y=0){x=X, y=Y;}};
struct LI{PI p,v; LI(){} LI(PI P, PI V){p=P, v=V;}};

PI operator+(PI a, PI b){return PI(a.x+b.x, a.y+b.y);}
PI operator-(PI a, PI b){return PI(a.x-b.x, a.y-b.y);}
PI operator*(PI a, LD b){return PI(a.x*b, a.y*b);}
PI operator*(PI a, PI b){return PI(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);}
LD operator^(PI a, PI b){return a.x*b.y - a.y*b.x;}
LD dot(PI a, PI b){return a.x*b.x + a.y*b.y;}
PI ict(LI a, LI b){ return b.p + b.v * ((a.v ^ (a.p-b.p)) / (a.v ^ b.v)); }
PI vert(LI a){return PI(a.v.y, -a.v.x);}
LD lens(PI a){return sqrt(dot(a, a));}

const int N = 4e5;

int n, tot, r[N];
LD ang, len, ps[N];

LI pic[N];
PI ina[N], inb[N];

const LD eps = 1e-9;

int in(PI a, int l)
{
	return ina[l].x - eps < a.x && a.x < ina[l].y + eps
		&& inb[l].x - eps < a.y && a.y < inb[l].y + eps;
}

int go(PI p, PI v, LD L)
{
	if(L > len) return 0;
	if(in(p, 0)) return ps[++tot] = p.x, 1;
	
	LD minlen(0); LI line(p, v); int f = -1; PI th;
	for(int i=0; i<=n; i++)
	{
		PI cr = ict(pic[i], line), vv = cr - p;
		if(in(cr, i) && vv.x * v.x > -eps && vv.y * v.y > -eps)
		{
			LD curlen = lens(vv);
			if(fabs(curlen) < 1e-6) continue; // Not current
			if(f<0 || curlen < minlen) f = i, minlen = curlen, th = cr;
		}
	}
	
	if(f<0) return 0; // infinity
	if(!r[f] && f) return 0; // absorbed
	if(!f) return go(th, v, L + minlen); // goto the last
	
	// reflect
	PI vt = vert(pic[f]), o = ict(LI(p, pic[f].v), LI(th, vt));
	PI op (o.x * 2 - p.x, o.y * 2 - p.y);
	return go(th, op-th, L + minlen);
}

int main()
{
	//freopen("light.in", "r", stdin);
	//freopen("light.out", "w", stdout);
	
	scanf("%d%lf%lf", &n, &ang, &len);
	
	PI a, b;
	for(int i=1; i<=n; i++)
	{
		scanf("%lf%lf%lf%lf%d", &a.x, &a.y, &b.x, &b.y, &r[i]);
		pic[i] = LI(a, b-a);
		ina[i] = PI(min(a.x, b.x), max(a.x, b.x));
		inb[i] = PI(min(a.y, b.y), max(a.y, b.y));
	}
	scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
	pic[0] = LI(a, b-a);
	ina[0] = PI(a.x, b.x), inb[0] =  PI(a.y, a.y);
	
	LD ag = ang / 360.0 * pi, spi = pi*0.5;
	LD agstp = (ag + ag) / N;
	for(LD i=-ag; i<=ag; i+=agstp) go(PI(0, 0), PI(cos(spi+i), sin(spi+i)), 0);
	
	LD ret(0), part((b.x-a.x) / 1e4);
	sort(ps+1, ps+tot+1);
	for(int i=1; i<tot; i++) if(ps[i+1] - ps[i] < part) ret += ps[i+1] - ps[i];
	printf("%.4lf\n", ret / LD(b.x - a.x));
	
	return 0;
}