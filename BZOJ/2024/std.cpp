
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define M 202
using namespace std;
struct Big_Int{
	#define BASE 1000
	int num[200],cnt;
	Big_Int() {}
	Big_Int(int _)
	{
		memset(num,0,sizeof num);
		num[cnt=1]=_;
	}
	Big_Int& operator = (int x)
	{
		return *(new (this)Big_Int(x));
	}
	Big_Int& operator += (const Big_Int &x)
	{
		int i;
		cnt=max(cnt,x.cnt);
		for(i=1;i<=cnt;i++)
		{
			num[i]+=x.num[i];
			if(num[i]>=BASE)
				num[i+1]+=num[i]/BASE,num[i]%=BASE;
		}
		if(num[cnt+1]) ++cnt;
		return *this;
	}
	Big_Int operator + (const Big_Int &x) const
	{
		Big_Int re=*this;re+=x;return re;
	}
	Big_Int& operator -= (const Big_Int &x)
	{
		int i;
		for(i=1;i<=cnt;i++)
		{
			num[i]-=x.num[i];
			while(num[i]<0)
				num[i+1]--,num[i]+=BASE;
		}
		while( cnt>0 && !num[cnt] ) --cnt;
		return *this;
	}
	Big_Int operator - (const Big_Int &x) const
	{
		Big_Int re=*this;re+=x;return re;
	}
	friend Big_Int operator * (const Big_Int &x,const Big_Int &y)
	{
		int i,j;
		Big_Int re=0;
		for(i=1;i<=x.cnt;i++)
			for(j=1;j<=y.cnt;j++)
				re.num[i+j-1]+=x.num[i]*y.num[j];
		re.cnt=x.cnt+y.cnt;
		for(i=1;i<=re.cnt;i++)
			if(re.num[i]>=BASE)
				re.num[i+1]+=re.num[i]/BASE,re.num[i]%=BASE;
		if(!re.num[re.cnt]) re.cnt--;
		return re;
	}
	Big_Int& operator *= (const Big_Int &x)
	{
		return *this=*this*x;
	}
	friend ostream& operator << (ostream &_,Big_Int &x)
	{
		int i;
		printf("%d",x.num[x.cnt]);
		for(i=x.cnt-1;i>0;i--)
			printf("%03d",x.num[i]);
		return _;
	}
}f[M][M],g[M],C[M][M],fac[M],ans;
int n,k;
int a[M],b[M],next[M];
int main()
{
	freopen("code.in","r",stdin);freopen("std.out","w",stdout);
	int i,j;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	
	for(j=1,i=1;i<=n;i++)
	{
		for(;j<=n&&b[j]<=a[i];j++);
		next[i]=j-1;
	}

	for(i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	for(fac[0]=1,i=1;i<=n;i++)
		fac[i]=fac[i-1]*i;

	f[0][0]=1;
	for(i=1;i<=n;i++)
	{
		f[i][0]=1;
		for(j=1;j<=i;j++)
			f[i][j]=f[i-1][j]+f[i-1][j-1]*max(next[i]-(j-1),0);
	}

	for(i=n;i>=n-k;i--)
	{
		g[i]=f[n][i]*fac[n-i];
		for(j=i+1;j<=n;j++)
			g[i]-=g[j]*C[j][i];
		ans+=g[i];
	}
	
	cout<<ans<<endl;
	return 0;
}


