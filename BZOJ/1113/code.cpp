#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 300000

using namespace std;

int n,h[maxn],pos[maxn],next[maxn],pre[maxn];
struct Block{
	int h,pos,vis;
	Block(int H=0,int Pos=0,int Vis=0){h=H;pos=Pos;vis=Vis;}
}b[maxn];
bool comp(Block a,Block b){return a.h>b.h;}
void del(int x){
	b[x].vis=1;
	next[pre[x]]=next[x];
	pre[next[x]]=pre[x];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int w;scanf("%d%d",&w,&h[i]);
		b[i]=Block(h[i],i);
	}
	sort(b+1,b+1+n,comp);
	for(int i=1;i<=n;++i)pos[b[i].pos]=i;
	for(int i=1;i<=n;++i)next[pos[i]]=pos[i+1],pre[pos[i]]=pos[i-1];
	int ans=0;
	for(int k=1;k<=n;++k)if(!b[k].vis)while(b[k].h==b[next[k]].h)del(next[k]);
	for(int i=1;i<=n;++i)if(!b[i].vis){
		++ans;
		del(i);
		if(b[pre[i]].h==b[next[i]].h)del(pre[i]);
	}
	printf("%d",ans);
	return 0;
}
