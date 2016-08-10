#include<iostream>
#include<cstdio>
#define maxn 5000000
#define LL long long
#define mo 1000000007
#define ha 2333333

using namespace std;

int a,b;
int tot,prime[maxn];
LL phi[maxn];
bool s[maxn];
void init(){
	phi[1]=1;
	for(int i=2;i<maxn;++i){
		if(!s[i])prime[tot++]=i,phi[i]=i-1;
		for(int j=0;j<tot&&i*prime[j]<maxn;++j){
			s[i*prime[j]]=1;
			if(i%prime[j]){
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}else{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
		}
	}
	for(int i=1;i<maxn;++i)phi[i]=(phi[i-1]+phi[i]*i)%mo;
}
struct Hash{
	int tot,head[ha],next[ha];
	LL key[ha],val[ha];
	LL get(LL k){
		for(int p=head[k%ha];p;p=next[p])if(key[p]==k)return val[p];
		return -1;
	}
	void ins(LL k,LL x){key[++tot]=k;val[tot]=x;next[tot]=head[k%ha];head[k%ha]=tot;}
}hash;
int exgcd(int a,int b,int&x,int&y){
	if(!b){
		x=1;y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y);
	int t=x;
	x=y;y=t-a/b*y;
	return d;
}
LL _(LL n){
	int x,y;
	exgcd(n,mo,x,y);
	return x;
}
LL getphi(LL n){
	if(n<maxn)return phi[n];
	LL ans=hash.get(n);
	if(ans!=-1)return ans;
	ans=0;
	for(int i=2,ne;i<=n;i=ne+1){
		ne=n/(n/i);
		ans=(ans+getphi(n/i)*((LL)(i+ne)*(ne-i+1)/2%mo))%mo;
	}
	ans=(n*(n+1)%mo*(2*n+1)%mo*_(6)%mo-ans)%mo;
	ans=(ans+mo)%mo;
	hash.ins(n,ans);
	return ans;
}
LL sum(LL n){
	if(n==0)return 0;
	return (1+getphi(n))*_(2)%mo;
}
LL F(int n){
	LL ans=0;
	for(int i=1,ne;i<=n;i=ne+1){
		ne=n/(n/i);
		ans=(ans+(sum(ne)-sum(i-1))*(n/i))%mo;
	}
	ans=(ans+mo)%mo;
	return ans;
}

int main(){
	init();
	scanf("%d%d",&a,&b);
	printf("%d",(F(b)-F(a-1)+mo)%mo);
	return 0;
}
