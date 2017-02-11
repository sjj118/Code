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
#define rep(i,x,y) for(LL i=(x);i<=(y);++i)
#define per(i,x,y) for(LL i=(x);i>=(y);--i)
typedef long long LL;
const LL inf=1e18+7;

inline void dn(LL&x,LL y){if(y<x)x=y;}
class MultiplyAddPuzzle {
public:
	long long minimalSteps(long long s, long long t, long long a, long long b) {
		if(s==t)return 0;
		if(b==0){
			if(t==0)return s!=0;
			if(a==0)return -1;
			if(s<=t&&s%a==t%a)return (t-s)/a;
			if(t%a==0)return 1+t/a;
			return -1;
		}
		if(b==1){
			if(s>t)return -1;
			if(a==0)return -1;
			if(s%a!=t%a)return -1;
			return (t-s)/a;
		}
		if(a==0){
			if(s==0){
				if(t==0)return 0;
				return -1;
			}
			if(t<s)return -1;
			if(t%s)return -1;
			t/=s;
			LL ans=0;
			while(t!=1){
				if(t%b)return -1;
				t/=b;++ans;
			}
			return ans;
		}
		if(t<s)return -1;
		if(s==0){
			LL w=t;
			if(w%a==0){
				w/=a;
				LL tmp=0;
				LL d=-1;
				while(w){
					tmp+=w%b;
					w/=b;
					++d;
				}
				return tmp+d;
			}
			return -1;
		}
		LL ans=inf;
		LL d=0,bd=1;
		while(1){
			LL w=t-s*bd;
			if(w%a==0){
				w/=a;
				LL tmp=0;
				rep(i,0,d){
					tmp+=w%b;
					w/=b;
				}
				tmp+=w*b;
				dn(ans,tmp+d);
			}
			if(t/s/bd/b==0)break;
			++d;bd*=b;
		}
		if(ans==inf)return -1;
		return ans;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
