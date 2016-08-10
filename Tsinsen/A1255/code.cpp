#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
#define mo 19930726
#define maxn 1000100
#define min(a,b) (a<b?a:b)

using namespace std;

int n;
LL k;
struct PAM{
	int tot,last,son[maxn][26],fail[maxn],len[maxn],cnt[maxn],n,s[maxn];
	PAM(){
		tot=1;s[0]=-1;
		len[1]=-1;fail[0]=1;
	}
	int getfail(int k){while(s[n-len[k]-1]!=s[n])
	k=fail[k];return k;}
	void ins(int x){
		s[++n]=x;
		int cur=getfail(last);
		if(!son[cur][x]){
			len[++tot]=len[cur]+2;fail[tot]=son[getfail(fail[cur])][x];son[cur][x]=tot;
		}
		last=son[cur][x];++cnt[last];
	}
	void count(){
		for(int i=tot;i>=0;--i)cnt[fail[i]]+=cnt[i];
	}
}P;
struct ps{
	int len,cnt;
}pp[maxn];
bool comp(ps a,ps b){return a.len>b.len;}
LL power(LL base,int exp){
	LL ans=1;
	while(exp){
		if(exp&1)ans=ans*base%mo;
		base=base*base%mo;
		exp>>=1;
	}
	return ans;
}

int main(){
	scanf("%d%lld",&n,&k);
	char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while(c>='a'&&c<='z')P.ins(c-'a'),c=getchar();
	P.count();
	for(int i=0;i<=P.tot;++i)pp[i].len=P.len[i],pp[i].cnt=P.cnt[i];
	sort(pp,pp+P.tot+1,comp);
	LL ans=1;
	for(int i=0;i<=P.tot&&k>0;++i)if(pp[i].len&1)ans=ans*power(pp[i].len,min(pp[i].cnt,k))%mo,k-=pp[i].cnt;
	if(k>0)printf("-1");else printf("%d",ans);
	return 0;
}
