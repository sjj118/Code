#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int maxn=110;
using namespace std;
int n;
struct Stu{
	char first[11],last[11];
}a[maxn];
int comp(char*a,char*b){
	int la=strlen(a),lb=strlen(b);
	int l=min(la,lb);
	rep(i,0,l-1){
		if(a[i]<b[i])return 1;
		if(a[i]>b[i])return -1;
	}
	if(la<lb)return 1;
	if(la>lb)return -1;
	return 0;
}
bool operator<(Stu a,Stu b){
	int t=comp(a.last,b.last);
	if(t==0)return comp(a.first,b.first)==1;
	return t==1;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%s%s",a[i].first,a[i].last);
	sort(a+1,a+1+n);
	rep(i,1,n)printf("%s %s\n",a[i].first,a[i].last);
	return 0;
}
