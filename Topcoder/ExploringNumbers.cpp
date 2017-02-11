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
const int N=1000+10;
bool isPrime(int n){
	if(n==1)return 0;
	for(int i=2;i*i<=n;++i)if(n%i==0)return 0;
	return 1;
}
bool vis[N];
inline int sqr(int x){return x*x;}
int decode(int n){
	int ret=0;
	while(n)ret+=sqr(n%10),n/=10;
	return ret;
}
class ExploringNumbers {
public:
	int numberOfSteps(int n) {
		int x=n;
		rep(i,1,n){
			if(isPrime(x))return i;
			if(x<1000&&vis[x])return -1;
			if(x<1000)vis[x]=1;
			x=decode(x);
		}
		return -1;
	}
};
