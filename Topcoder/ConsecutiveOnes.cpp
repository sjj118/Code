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
typedef long long LL;
using namespace std;
const int N=100;
const LL inf=1e18;
inline void dn(LL&x,LL y){if(y<x)x=y;}
class ConsecutiveOnes {
public:
	LL calc(LL n,int l,int r){
		bool flag=0;
		rep(i,l,r){
			if(!((n>>i)&1))flag=1;
			n|=1ll<<i;
		}
		if(flag)rep(i,0,l-1)n^=((LL)((n>>i)&1))<<i;
		return n;
	}
	long long get(long long n, int k) {
		LL m=inf;
		rep(i,0,60-k)dn(m,calc(n,i,i+k-1));
		return m;
	}
};
