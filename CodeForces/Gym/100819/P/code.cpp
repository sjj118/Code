#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
using namespace std;
const int maxn=110;
int n,num[26],cnt;
char s[maxn];
int main(){
	scanf("%s",s);n=strlen(s);
	rep(i,0,n-1){++cnt;++num[s[i]-'a'];}
	sort(num,num+26);
	printf("%d",cnt-num[25]-num[24]);
	return 0;
}
