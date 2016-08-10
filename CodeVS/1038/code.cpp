#include <iostream>
#include<stdio.h>
using namespace std;

float a,b,c,d;
float f(float);

int main(){
	cin>>a>>b>>c>>d;
	int p=0;
	float x[3];
	for(int i=-99;i<=100;++i){
		if(f(i-1)*f(i)<0){
            x[p]=i;
            p++;
        }
        if(f(i)==0){
            x[p]=i;
            p++;
        }
	}
	for (p=0;p<3;++p){
		for(int i=2;i<=1024;i*=2){
			if(f(x[p]-(1/(float(i)/2)))*f(x[p]-1/float(i))<0){
				x[p]=x[p]-1/float(i);
			}
		}
	}
	printf("%.2lf ",x[0]);
	printf("%.2lf ",x[1]);
	printf("%.2lf",x[2]);
}

float f(float x){
	return a*x*x*x+b*x*x+c*x+d;
}
