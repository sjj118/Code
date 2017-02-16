#include<iostream>
#include<cstdio>
#include<map>
#define rg register
#define mp make_pair
#define fi first
#define se second
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using std::map;
using std::pair;
using std::make_pair;
const int N=2e5+10;
inline void up(int&x,int y){if(y>x)x=y;}
int n,a[N],c[3];
map<pair<int,int> ,int> s;
int main(){
	scanf("%d\n",&n);
	rep(i,1,n){
		char c;scanf("%c",&c);
		if(c=='J')a[i]=0;
		if(c=='O')a[i]=1;
		if(c=='I')a[i]=2;
	}
	int ans=0;
	s[mp(0,0)]=0;
	rep(i,1,n){
		++c[a[i]];
		if(s.count(mp(c[1]-c[0],c[2]-c[1]))){
			up(ans,i-s[mp(c[1]-c[0],c[2]-c[1])]);
		}else s[mp(c[1]-c[0],c[2]-c[1])]=i;
	}
	printf("%d",ans);
	return 0;
}
