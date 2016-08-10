#include<iostream>
#include<cstdio>
#include<time.h>
#include<stdlib.h>

using namespace std;

int n=20,a[100],ans,sum;

int main(){
	srand(time(NULL));
	for(int i=1;i<=n;++i)a[i]=(rand()%2)?1:-1;
	int t1=0,t2=0;
	for(int i=1;i<=n;++i){
		sum+=a[i];
		if(sum>0)t1=max(t1,sum);
		else t2=max(t2,-sum);
	}
	printf("%d\n",t1+t2);
	for(int i=1;i<=n;++i){
		sum+=a[i];
		if(sum<0)++ans,sum+=2;
	}
}
