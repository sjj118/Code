#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10;
int n,k,num[2];
int s[N];
int main(){
	scanf("%d%d%d%d",&n,&k,&num[0],&num[1]);
	int a=0,b=1,p=0;
	rep(i,1,n){
		if(num[a]<num[b]||p==k)swap(a,b),p=0;
		++p;
		if(num[a]==0){puts("NO");return 0;}
		s[i]=a;--num[a];
	}
	rep(i,1,n)printf("%c",s[i]?'B':'G');
	return 0;
}
