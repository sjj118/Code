#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1112
#define yawei 9
#define base 1000000000

using namespace std;

struct bignum{
	int len,arr[maxn];
	bignum(){
		len=0;
		memset(arr,0,sizeof(arr));
	}
};
bool isNum(char c){
	return c>='0'&&c<='9';
}
void check(bignum &a){
	while(a.len&&a.arr[a.len]==0)--a.len;
	while(a.arr[a.len+1])++a.len;
}
void read(bignum &a){
	char c=getchar();
	while(!isNum(c))c=getchar();
	string s="";
	while(isNum(c)){
		s=s+c;
		c=getchar();
	}
	int temp=0;
	for(int i=s.size()-1,j=1;i>=0;--i){
		temp+=j*(s[i]-'0');
		j*=10;
		if(j%base==0||i==0) a.arr[++a.len]=temp,temp=0,j=1;
	}
	check(a);
}
void write(bignum a){
	check(a);
	printf("%d",a.arr[a.len]);
	for(int i=a.len-1;i;--i)printf("%09d",a.arr[i]);
}
bool operator<(bignum a,bignum b){
	check(a);check(b);
	if(a.len<b.len)return 1;
	if(a.len>b.len)return 0;
	for(int i=a.len;i;--i){
		if(a.arr[i]<b.arr[i])return 1;
		if(a.arr[i]>b.arr[i])return 0;
	}
	return 0;
}
bool operator==(bignum a,bignum b){
	check(a);check(b);
	if(a.len!=b.len)return 0;
	for(int i=1;i<=a.len;++i)if(a.arr[i]!=b.arr[i])return 0;
	return 1;
}
bignum operator+(bignum a,bignum b){
	bignum c;
	if(a.len<b.len)swap(a,b);
	c.len=a.len;
	for(int i=1;i<=c.len;++i){
		c.arr[i]+=a.arr[i]+b.arr[i];
		c.arr[i+1]+=c.arr[i]/base;
		c.arr[i]%=base;
	}
	check(c);
	return c;
}
void operator-=(bignum &a,bignum b){
	for(int i=1;i<=a.len;++i){
		a.arr[i]-=b.arr[i];
		if(a.arr[i]<0) a.arr[i]+=base,a.arr[i+1]--;
	}
	check(a);
}
bignum operator*(bignum a,int b){
	bignum c;
	for(int i=1;i<=a.len;++i){
		c.arr[i]+=a.arr[i]*b;
		c.arr[i+1]+=c.arr[i]/base;
		c.arr[i]%=base;
	}
	check(c);
	return c;
}
void operator/=(bignum &a,int b){
	for(int i=a.len;i;--i){
		a.arr[i-1]+=base*(a.arr[i]%b);
		a.arr[i]/=b;
	}
	check(a);
}
bignum gcd(bignum a,bignum b){
	int cnt=0;
	bignum c;c.len=1;c.arr[1]=1;
	while(1){
		if(a.len==0){
			while(cnt--) b=b*2;
			return b;
		}
		if(b.len==0||a==b){
			while(cnt--) a=a*2;
			return a;
		}
		if(a.arr[1]&1){
			if(b.arr[1]&1){
				if(a<b)b-=a;else a-=b;
			}else{
				b/=2;
			}
		}else{
			if(b.arr[1]&1){
				a/=2;
			}else{
				a/=2;
				b/=2;
				++cnt;
			}
		}
	}
}

bignum a,b;
int main(){
	read(a);read(b);
	write(gcd(a,b));
	return 0;
}
