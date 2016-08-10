#include <iostream>
#include <math.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  for(int k=0;k<n;++k){
    int s;
	cin>>s;
	int c=0;
	for(int i=2;i<=sqrt(s);++i){
	  while(s%i==0){
	    s/=i;
	    c++;
	    if(c>2){
		  break;
		}
	  }
	  if(c>2){
	    break;
	  }
	}
	if(s>1)c++;
	if(c>2||c<2)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
  }
}
