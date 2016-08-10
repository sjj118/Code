#include<iostream>
#include<cstdio>
#define maxn 200100
#define maxm 400100

using namespace std;

int n,m,mo[maxn],hand[maxn][3],t[maxn][3];
struct query{
	int x,h;
}q[maxm];
int pa[maxn],rank[maxn];
void init(){
	for(int i=1;i<=n;++i)mo[i]=0,pa[i]=i,rank[i]=0;
}
int find(int k){
	if(pa[k]==k)return k;
	int t=find(pa[k]);
	if(mo[k]==0)mo[k]=mo[pa[k]];
	return pa[k]=t;
}
bool unio(int a,int b){
	a=find(a);b=find(b);
	if(a==b)return 0;
	if(a==1){pa[b]=a;return 1;}
	if(b==1){pa[a]=b;return 1;}
	if(rank[a]>rank[b])swap(a,b);
	pa[a]=b;++rank[b];
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;++i)scanf("%d%d",&hand[i][1],&hand[i][2]);
	for(int i=1;i<=m;++i){
		int x,h;scanf("%d%d",&x,&h);
		t[x][h]=-1;
		q[i].x=x;q[i].h=h;
	}
	for(int i=1;i<=n;++i){
		if(t[i][1]!=-1&&hand[i][1]!=-1){
			if(i==1)unio(hand[i][1],i);
			else unio(i,hand[i][1]);
		}
		if(t[i][2]!=-1&&hand[i][2]!=-1){
			if(i==1)unio(hand[i][2],i);
			else unio(i,hand[i][2]);
		}
	}
	for(int i=m;i;--i){
		int a=find(q[i].x),b=find(hand[q[i].x][q[i].h]);
		if(a!=b){
			if(a==find(1))mo[b]=i;
			if(b==find(1))mo[a]=i;
			unio(a,b);
		}
	}
	for(int i=1;i<=n;++i)find(i),printf("%d\n",mo[i]-1);
	return 0;
}
