#include <iostream>

using namespace std;

struct bignum{
  int len,data[500];
};

bignum change(int);
bool compare(bignum,bignum);
bignum cheng(bignum,int);
bignum jian(bignum,bignum);
void write(bignum);

int main(){
  int a,b;
  cin>>a>>b;
  bignum c,d;
  c=change(a);
  d=change(b);
  for(int i=1;i<b;++i)c=cheng(c,a);
  for(int i=1;i<a;++i)d=cheng(d,b);
  write(jian(c,d));
}

bignum change(int a){
  bignum x;
  for(int i=0;i<500;++i)x.data[i]=0;
  x.len=0;
  while(a>0){
    x.data[x.len++]=a%10;
	a/=10;
  }
  return x;
}

bignum cheng(bignum a,int b){
  for(int i=0;i<a.len;++i){
    a.data[i]*=b;
  }
  for(int i=0;i<a.len;++i){
    a.data[i+1]+=a.data[i]/10;
	a.data[i]%=10;
  }
  while(a.data[a.len]>0){
    a.data[a.len+1]+=a.data[a.len]/10;
	a.data[a.len++]%=10;
  }
  return a;
}

bool compare(bignum a,bignum b){
  if(a.len>b.len)return true;
  if(a.len<b.len)return false;
  for(int i=a.len-1;i>=0;--i){
    if(a.data[i]>b.data[i])return true;
    if(a.data[i]<b.data[i])return false;
  }
  return true;
}

bignum jian(bignum a,bignum b){
  if(!compare(a,b)){
    cout<<'-';
	bignum t=a;
	a=b;
	b=t;
  }
  for(int i=0;i<b.len;++i){
    a.data[i]-=b.data[i];
	if(a.data[i]<0){
	  a.data[i]+=10;
	  a.data[i+1]-=1;
	}
  }
  while(a.data[b.len]<0){
	  a.data[b.len]+=10;
	  a.data[b.len+1]-=1;
	  ++b.len;
  }
  while(a.data[a.len-1]==0&&a.len>1)a.len--;
  return a;
}

void write(bignum a){
  for(int i=a.len-1;i>=0;--i)cout<<a.data[i];
}
