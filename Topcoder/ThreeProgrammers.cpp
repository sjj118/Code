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
class ThreeProgrammers {
public:
	string validCodeHistory(string code) {
		string ret;
		for(auto i=code.begin();i!=code.end();++i)++cnt[*i-'A'];
		if(cnt[2]>=cnt[1]){
			if(cnt[0]<cnt[2]-1)
		}
	}
};
