#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 100010

using namespace std;

int T,n,a[maxn];
struct Heap{
	priority_queue<int,vector<int>,greater<int> > A,B;
	int size(){return A.size()-B.size();}
	void update(){while(B.size()&&A.top()==B.top())A.pop(),B.pop();}
	int top(){update();return A.top();}
	void pop(){update();A.pop();}
	void del(int x){B.push(x);}
	void push(int x){A.push(x);}
	void clear(){while(A.size())A.pop();while(B.size())B.pop();}
}H; 

int main(){
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);H.clear();
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),H.push(a[i]);
		int bottom=1,top=0,now=0;
		for(int i=1;i<=n;++i){
			int x=H.top();
			if(bottom>top||x<min(a[bottom],a[top])){
				H.pop();
				while(a[now+1]!=x)H.del(a[++now]),a[++top]=a[now];
				++now;
			}else{
				if(a[bottom]<a[top])x=a[bottom++];
				else x=a[top--];
			}
			printf("%d ",x);
		}
		printf("\n");
	}
	return 0;
}
