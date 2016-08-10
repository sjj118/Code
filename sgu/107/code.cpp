#include <iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  if(n<9){
    cout<<0;
  }else{
    if(n<10){
	  cout<<8;
	}else{
	  cout<<72;
	  for(int i=10;i<n;++i){
	    cout<<0;
	  }
	}
  }
}