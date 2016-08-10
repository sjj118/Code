#include<iostream>
#include<cstdio>
#include<cstring>
#define maxp 1000010
#define maxn 500010
#define alp 26
#define LL long long

using namespace std;

int n;
struct SAM{
	int tot,pre[maxp],son[maxp][alp],size[maxp],step[maxp],du[maxp];
	LL sum[maxp];
	void clear(){tot=1;}
	int ins(int p,int c){
		int np=++tot;step[np]=step[p]+1;size[np]=1;
		while(p&&!son[p][c])son[p][c]=np,p=pre[p];
		if(p){
			int q=son[p][c];
			if(step[q]==step[p]+1)pre[np]=q;
			else{
				int nq=++tot;step[nq]=step[p]+1;
				memcpy(son[nq],son[q],sizeof(son[q]));
				pre[nq]=pre[q];
				pre[q]=pre[np]=nq;
				while(son[p][c]==q)son[p][c]=nq,p=pre[p];
			}
		}else pre[np]=1;
		return np;
	}
	int q[maxp],ql,qr;
	void build(char*s){
		clear();
		for(int i=strlen(s)-1,last=1;i>=0;--i)last=ins(last,s[i]-'a');
		for(int i=1;i<=tot;++i)++du[pre[i]];
		ql=1;qr=0;
		for(int i=1;i<=tot;++i)if(!du[i])q[++qr]=i;
		while(ql<=qr){
			int k=q[ql++];
			size[pre[k]]+=size[k];
			--du[pre[k]];
			if(!du[pre[k]])q[++qr]=pre[k];
		}
		for(int i=1;i<=tot;++i)sum[i]+=(LL)size[i]*(size[i]-1)/2,sum[pre[i]]-=(LL)size[i]*(size[i]-1)/2;
	}
	LL solve(){
		LL ans=0;
		for(int i=1;i<=tot;++i)ans+=sum[i]*step[i];
		return (LL)n*(n+1)*(n-1)/2-2*ans;
	}
}sam;
char s[maxn];

int main(){
	scanf("%s",s);n=strlen(s);
	sam.build(s);
	printf("%lld",sam.solve());
	return 0;
}
