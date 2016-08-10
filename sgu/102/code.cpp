#include <iostream>
#include <math.h>

using namespace std;

int phi(int);

int main(){
  int n;
  cin>>n;
  cout<<phi(n);
  cin>>n;
}

int phi(int n){
  int k=n;
  for(int i=2;i<=sqrt(n);++i){
    if(n%i==0){
	  k=k/i*(i-1);
	  while(n%i==0){
	    n/=i;
	  }
	}
  }
  if(n>1)k=k/n*(n-1);
  return k;
}
