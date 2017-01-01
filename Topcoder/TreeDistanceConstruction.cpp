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
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
const int N=50+5;
int n,d[N],a[N],nxt[N],st[N],l,p[N],tot;
class TreeDistanceConstruction {
public:
	vector <int> construct(vector <int> _d) {
		vector<int>noans;
		n=_d.size();
		rep(i,1,n)d[i]=_d[i-1];
		per(i,n,1)nxt[i]=st[d[i]],st[d[i]]=i;
		rep(i,1,n)if(st[i])l=i;
		per(i,l,l/2+1){
			if(st[i])p[++tot]=st[i],st[i]=nxt[st[i]];
			else return noans;
		}
		if((l&1)==0){
			if(st[l/2])p[++tot]=st[l/2],st[l/2]=nxt[st[l/2]];
			else return noans;
		}
		rep(i,l/2+1,l){
			if(st[i])p[++tot]=st[i],st[i]=nxt[st[i]];
			else return noans;
		}
		rep(i,1,(l+1)/2)if(st[i])return noans;
		vector<int> ans;
		rep(i,1,tot-1)ans.pb(p[i]-1),ans.pb(p[i+1]-1);
		rep(i,(l+1)/2+1,l){
			while(st[i]){
				ans.pb(p[i]-1);
				ans.pb(st[i]-1);
				st[i]=nxt[st[i]];
			}
		}
		return ans;
	}
};
// BEGIN CUT HERE 
int main(){
        TreeDistanceConstruction ___test; 
		vector<int>x;
		x.pb(3);x.pb(2);x.pb(2);x.pb(3);
		___test.construct(x);
} 
// END CUT HERE 
