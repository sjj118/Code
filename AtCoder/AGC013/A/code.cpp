#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
int n;
int main(){
	scanf("%d",&n);
	int lst=0,dir=0;
	int ans=1;
	rep(i,1,n){
		int x;scanf("%d",&x);
		if(dir==0){
			if(lst){
				if(lst<x)dir=1;
				if(lst>x)dir=-1;
			}
		}else{
			if((dir==1&&lst>x)||(dir==-1&&lst<x)){
				lst=0;++ans;dir=0;
			}
		}
		lst=x;
	}
	printf("%d",ans);
	return 0;
}
