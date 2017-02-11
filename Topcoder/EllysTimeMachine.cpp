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
class EllysTimeMachine {
public:
	string getTime(string time) {
		int h=(time[0]-'0')*10+time[1]-'0';
		int m=(time[3]-'0')*10+time[4]-'0';
		if(m==0)m=60;
		if(h==12)h=0;
		char s[10];
		sprintf(s,"%02d:%02d",m/5,h*5);
		return s;
	}
};
//int main(){
//	EllysTimeMachine t;
//	cout<<t.getTime("11:20");
//	return 0;
//}
