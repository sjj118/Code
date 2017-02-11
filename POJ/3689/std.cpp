
#include<iostream>
#include <cmath>
#include <algorithm>
#include<vector>
using namespace std;

#define MAX_N 100000 * 2
typedef long long  LL;

inline int compare_to_zero(long double x)
{
	if (fabs(x) < 1e-12)return 0;
	return x < 0 ? -1 : 1;
}

struct Line
{
	LL a, b, c;
} 
ls[MAX_N], // 输入直线
st[MAX_N]; // 输入st对

long double ans[MAX_N];
bool impossible[MAX_N];

// 优先斜率，截距次之的排序
inline bool cmp(const Line &a, const Line &b)
{
	LL t = a.a*b.b - a.b*b.a;
	if (t != 0)return t > 0;
	t = a.c*b.b - a.b*b.c;
	return t > 0;
}
struct Point
{
	long double x, y;
};
int stack[MAX_N];
Point p[MAX_N];

// 直线交点
inline Point intersection(const Line &la, const Line &lb)
{
	LL a = la.a, b = la.b, c = la.c;
	LL d = lb.a, e = lb.b, f = lb.c;
	LL der = a*e - b*d;
	Point ret;
	ret.x = c*e - b*f;
	ret.y = a*f - c*d;
	ret.x /= der;
	ret.y /= der;
	return ret;
}

// 点是否满足直线的约束
inline bool is_point_fit_line(const Line &l, const Point &p)
{
	return compare_to_zero(l.a * p.x + l.b * p.y - l.c) >= 0;
}

///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	int n, m;
	scanf("%d%d", &n, &m);
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lld%lld%lld", &ls[i].a, &ls[i].b, &ls[i].c);
		}
		sort(ls, ls + n, cmp);
		int size = 1;
		for (int i = 1; i < n; i++)
		{
			if (ls[i].a* ls[i - 1].b == ls[i - 1].a* ls[i].b)	continue;	// 排重
			ls[size++] = ls[i];
		}
		n = size;
		LL S, T;
		if (n == 1)
		{
			while (m--)
			{
				scanf("%lld%lld", &S, &T);
				if (S* ls[0].b != T* ls[0].a)	puts("IMPOSSIBLE"); // 平行，没有最小值，也就是最小值是无穷小
				else printf("%.5f\n", ls[0].c*S*1.0 / ls[0].a);
			}
		}
		else
		{
			// 半平面交集
			stack[0] = 0;	// 一个栈，储存的是凸包边所在直线的下标
			p[0].x = 0;		// p是最终的交集对应的点，每个点是每条边的最远点，第一个点当然是由x>=0这个半平面和第一个半平面的交点
			p[0].y = ls[0].c / (double)ls[0].b;
			stack[1] = 1;
			p[1] = intersection(ls[0], ls[1]);	// 第二个点
			int stack_size = 2;
			int ls_index;
			for (ls_index = 2; ls_index < n; ls_index++)
			{
				while (stack_size > 1)
				{
					int prev = stack[stack_size - 2];
					int top = stack[stack_size - 1];
					if (is_point_fit_line(ls[top], intersection(ls[ls_index], ls[prev]))) --stack_size;
					else
					{
						break;
					}
				}
				p[stack_size] = intersection(ls[ls_index], ls[stack[stack_size - 1]]);
				stack[stack_size++] = ls_index;
			}
			// 半平面交集求解完毕

			for (int i = 0; i < m; i++)
			{
				scanf("%lld%lld", &st[i].a, &st[i].b);
				st[i].c = i;	// 用c表示id
				impossible[i] = false;
			}

			sort(st, st + m, cmp);
			int st_index;
			for (st_index = 0; st_index < m; st_index++)
			{
				if (st[st_index].a * ls[0].b > st[st_index].b * ls[0].a) impossible[st[st_index].c] = true;	// 角度比第一条还小，这条线肯定与半平面交集不相交
				else break;
			}
			int cur = 0;
			while (cur < stack_size && st_index < m)
			{
				ls_index = stack[stack_size - 1];
				if (st[st_index].a * ls[ls_index].b < st[st_index].b * ls[ls_index].a) // 比最后一条还大，还是不相交
				{
					break;
				}
				// 角度在半平面交集的范围内，叉积由小增大
				while (cur < stack_size)
				{
					ls_index = stack[cur];
					LL det = st[st_index].a * ls[ls_index].b - st[st_index].b * ls[ls_index].a;	// 叉积
					if (det >= 0)	// 跟这条约束线的方向最相近，在此方向上取最远点作为极值点
					{
						ans[st[st_index].c] = st[st_index].a * p[cur].x + st[st_index].b * p[cur].y;
						break;
					}
					else
					{
						cur++;
						continue;
					}
				}
				st_index++;
			}
			while (st_index < m)
			{
				impossible[st[st_index].c] = true;
				st_index++;
			}
			for (st_index = 0; st_index < m; st_index++)
			{
				if (impossible[st_index])
				{
					puts("IMPOSSIBLE");
				}
				else
				{
					printf("%.5f\n", (double)ans[st_index]);
				}
			}
		}
	}
	return 0;
}
