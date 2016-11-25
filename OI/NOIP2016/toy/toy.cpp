#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=1e5+10,L=10+2;
int n,m,a[N];
char name[N][L];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d %s",&a[i],name[i]);
	int pos=1;
	rep(i,1,m){
		int x,s;scanf("%d%d",&x,&s);
		if(x^a[pos]){
			pos+=s;
			if(pos>n)pos-=n;
		}else{
			pos-=s;
			if(pos<=0)pos+=n;
		}
	}
	printf("%s",name[pos]);
	return 0;
}
