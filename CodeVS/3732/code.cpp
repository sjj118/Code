#include <iostream>
using namespace std;

int big[100][10000];
void read(int[]);

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		read(big[i]);
	}
}
