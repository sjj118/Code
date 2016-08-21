#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 20000
#define smaxn 142
#define LL long long

using namespace std;

int t,n,m;
int _gcd[smaxn][smaxn],prime[maxn],tot;
bool slide[maxn];
LL ans;
struct decomp{
	int k[3]; 
} de[maxn];
void init(){
	for(int i=1;i<smaxn;++i)_gcd[i][0]=_gcd[0][i]=i;
	for(int i=1;i<smaxn;++i)
		for(int j=i;j<smaxn;++j)_gcd[i][j]=_gcd[j][i]=_gcd[j%i][i];
	de[1].k[0]=de[1].k[1]=de[1].k[2]=1;
	for(int i=2;i<maxn;++i){
		if(!slide[i]){
			prime[tot++]=i;
			de[i].k[0]=de[i].k[1]=1;de[i].k[2]=i;
		}
		if(de[i].k[1]<de[i].k[0])swap(de[i].k[1],de[i].k[0]);
		if(de[i].k[2]<de[i].k[0])swap(de[i].k[2],de[i].k[0]);
		for(int j=0;j<tot&&i*prime[j]<maxn;++j){
			slide[i*prime[j]]=1;
			de[i*prime[j]]=de[i];
			de[i*prime[j]].k[0]*=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
int gcd(int a,int b){
	if(a>b)swap(a,b);
	if(a==0)return b;
	if(a<smaxn)return _gcd[a][b%a];
	decomp k=de[a];
	int d=1,g;
	for(int i=0;i<3;++i){
		if(k.k[i]<smaxn)g=_gcd[k.k[i]][b%k.k[i]];
		else if(b%k.k[i]==0)g=k.k[i];
		else g=1;
		d*=g;
		b/=g;
	}
	return d;
}

int main(){
	scanf("%d",&t);
	init();
	while(t--){
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)ans+=gcd(i&j,i|j);
		printf("%lld\n",ans);
	}
	return 0;
}
