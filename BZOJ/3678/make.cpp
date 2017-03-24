#include<iostream>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
int main(){
	srand(time(0));
	freopen("code.in","w",stdout);
	int n=100000,m=20000;
	int p=n;
	printf("%d %d\n",n,m);
	rep(i,1,n)printf("%d ",rand());puts("");
	rep(i,0,m-1){
		int op=rand()%3;
		if(i%3==1){
			//int a=rand()%1000000+1,b=a+rand()%(100000-p);
			//int a=rand()%100000+1,b=a;
			int t=0;int a=1000000,b=a+100000;
			printf("0 %d %d %d\n",t,a,b);
			p+=b-a+1;
		}
		if(i%3==0){
			//int l=rand()%p+1,r=rand()%p+1;
			//int l=rand()%p+1,r=l;
			int l=1,r=100000;
			if(l>r)std::swap(l,r);
			printf("1 %d %d\n",l,r);
			p-=r-l+1;
		}
		if(i%3==2){
			printf("2 %d\n",rand()%p+1);
		}
	}
	return 0;
}
