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
class SumFullSet {
public:
	string isSumFullSet(vector <int> elements) {
		set<int> s;
		for(auto i=elements.begin();i!=elements.end();++i){
			s.insert(*i);
		}
		for(auto i=elements.begin();i!=elements.end();++i){
			for(auto j=elements.begin();j!=elements.end();++j)if(i!=j){
				if(!s.count(*i+*j))return "not closed";
			}
		}
		return "closed";
	}
};
