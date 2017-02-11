#include<iostream>
#include<cstdio>
#include<cmath>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=10000+10,inf=1e9;
int n,maxs[N],mid[N],p;
inline void up(int&x,int y){if(y>x)x=y;}
inline int maxlen(int n){
	int r=floor(sqrt(n));
	if((r+1)*(r+1)<=n)++r;
	--r;
	return r;
}
void build(int r){
	per(i,r,0){
		mid[i]=++p;
		if(i<r)printf("%d %d\n",mid[i],mid[i+1]);
		int lst=mid[i];rep(j,1,i)printf("%d %d\n",lst,++p),lst=p;
		lst=mid[i];rep(j,1,i)printf("%d %d\n",lst,++p),lst=p;
	}
}
int main(){
	scanf("%d",&n);
	maxs[0]=1;rep(i,1,n)maxs[i]=maxs[i-1]+(i+1)*(i+1);
	if(n==1){

	}else if(n==2){
		puts("1 2");
	}else if(n==3){
		puts("1 2");
		puts("1 3");
	}else{
		int maxS=0,maxr=0;
		rep(i,1,maxlen(n)){
			if(maxs[i]+(i+1)*(n-(i+1)*(i+1))>maxS)maxS=maxs[i]+(i+1)*(n-(i+1)*(i+1)),maxr=i;
		}
		//cout<<maxS<<endl;
		build(maxr);
		rep(i,1+(maxr+1)*(maxr+1),n)printf("%d %d\n",i,mid[1]);
	}
	return 0;
}
