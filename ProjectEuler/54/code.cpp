#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
inline char gc(){char c=getchar();while(!(c>='0'&&c<='9'||c>='A'&&c<='Z'))c=getchar();return c;}
struct Poker{
	int val,col;
	void read(){
		char c=gc();
		if(c>='2'&&c<='9')val=c-'0';
		if(c=='T')val=10;
		if(c=='J')val=11;
		if(c=='Q')val=12;
		if(c=='K')val=13;
		if(c=='A')val=14;
		col=gc();
	}
}a[6],b[6];
bool operator<(Poker a,Poker b){return a.val<b.val;}
int Royal_Flush(Poker*a){
	int col=a[1].col;
	rep(i,2,5)if(a[i].col!=col)return 0;
	rep(i,1,5)if(a[i].val!=9+i)return 0;
	return 1;
}
int Straight_Flush(Poker*a){
	int col=a[1].col;
	rep(i,2,5)if(a[i].col!=col)return 0;
	int val=a[1].val;
	rep(i,2,5)if(a[i].val!=val+i-1)return 0;
	return val;
}
int Four_of_a_Kind(Poker*a){
	int num[15];cls(num);
	rep(i,1,5)++num[a[i].val];
	rep(i,2,14)if(num[i]==4)return i;
	return 0;
}
int Full_House(Poker*a){
	bool three=0,two=0,num[15];cls(num);
	rep(i,1,5)++num[a[i].val];
	rep(i,2,14){if(num[i]==3)three=1;if(num[i]==2)two=1;}
	return three&&two;
}
int Flush(Poker*a){
	int col=a[1].col;
	rep(i,2,5)if(a[i].col!=col)return 0;
	return 1;
}
int Straight(Poker*a){
	int val=a[1].val;
	rep(i,2,5)if(a[i].val!=val+i-1)return 0;
	return val;
}
int Three_of_a_Kind(Poker*a){
	int num[15];cls(num);
	rep(i,1,5)++num[a[i].val];
	rep(i,2,14)if(num[i]==3)return i;
	return 0;
}
int Two_Pairs(Poker*a){
	int cnt=0,num[15],v[2];cls(num);
	rep(i,1,5)++num[a[i].val];
	rep(i,2,14)if(num[i]==2)v[cnt++]=i;
	if(cnt==2)return 15*v[1]+v[0];else return 0;
}
int One_Pair(Poker*a){
	int num[15];cls(num);
	rep(i,1,5)++num[a[i].val];
	per(i,14,2)if(num[i]==2)return i;
	return 0;
}
int High_Card(Poker*a){
	int tmp=0;
	per(i,5,1)tmp=tmp*15+a[i].val;
	return tmp;
}
int main(){
	freopen("poker.txt","r",stdin);
	int ans=0;
	rep(cas,1,1000){
		rep(j,1,5)a[j].read();
		rep(j,1,5)b[j].read();
		sort(a+1,a+1+5);sort(b+1,b+1+5);
		if(Royal_Flush(a)==Royal_Flush(b)){
			if(Straight_Flush(a)==Straight_Flush(b)){
				if(Four_of_a_Kind(a)==Four_of_a_Kind(b)){
					if(Full_House(a)==Full_House(b)){
						if(Flush(a)==Flush(b)){
							if(Straight(a)==Straight(b)){
								if(Three_of_a_Kind(a)==Three_of_a_Kind(b)){
									if(Two_Pairs(a)==Two_Pairs(b)){
										if(One_Pair(a)==One_Pair(b)){
											ans+=High_Card(a)>High_Card(b);
										}else ans+=One_Pair(a)>One_Pair(b);
									}else ans+=Two_Pairs(a)>Two_Pairs(b);
								}else ans+=Three_of_a_Kind(a)>Three_of_a_Kind(b);
							}else ans+=Straight(a)>Straight(b);
						}else ans+=Flush(a)>Flush(b);
					}else ans+=Full_House(a)>Full_House(b);
				}else ans+=Four_of_a_Kind(a)>Four_of_a_Kind(b);
			}else ans+=Straight_Flush(a)>Straight_Flush(b);
		}else ans+=Royal_Flush(a)>Royal_Flush(b);
	}
	printf("%d\n",ans);
	return 0;
}
