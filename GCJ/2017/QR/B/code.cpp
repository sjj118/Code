#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef long long LL;
int a[22],l,b[22];
void solve(LL n){
	l=0;
	while(n)a[++l]=n%10,n/=10;
	bool top=1;
	per(i,l,1){
		per(j,9,0){
			bool flag=1;
			bool tmp=top;
			per(k,i,1){
				if(tmp&&j>a[k])flag=0;
				tmp&=j==a[k];
			}
			if(flag){
				b[i]=j;
				top&=a[i]==j;
				break;
			}
		}
	}
	while(l&&b[l]==0)--l;
	per(i,l,1)putchar('0'+b[i]);puts("");
}
int main(){
	int tasknumber;scanf("%d",&tasknumber);
	rep(taskid,1,tasknumber){
		LL n;scanf("%lld",&n);
		printf("Case #%d: ",taskid);
		solve(n);
	}
	return 0;
}
