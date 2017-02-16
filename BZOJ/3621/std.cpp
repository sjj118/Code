
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define EPS 1e-4
using namespace std;
struct Complex{
	double a,b;
	Complex() {}
	Complex(double _,double __=0):
		a(_),b(__) {}
	friend istream& operator >> (istream &_,Complex &c)
	{
		scanf("%lf%lf",&c.a,&c.b);
		return _;
	}
	friend ostream& operator << (ostream &_,const Complex &c)
	{
		printf("%.6lf %.6lf\n",c.a,c.b);
		return _;
	}
	friend Complex operator + (const Complex &c1,const Complex &c2)
	{
		return Complex(c1.a+c2.a,c1.b+c2.b);
	}
	friend Complex operator - (const Complex &c1,const Complex &c2)
	{
		return Complex(c1.a-c2.a,c1.b-c2.b);
	}
	friend Complex operator * (const Complex &c1,const Complex &c2)
	{
		return Complex(c1.a*c2.a-c1.b*c2.b,c1.a*c2.b+c1.b*c2.a);
	}
	friend Complex operator / (const Complex &c1,const Complex &c2)
	{
		double modulus=c2.a*c2.a+c2.b*c2.b;
		return Complex((c1.a*c2.a+c1.b*c2.b)/modulus,(c1.b*c2.a-c1.a*c2.b)/modulus);
	}
	friend bool operator == (const Complex &c1,const Complex &c2)
	{
		return fabs(c1.a-c2.a)<EPS && fabs(c1.b-c2.b)<EPS ;
	}
}A,B,C,points[4];
void Calculate(const Complex _A,const Complex _B,const Complex _C)
{
	Complex T=(_A-_B)/(A-B),P=(A*T-_A)/(T-1);
	if( (C-P)*T==(_C-P) )
	{
		cout<<P<<endl;
		throw true;
	}
}
int main()
{
	int T;
	for(cin>>T;T;T--)
	{
		cin>>A>>B>>C>>points[1]>>points[2]>>points[3];
		try{
			Calculate(points[1],points[2],points[3]);
			Calculate(points[1],points[3],points[2]);
			Calculate(points[2],points[1],points[3]);
			Calculate(points[2],points[3],points[1]);
			Calculate(points[3],points[1],points[2]);
			Calculate(points[3],points[2],points[1]);
		}catch(bool){}
	}
}
