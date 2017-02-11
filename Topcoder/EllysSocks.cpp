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
const int inf=1e9;
class EllysSocks {
public:
	int getDifference(vector <int> S, int P) {
		sort(S.begin(),S.end());
		int l=0,r=inf;
		while(l<r){
			int mid=(l+r)>>1;
			int cnt=0;
			for(int i=1;i<S.size();){
				if(S[i]-S[i-1]<=mid)++cnt,i+=2;
				else ++i;
			}
			if(cnt>=P)r=mid;else l=mid+1;
		}
		return l;
	}
};
