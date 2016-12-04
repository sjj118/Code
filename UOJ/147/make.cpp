#include<bits/stdc++.h>
using namespace std;
int T=4,n=23;
int cnt[15];
int main(){
	srand(time(0));freopen("code.in","w",stdout);
	printf("%d %d\n",T,n);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i){
			int t=rand()%14;
			while(!(t&&cnt[t]<=4||cnt[t]<=2))t=rand()%14;
			printf("%d %d\n",t,rand()%4+1);
		}
	}
	return 0;
}
