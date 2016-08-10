#include<iostream>
#include<cstdio>
#define maxn 300010
#define LL long long

using namespace std;

struct PAM{
	int s[maxn],n,tot,last,son[maxn][26],fail[maxn],len[maxn],cnt[maxn];
	PAM(){
		len[0]=0;len[1]=-1;fail[0]=fail[1]=1;
		tot=1;s[0]=-1;
	}
	int getfail(int k){while(s[n-len[k]-1]!=s[n])k=fail[k];return k;}
	void ins(int x){
		s[++n]=x;
		int cur=getfail(last);
		if(!son[cur][x]){
			len[++tot]=len[cur]+2;fail[tot]=son[getfail(fail[cur])][x];son[cur][x]=tot;
		}
		last=son[cur][x];
		++cnt[last];
	}
	LL count(){
		for(int i=tot;i>=0;--i)cnt[fail[i]]+=cnt[i];
		LL ans=0;
		for(int i=0;i<=tot;++i)ans=max(ans,(LL)len[i]*cnt[i]);
		return ans;
	}
}P;

int main(){
	char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while(c>='a'&&c<='z'){
		P.ins(c-'a');
		c=getchar();
	}
	printf("%lld\n",P.count());
	return 0;
}
