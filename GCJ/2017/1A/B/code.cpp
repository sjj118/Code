#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int N=50+5;
int n,m,R[N],Q[N][N],l[N];
int lower(int x){return (x-1)*9/10+1;}
int upper(int x){return x*11/10;}
bool check(int amo){
	bool ret=1;
	rep(i,1,n)if(l[i]>m)ret=0;
	if(!ret)return ret;
	rep(i,1,n){
		while(l[i]<m&&lower(amo*R[i])>Q[i][l[i]])++l[i];
		if(lower(amo*R[i])>Q[i][l[i]]||Q[i][l[i]]>upper(amo*R[i]))ret=0;
	}
	if(ret)rep(i,1,n)++l[i];
	return ret;
}
int main(){
	int tasknumber;scanf("%d",&tasknumber);
	rep(taskid,1,tasknumber){
		scanf("%d%d",&n,&m);
		rep(i,1,n)scanf("%d",&R[i]);
		rep(i,1,n)rep(j,1,m)scanf("%d",&Q[i][j]);
		rep(i,1,n)std::sort(Q[i]+1,Q[i]+1+m);
		rep(i,1,n)l[i]=1;
		int ans=0;
		for(int amo=1;;++amo){
			bool flag=1;
			rep(i,1,n)if(amo*R[i]>2000000)flag=0;
			if(!flag)break;
			while(check(amo))++ans;
		}
		printf("Case #%d: %d\n",taskid,ans);
	}
	return 0;
}
