#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
inline LL sqr(LL x){return x*x;}
LL ansd,ansx;
int main(){
	int n;scanf("%d",&n);
	rep(d,1,n)if(sqr(LL(sqrt(d)))!=d){
		for(LL y=1;;++y){
			if(y>100000000){cerr<<d<<" "<<y<<endl;break;}
			LL x=1+d*sqr(y);
			if(sqr(LL(sqrt(x)))==x){
				x=LL(sqrt(x));
				if(x>ansx)ansx=x,ansd=d;
				break;
			}
		}
	}
	cout<<ansd<<" "<<ansx;
	return 0;
}
