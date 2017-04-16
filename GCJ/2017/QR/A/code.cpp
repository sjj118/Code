#include<cstdio>
#include<algorithm>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
inline bool vaild(char c){return c=='+'||c=='-';}
inline char gc(){char c=getchar();while(!vaild(c))c=getchar();return c;}
const int N=1000+10;
int s[N],b[N];
int main(){
	int tasknumber;scanf("%d",&tasknumber);
	rep(taskid,1,tasknumber){
		char c=gc();
		int n=0;
		while(vaild(c))s[++n]=(c=='+'),c=getchar();
		int k;scanf("%d",&k);
		cls(b);
		int ans=0;
		rep(i,1,n-k+1){
			b[i]^=b[i-1];
			if((s[i]^b[i])==0){
				++ans;
				b[i]^=1;
				b[i+k]^=1;
			}
		}
		bool flag=1;
		rep(i,n-k+2,n){
			b[i]^=b[i-1];
			if((s[i]^b[i])==0)flag=0;
		}
		printf("Case #%d: ",taskid);
		if(flag)printf("%d\n",ans);else puts("IMPOSSIBLE");
	}
	return 0;
}
