#include<bits/stdc++.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int N=2000+10,M=N*N;
int n,a[N],m,head=1;
inline int cw(int x){if(x<=0)x+=n;if(x>n)x-=n;return x;}
int main(){
	freopen("shift.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	fclose(stdin);freopen("shift.out","r",stdin);
	scanf("%d",&m);
	char last=0;
	bool flag1=0;
	rep(j,1,m){
		int k;char c;scanf("%d%c",&k,&c);
		if(c==last)flag1=1;
		last=c;
		if(k<=0||k>=n)flag1=1;
		if(c=='a')head=cw(head-k);
		else rep(i,1,k%3)swap(a[cw(head+2)],a[cw(head+1)]),swap(a[cw(head+1)],a[head]);
	}
	rep(i,1,n)if(a[cw(head+i-1)]!=i)flag1=1;
	if(m>n*n)flag1=1;
	fclose(stdin);freopen("shift.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	fclose(stdin);freopen("std.out","r",stdin);
	head=1;
	scanf("%d",&m);
	rep(j,1,m){
		int k;char c;scanf("%d%c",&k,&c);
		if(c=='a')head=cw(head-k);
		else rep(i,1,k%3)swap(a[cw(head+2)],a[cw(head+1)]),swap(a[cw(head+1)],a[head]);
	}
	bool flag2=0;
	rep(i,1,n)if(a[cw(head+i-1)]!=i)flag2=1;
	if(m>n*n)flag2=1;
	if(flag1!=flag2)return 1;
	return 0;
}
