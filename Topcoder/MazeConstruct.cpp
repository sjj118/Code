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
class MazeConstruct {
public:
	vector <string> construct(int k) {
		vector<string> ret;
		if(k<=49){
			string line;
			rep(i,0,k)line+='.';
			ret.pb(line);
			return ret;
		}
		string line;
		rep(i,1,50)line+='.';
		if(k<=98){
			int m=50,n=k-m+2;
			ret.pb(line);
			string tmp;
			rep(i,1,49)tmp+='#';
			tmp+='.';
			rep(i,1,n-1)ret.pb(tmp);
			return ret;
		}
		int n=50,m=50;
		if(k&1)n=49;
		string rhole;
		rep(i,1,m-1)rhole+='#';rhole+='.';
		string lhole;
		lhole+='.';rep(i,1,m-1)lhole+='#';
		k-=n+m-2;
		while(k>=49*2){
			ret.pb(line);
			ret.pb(rhole);
			ret.pb(line);
			ret.pb(lhole);
			n-=4;
			k-=49*2;
		}
		if(k){
			ret.pb(line);
			ret.pb(rhole);
			ret.pb(line);
			string tmp;
			rep(i,1,m-k/2)tmp+='.';
			rep(i,1,k/2)tmp+='#';
			ret.pb(tmp);
			n-=4;
		}
		rep(i,1,n)ret.pb(line);
		return ret;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
