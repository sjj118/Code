#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
const int mo=1e9+7,maxn=1e7+10;
typedef long long LL;
using namespace std;
inline void ck(int&x){if(x<0)x+=mo;if(x>=mo)x-=mo;}
inline void ad(int&x,int y){x+=y;ck(x);}
inline LL power(LL x,LL y,LL p){
	LL a=1;
	while(y){
		if(y&1)a=a*x%p;
		x=x*x%p;
		y>>=1;
	}
	return a;
}
int n,m,l,r;
int tot,s[maxn],miu[maxn],prime[maxn];
void pre(){
	miu[1]=1;
	rep(i,2,maxn-1){
		if(!s[i])prime[tot++]=i,miu[i]=-1;
		for(int j=0;j<tot&&i*prime[j]<maxn;++i){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				miu[i*prime[j]]=-miu[i];
			}else{
				miu[i*prime[j]]=0;
				break;
			}
		}
	}
	rep(i,2,maxn-1)miu[i]+=miu[i-1];
}
int calc(int x,int y){
	int ans;
	for(int i=l,ne;i<=r&&i<=y;i=ne+1){
		ne=min(y/(y/i),min(y,r));
		ad(ans,miu[y/i]*(ne-i+1)%mo);
	}
	--x;
	for(int i=l,ne;i<=r&&i<=x;i=ne+1){
		ne=min(x/(x/i),min(x,r));
		ad(ans,-miu[x/i]*(ne-i+1)%mo);
	}
	return ans;
}

int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	pre();
	int T,type;scanf("%d%d",&T,&type);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&l,&r);int ans=0;
		if(type==1){
			for(int i=1,ni;i<=m;i=ni+1){
				ni=min(m/(m/i),m);
				ad(ans,calc(i,ni)*power(m/i,n,mo)%mo);
			}
		}else{
			
		}
		printf("%d\n",ans);
	}
	return 0;
}
