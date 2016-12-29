#include<iostream>
#include<cstdio>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
const int inf=1e9;
int bottle_id;
int read(){puts("I");return ++bottle_id;}
void write(int x){printf("O %d\n",x);}
int new_bottle(int x){printf("C %d\n",x);return ++bottle_id;}
void pull(int a,int b){printf("T %d %d\n",a,b);}
int sum(int a,int b){
	int c=new_bottle(inf);
	pull(a,c);pull(b,c);
	return c;
}
void clear(int a){printf("E %d\n",a);}
void fill(int a){printf("F %d\n",a);}
int copy(int a){printf("M %d\n",a);return ++bottle_id;}
int min(int a,int b){
	clear(b);
	pull(a,b);
	return b;
}
int max(int a,int b){
	int ta=copy(a),tb=copy(b);
	fill(ta);fill(tb);
	int c=sum(ta,tb);
	b=copy(min(a,b));
	pull(c,b);
	return c;
}
int main(){
	int test_id;scanf("%d",&test_id);
	freopen("code3.out","w",stdout);
	if(test_id==1){
		write(sum(read(),read()));
	}
	if(test_id==2){
		
	}
	if(test_id==3){
		write(max(read(),read()));
	}
	return 0;
}
