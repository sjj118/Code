#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<assert.h>
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
typedef unsigned int UI;
const int N=500+10,M=1000+10,L=1000+10,inf=1e9;
int n,m,l;
template<int N>struct Bitset{
	UI v[(N>>5)+1];
	Bitset(){cls(v);}
	const int get(int x)const{return (v[x>>5]>>(x&31))&1;}
	const int operator[](int x)const{return get(x);}
	void set(int x){v[x>>5]|=1<<(x&31);}
	void operator^=(const Bitset&a){rep(i,0,N>>5)v[i]^=a.v[i];}
	int log(){per(i,N>>5,0)if(v[i])per(j,31,0)if((v[i]>>j)&1)return (i<<5)+j;return -1;}
	void input(){
		cls(v);
		char c=getchar();
		while(!(c=='0'||c=='1'))c=getchar();
		int l=0;
		static int a[N];
		while(c=='0'||c=='1')a[l++]=c-'0',c=getchar();
		rep(i,0,l-1)if(a[l-i-1])set(i);
	}
	void output(){
		bool flag=0;
		per(i,l,0){
			if(get(i))flag=1;
			if(flag)putchar('0'+get(i));
		}
		if(!flag)putchar('0');
		puts("");
	}
	void operator=(int x){
		cls(v);
		int l=0;
		while(x){if(x&1)set(l++);x>>=1;}
	}
};
int h[L];
Bitset<L> w[N];
Bitset<N> b[N];
void gauss(int k){
	rep(i,0,l)if(h[i]==k)h[i]=0;
	per(i,l,0)if(w[k][i]){
		if(h[i]){
			w[k]^=w[h[i]];
			b[k]^=b[h[i]];
		}else{
			h[i]=k;
			break;
		}
	}
}
void change(int k,const Bitset<L>&c){
	int mnpos=inf,mnid=0;
	rep(i,1,n)if(b[i][k])if(w[i].log()<mnpos)mnpos=w[i].log(),mnid=i;
	rep(i,1,n)if(i!=mnid&&b[i][k])b[i]^=b[mnid],w[i]^=w[mnid];
	w[mnid]^=c;
	gauss(mnid);
}
void solve(){
	static Bitset<L> ans;
	ans=0;
	per(i,l,0)if(ans[i]==0&&h[i])ans^=w[h[i]];
	ans.output();
}
int main(){
	int id;scanf("%d",&id);
	scanf("%d%d",&n,&m);l=1000;
	rep(i,1,n)b[i].set(i);
	rep(i,1,m){
		int a,b;scanf("%d%d",&a,&b);
		static Bitset<L> c;c.input();
		change(a,c);change(b,c);
		solve();
	}
	return 0;
}
