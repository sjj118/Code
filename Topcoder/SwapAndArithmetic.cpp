#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;

class SwapAndArithmetic {
public:
	string able(vector <int> x) {
		sort(x.begin(),x.end());
		int d=x[1]-x[0];
		bool ans=1;
		rep(i,1,x.size()-2)if(x[i+1]-x[i]!=d)ans=0;
		if(ans)return "Possible";else return "Impossible";
	}
};
