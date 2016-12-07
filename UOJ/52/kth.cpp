#include<iostream>
#include<cstdio>
#include "kth.h"
using namespace std;
int query_kth(int na,int nb,int nc,int k){
	int pa=-1,pb=-1,pc=-1;
	while(k>=3){
		int xa=get_a(pa+k/3),xb=get_b(pb+k/3),xc=get_c(pc+k/3);
		if(xa<=xb&&xa<=xc)pa+=k/3;
		else if(xb<=xa&&xb<=xc)pb+=k/3;
		else if(xc<=xa&&xc<=xb)pc+=k/3;
		k-=k/3;
	}
	if(k==2){
		int xa=get_a(pa+1),xb=get_b(pb+1),xc=get_c(pc+1);
		if(xa<=xb&&xa<=xc)++pa;
		else if(xb<=xa&&xb<=xc)++pb;
		else if(xc<=xa&&xc<=xb)++pc;
		--k;
	}
	return min(min(get_a(pa+1),get_b(pb+1)),get_c(pc+1));
}
