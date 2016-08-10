#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int maxn=5e5+10;
using namespace std;
inline int read(){
	int tmp=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp;
}
int n,m,ty,ans;

int main(){
	n=read();m=read();ty=read();
	rep(i,1,m){
		int op=read();
		if(op==1){
			int l=read(),r=read();
			l=(l+ans*ty)%n+1;
			r=(r+ans*ty)%n+1;
			if(l>r)swap(l,r);
			
		}else if(op==2){
			int l=read();
			l=(l+ans*ty)%n+1;
			
		}else{
			int l=read(),r=read(),x=read();
			l=(l+ans*ty)%n+1;
			r=(r+ans*ty)%n+1;
			if(l>r)swap(l,r);
			
		}
		
		
	}
	return 0;
}
