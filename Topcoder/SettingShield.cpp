#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<cstdlib>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=1e5+10,inf=1e7+10;
inline void up(LL&x,LL y){if(y>x)x=y;}
inline void dn(LL&x,LL y){if(y<x)x=y;}
int n,m,h,t,prot[N],lft[N],rgt[N],delta[N];
struct Interval{
	int l,r;
}iv[N];
bool operator<(const Interval&a,const Interval&b){
	return a.l<b.l||(a.l==b.l&&a.r>b.r);
}
void unique(){
	rep(i,1,h)iv[i].l=lft[i]+1,iv[i].r=rgt[i]+1;
	sort(iv+1,iv+1+h);
	rep(i,1,h)if(iv[m].r<iv[i].r)iv[++m]=iv[i];
	iv[m+1].l=n+1;iv[m+1].r=n;
}
bool vaild(int x){
	rep(i,0,m)rep(j,iv[i].r+1,iv[i+1].l-1)if(prot[j]>x)return 0;
	return 1;
}
LL work(LL x){
	LL sum=0;
	LL tmp=0,s=0;
	for(int i=1,j=1;i<=n;++i){
		if(iv[j+1].l==i){
			if(tmp){
				sum+=tmp;
				s+=tmp;
				delta[max(i,iv[j].r+1)]+=tmp;
			}
			++j;tmp=0;
		}
		s-=delta[i];delta[i]=0;
		up(tmp,prot[i]-x-s);
	}
	if(tmp){
		sum+=tmp;
	}
	return sum+t*x;
}
class SettingShield {
public:
	LL getOptimalCost(int n, int h, int t, vector <int> val0, vector <int> a, vector <int> b, vector <int> m) {
		::n=n;::h=h;::t=t;
		prot[1]=val0[0];rep(i,2,n)prot[i]=((LL)a[0]*prot[i-1]+b[0])%m[0];
		lft[1]=val0[1];rgt[1]=val0[2];
		rep(i,2,h){
			lft[i] = min(n-1, (int)(((LL)a[1] * lft[i-1] + b[1]) % m[1]));
			LL dist = rgt[i-1] - lft[i-1];
			rgt[i] = min(n-1, (int)(lft[i] + ((LL)a[2] * dist + b[2]) % m[2]));
		}
		unique();
		int l=0,r=1e7;
		LL ans=1e18;
		while(r-l>10){
			int m1=(l+r)>>1,m2=(m1+r)>>1;
			if(!vaild(m1)){l=m1+1;continue;}
			LL x1=work(m1),x2=work(m2);
			if(x1<x2)r=m2;else l=m1;
		}
		rep(i,l,r)if(vaild(i))dn(ans,work(i));
		return ans;
	}
};
//int main(){
//	int n=555;
//	int h=120;
//	int t=4;
//	int val0[]={10000000, 301, 520};
//	int a[]={9999999, 9999998, 9999997};
//	int b[]={9995999, 0, 9919999};
//	int m[]={1999999, 9993999, 9299999};
//	SettingShield test;
//	printf("%lld",test.getOptimalCost(n,h,t,vector<int>(val0,val0+3),vector<int>(a,a+3),vector<int>(b,b+3),vector<int>(m,m+4)));
//	return 0;
//}
