#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 1010
#define maxp 2100000
#define maxv 6100000
#define inf 1e9

using namespace std;

int readint(){
	int tmp=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')tmp=tmp*10+c-'0',c=getchar();
	return tmp;
}
int n,m,start,end,node[maxn][maxn][2];
struct Dij_Node{
	int sign,dis;
	Dij_Node(int Sign,int Dis){sign=Sign;dis=Dis;}
};
bool operator>(Dij_Node a,Dij_Node b){return a.dis>b.dis;}
bool operator==(Dij_Node a,Dij_Node b){return a.sign==b.sign&&a.dis==b.dis;}
struct Heap{
	priority_queue<Dij_Node,vector<Dij_Node>,greater<Dij_Node> > A,B;
	int size(){return A.size()-B.size();}
	void update(){while(B.size()&&A.top()==B.top())A.pop(),B.pop();} 
	void pop(){update();A.pop();}
	void push(Dij_Node x){A.push(x);}
	Dij_Node top(){update();return A.top();}
	void del(Dij_Node x){B.push(x);}
}H;
struct Graph{
	int tot,pointsize,head[maxp],to[maxv],next[maxv],len[maxv],dis[maxp];
	void getp(int&x){if(!x)x=++pointsize;}
	void ins(int a,int b,int c){to[++tot]=b;len[tot]=c;next[tot]=head[a];head[a]=tot;}
	void addedge(int&a,int&b,int c){getp(a);getp(b);ins(a,b,c);ins(b,a,c);}
	int Dij(int s,int t){
		for(int i=1;i<=pointsize;++i)dis[i]=inf;dis[s]=0;
		for(int i=1;i<=pointsize;++i)H.push(Dij_Node(i,dis[i]));
		for(int i=1;i<pointsize;++i){
			int k=H.top().sign;H.pop();
			for(int p=head[k];p;p=next[p])if(dis[to[p]]>dis[k]+len[p]){
				H.del(Dij_Node(to[p],dis[to[p]]));
				dis[to[p]]=dis[k]+len[p];
				H.push(Dij_Node(to[p],dis[to[p]]));
			}
		}
		return dis[t];
	}
}G;

int main(){
	n=readint();m=readint();
	for(int i=1;i<=n;++i)for(int j=1;j<m;++j){int x=readint();G.addedge(i==1?start:node[i-1][j][1],i==n?end:node[i][j][0],x);}
	for(int i=1;i<n;++i)for(int j=1;j<=m;++j){int x=readint();G.addedge(j==1?end:node[i][j-1][0],j==m?start:node[i][j][1],x);}
	for(int i=1;i<n;++i)for(int j=1;j<m;++j){int x=readint();G.addedge(node[i][j][0],node[i][j][1],x);}
	printf("%d",G.Dij(start,end));
	return 0;
}
