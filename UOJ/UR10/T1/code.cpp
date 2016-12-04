#include<iostream>
#include<cstdio>
#define maxn 510
#define maxk 1000010

using namespace std;

int n,A[4][maxn],top[4],pos[maxn],k;
struct opera{
	int a,b;
	opera(int aa=0,int bb=0){a=aa;b=bb;}
}O[maxk];

int main(){
	scanf("%d",&n);
	for(int i=n;i>=1;--i)scanf("%d",&A[1][i]);
	for(int i=1;i<=n;++i)pos[i]=1;top[1]=n;
	for(int i=n;i>=1;--i){
		int t=pos[i];
		while(A[t][top[t]]!=i)pos[A[t][top[t]]]=3-t,A[3-t][++top[3-t]]=A[t][top[t]],--top[t],O[++k]=opera(t,3-t);
		pos[A[t][top[t]]]=3;A[3][++top[3]]=i;--top[t];O[++k]=opera(t,3);
	}
	printf("%d\n",k);
	for(int i=1;i<=k;++i)printf("%d %d\n",O[i].a,O[i].b);
	return 0;
}
