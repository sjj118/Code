#include<iostream>
#include<cstdio>
#include<complex>
#define mo 1000000007
#define maxn 300010
#define E complex<double>
#define pi acos(-1)
#define LL long long
#define eps 1e-3

using namespace std;

int n;
int a[maxn];
E s[maxn],fs[maxn];
LL ans,tmp;
int gets(int x){
	if(x==0)return -2;
	if(x>n*2+1)return -3;
	if(x&1)return -1;
	else return a[(x>>1)-1];
}
int rad[maxn];
LL manacher(){
	LL tmp=0;
	int id,mx=0;
	for(int i=1;i<=n*2;++i){
		if(mx>i)rad[i]=min(mx-i,rad[2*id-i]);else rad[i]=1;
		while(gets(i+rad[i])==gets(i-rad[i]))++rad[i];
		if(i+rad[i]>mx)mx=i+rad[i],id=i;
	}
	for(int i=1;i<=n*2;++i)tmp=(tmp+rad[i]/2)%mo;
	return tmp;
}
int rev[maxn],L,m;
void fft(E*a,int f){
	for(int i=0;i<n;++i)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1){
		E wn(cos(pi/i),f*sin(pi/i));
		for(int j=0;j<n;j+=(i<<1)){
			E w(1,0);
			for(int k=0;k<i;++k,w*=wn){
				E x=a[j+k],y=w*a[j+k+i];
				a[j+k]=x+y;a[j+k+i]=x-y;
			}
		}
	}
	if(f==-1)for(int i=0;i<n;++i)a[i]/=n;
}
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
	{char c=getchar();
	while(c!='a'&&c!='b')c=getchar();
	while(c=='a'||c=='b')a[n]=c-'a',fs[n]=(c-'a')^1,s[n++]=c-'a',c=getchar();}
	tmp=manacher();
	m=n*2-2;
	for(n=1;n<=m;n<<=1)++L;
	for(int i=0;i<n;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
	fft(s,1);fft(fs,1);
	for(int i=0;i<n;++i)s[i]*=s[i],fs[i]*=fs[i];
	fft(s,-1);fft(fs,-1);
	for(int i=0;i<=m;++i)
	ans=(ans+power(2,int((s[i].real()+eps)+(fs[i].real()+eps)+1)/2)-1)%mo;
	ans=(ans-tmp+mo)%mo;
	printf("%d",ans);
	return 0;
}
