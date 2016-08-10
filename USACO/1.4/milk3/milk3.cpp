/*
ID:sjj118
PROG:milk3
LANG:C++
*/
#include<iostream>
#include<cstdio>

using namespace std;

int a,b,c;
bool hash[500],ans[21];

int h(int a,int b){
	return a*21+b;
}
void dfs(int x,int y){
	if(hash[h(x,y)])return;
	hash[h(x,y)]=1;
	if(x==0)ans[c-y]=1;
	int t=min(x,b-y);
	dfs(x-t,y+t);//A->B
	dfs(0,y);//A->C
	t=min(y,a-x);
	dfs(x+t,y-t);//B->A
	dfs(x,0);//B->C
	t=min(c-x-y,a-x);
	dfs(x+t,y);//C->A
	t=min(c-x-y,b-y);
	dfs(x,y+t);//C->B
}

int main(){
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	dfs(0,0);
	bool flag=0;
	for(int i=0;i<=c;++i)if(ans[i]){
		if(flag){
			printf(" ");
		}else flag=1;
		printf("%d",i);
	}
	printf("\n");
	return 0;
}
