#include<map>
#include<set>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 1000000000
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,Log[100005];
char ch[100005];
struct SA{
	int p,q,k;
	int sa[2][100005],rk[2][100005],mn[17][100005];
	int a[100005],h[100005],v[100005];ll s[100005];
	SA(){
		p=0,q=1;
	}
	void mul(int *sa,int *rk,int *SA,int *RK){
		for(int i=1;i<=n;i++)v[rk[sa[i]]]=i;
		for(int i=n;i;i--)
			if(sa[i]>k)SA[v[rk[sa[i]-k]]--]=sa[i]-k;
		for(int i=n-k+1;i<=n;i++)SA[v[rk[i]]--]=i;
		for(int i=1;i<=n;i++)
			RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i-1]]!=rk[SA[i]]||rk[SA[i-1]+k]!=rk[SA[i]+k]);
	}
	void getsa(){
		for(int i=1;i<=n;i++)v[a[i]]++;
		for(int i=1;i<=30;i++)v[i]+=v[i-1];
		for(int i=1;i<=n;i++)sa[p][v[a[i]]--]=i;
		for(int i=1;i<=n;i++)
			rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(a[sa[p][i]]!=a[sa[p][i-1]]);
		for(k=1;k<n;k<<=1,swap(p,q))
			mul(sa[p],rk[p],sa[q],rk[q]);
		for(int k=0,i=1;i<=n;i++)
		{
			int j=sa[p][rk[p][i]-1];
			while(a[i+k]==a[j+k])k++;
			h[rk[p][i]]=k;if(k)k--;			
		}
	}
	void pre(){
		for(int i=1;i<=n;i++)a[i]=ch[i]-'a'+1;
		getsa();
		for(int i=1;i<=n;i++)mn[0][i]=h[i];
		for(int i=1;i<=Log[n];i++)
			for(int j=1;j<=n;j++)
				if(j+(1<<i)-1<=n)
					mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
				else break;
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+n-sa[p][i]+1-h[i];
	}
	int query(int a,int b){
		a=rk[p][a],b=rk[p][b];
		if(a>b)swap(a,b);a++;
		int t=Log[b-a+1];
		return min(mn[t][a],mn[t][b-(1<<t)+1]);
	}
	void print(){
		for(int i=2;i<=n;i++)printf("%d ",h[i]);
	}
}A,B;
int main()
{
	freopen("code.in","r",stdin);freopen("brute.out","w",stdout);
	Log[0]=-1;for(int i=1;i<=100000;i++)Log[i]=Log[i>>1]+1;
	n=read();m=read();
	scanf("%s",ch+1);A.pre();
	reverse(ch+1,ch+n+1);B.pre();
	for(int i=1;i<=m;i++)
	{
		ll l=read(),r=read(),id,a1,a2,b1,b2,ans=0;
		if(l>A.s[n]||r>A.s[n]){puts("-1");continue;}
		id=lower_bound(A.s+1,A.s+n+1,l)-A.s;
		a1=A.sa[A.p][id];
		b1=A.sa[A.p][id]+A.h[id]-1+l-A.s[id-1];
		id=lower_bound(A.s+1,A.s+n+1,r)-A.s;
		a2=A.sa[A.p][id];
		b2=A.sa[A.p][id]+A.h[id]-1+r-A.s[id-1];
		ll t=(a1==a2)?inf:A.query(a1,a2);
		t=min(t,min(b1-a1+1,b2-a2+1));ans+=t*t;
		t=(n-b1+1==n-b2+1)?inf:B.query(n-b1+1,n-b2+1);
		t=min(t,min(b1-a1+1,b2-a2+1));ans+=t*t;
		printf("%lld\n",ans);
	}
	return 0;
}
