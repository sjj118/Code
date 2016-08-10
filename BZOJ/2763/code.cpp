#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 200010
#define maxm 3000010
#define node(i,j) ((i)*n+j)

using namespace std;

int s,t,n,m,k;
struct Dij_Node{
	int sign,dis;
	Dij_Node(int Sign,int Dis){sign=Sign;dis=Dis;}
};
bool operator>(Dij_Node a,Dij_Node b){return a.dis>b.dis;}
bool operator==(Dij_Node a,Dij_Node b){return a.sign==b.sign&&a.dis==b.dis;}	
struct Heap{
	priority_queue<Dij_Node,vector<Dij_Node>,greater<Dij_Node> >A,B;
	int size(){return A.size()-B.size();}
	void update(){
	while(B.size()&&
	(A.top()==B.top()))
	A.pop(),B.pop();} 
	void pop(){update();A.pop();}
	void push(Dij_Node x){A.push(x);}
	Dij_Node top(){update();return A.top();}
	void del(Dij_Node x){B.push(x);}
}H;
struct Graph{
	int tot,head[maxn],to[maxm],next[maxm],len[maxm],dis[maxn];
	void ins(int a,int b,int c){to[++tot]=b;len[tot]=c;next[tot]=head[a];head[a]=tot;}
	void addedge(int a,int b,int c){ins(a,b,c);ins(b,a,c);}
	int Dijstra(int s,int t){
		for(int i=0;i<k*n;++i)dis[i]=1e9;dis[s]=0;
		for(int i=0;i<k*n;++i)H.push(Dij_Node(i,dis[i]));
		while(H.size()){
			int k=H.top().sign;H.pop();
			for(int p=head[k];p;p=next[p])if(dis[k]+len[p]<dis[to[p]]){
				H.del(Dij_Node(to[p],dis[to[p]]));
				dis[to[p]]=dis[k]+len[p];
				H.push(Dij_Node(to[p],dis[to[p]]));
			}
		}
		return dis[t];
	}
}G;

int main(){
	scanf("%d%d%d",&n,&m,&k);++k;
	scanf("%d%d",&s,&t);
	for(int i=1;i<k;++i)G.ins(node(i-1,t),node(i,t),0);
	for(int i=0;i<m;++i){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		for(int j=0;j<k;++j)G.addedge(node(j,a),node(j,b),c);
		for(int j=1;j<k;++j)G.ins(node(j-1,a),node(j,b),0),G.ins(node(j-1,b),node(j,a),0);
	}
	printf("%d",G.Dijstra(node(0,s),node(k-1,t)));
	return 0;
}
