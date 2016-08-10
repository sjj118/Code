/*
ID:sj22451
PROG:wormhole
LANG:C++
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 20

using namespace std;

int ans;
struct Point{
	int x,y;
} p[maxn];

int n,rig[maxn],tran[maxn];

bool comp(Point a,Point b){
	return a.y<b.y||a.y==b.y&&a.x<b.x;
}
bool vis[maxn];
bool findcir(){
	for(int i=0;i<n;++i){
		memset(vis,0,sizeof(vis));
		int k=i;
		while(k>=0){
			if(vis[k])return 1;
			vis[k]=1;
			k=tran[k];
			k=rig[k];
		}
	}
	return 0;
}
bool used[maxn];
int last;
void go(int k){
	if(k>n){
		if(findcir())++ans;
		return;
	}
	if(k&1){
		for(int i=0;i<n;++i)if(!used[i]){
			used[i]=1;
			last=i;
			go(k+1);
			used[i]=0;
			break;
		}
	}else{
		int t=last;
		for(int i=0;i<n;++i)if(!used[i]){
			used[i]=1;
			tran[i]=t;
			tran[t]=i;
			go(k+1);
			used[i]=0;
		}
	}
}


int main(){
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	sort(p,p+n,comp);
	for(int i=0;i<n-1;++i){
		if(p[i].y==p[i+1].y){
			rig[i]=i+1;
		}else rig[i]=-1;
	}
	rig[n-1]=-1;
	go(1);
	printf("%d\n",ans);
	return 0;
}
