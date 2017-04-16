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
typedef long long LL;
const int mo=1e9+7;
const int N=50+5,M=5000+10;
inline void ck(LL&x,LL p){if(x<0)x+=p;if(x>=p)x-=p;}
inline void ad(LL&x,LL y,LL p){x+=y;ck(x,p);}
LL fact[M],inv[M],_fact[M];
inline LL C(LL n,LL m){
	if(m>n)return 0;
	return fact[n]*_fact[m]%mo*_fact[n-m]%mo;
}
inline LL D(LL a,LL b){
	return C(a+b-1,b-1);
}
class OrderedProduct {
public:
	int n,sum;
	LL f[M];
	int count(vector <int> a) {
		n=a.size();
		rep(i,0,n-1)sum+=a[i];
		inv[1]=1;rep(i,2,M-1)inv[i]=-mo/i*inv[mo%i]%mo,ck(inv[i],mo);
		fact[0]=1;rep(i,1,M-1)fact[i]=fact[i-1]*i%mo;
		_fact[0]=1;rep(i,1,M-1)_fact[i]=_fact[i-1]*inv[i]%mo;
		rep(i,1,sum){
			f[i]=1;
			rep(j,0,n-1)f[i]=f[i]*D(a[j],i)%mo;
			rep(j,1,i-1)ad(f[i],-C(i,j)*f[j]%mo,mo);
		}
		LL ans=0;
		rep(i,1,sum)ad(ans,f[i],mo);
		return ans;
	}
};
/*int main(){
	OrderedProduct test;
	int n;
	vector<int> a;
	scanf("%d",&n);
	rep(i,1,n){int x;scanf("%d",&x);a.pb(x);}
	printf("%d",test.count(a));
	return 0;
}*/
