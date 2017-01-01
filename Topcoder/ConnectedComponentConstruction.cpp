#include<bits/stdc++.h>
#define pb push_back
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
const int N=50+5;
int n,a[N],s[N],t[N],w[N][N];
bool cmp(int a,int b){return s[a]<s[b];}
class ConnectedComponentConstruction {
public:
	vector <string> construct(vector <int> _s) {
		n=_s.size();
		rep(i,1,n)s[i]=_s[i-1];
		rep(i,1,n)a[i]=i;
		sort(a+1,a+1+n,cmp);
		vector<string> ans;
		vector<string> noans;
		rep(i,1,n)t[i]=1;
		rep(i,1,n){
			if(s[a[i]]>t[a[i]]){
				if(i==n)return noans;
				if(s[a[i]]==s[a[i+1]]){
					t[a[i+1]]+=t[a[i]];
					w[a[i]][a[i+1]]=w[a[i+1]][a[i]]=1;
				}else return noans;
			}
		}
		rep(i,1,n){
			string tmp;
			rep(j,1,n)if(w[i][j])tmp+='Y';else tmp+='N';
			ans.pb(tmp);
		}
		return ans;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
