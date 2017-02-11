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
const int N=50+5;
int a[N],d[10],n,tot;
pair<int,int> p[N*7];
bool cmp(const pair<int,int>&a,const pair<int,int>&b){
	return a.fi<b.fi||(a.fi==b.fi&&a.se>b.se);
}
class ReplacingDigit {
public:
	int getMaximumStockWorth(vector <int> A, vector <int> D) {
		int pow10[]={1,1e1,1e2,1e3,1e4,1e5,1e6,1e7};
		int n=A.size();
		rep(i,1,n)a[i]=A[i-1];
		rep(i,1,9)d[i]=D[i-1];
		rep(i,1,n){
			int x=a[i],l=0;
			while(x)p[++tot]=mp(l++,x%10),x/=10;
		}
		int ans=0;
		rep(i,1,n)ans+=a[i];
		sort(p+1,p+1+tot,cmp);
		per(i,9,1)while(d[i]--){
			while(tot&&p[tot].se>=i)--tot;
			if(tot)ans+=pow10[p[tot].fi]*(i-p[tot].se),--tot;
		}
		return ans;
	}
};
