#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<map>
#define maxn 250010
#define lson son[k][0]
#define rson son[k][1]
#define ws(k) (son[pa[k]][1]==k)

using namespace std;

int m;
struct Treap{
	int tot,rnd[maxn],key[maxn],son[maxn][2],pa[maxn],root,size[maxn];
	char*val[maxn];
	void set(int a,int b,int c){pa[a]=b;son[b][c]=a;}
	int newNode(int _key,char*_val){
		rnd[++tot]=rand()+1;key[tot]=_key;val[tot]=_val;size[tot]=1;return tot;
	}
	void pushup(int k){
		size[k]=size[lson]+size[rson]+1;
	}
	void rot(int k){
		int f=pa[k],gf=pa[f],w=ws(k);
		set(k,gf,ws(f));set(son[k][!w],f,w);set(f,k,!w);
		pushup(f);pushup(k);if(!pa[k])root=k;
	}
	void ins(int&k,int p){
		if(!k){k=p;return;}
		++size[k];
		if(key[p]<key[k])ins(lson,p);else ins(rson,p);
		if(rnd[pa[p]]<rnd[p])rot(p);
	}
	void del(int k){
		while(lson||rson)if(rnd[lson]>rnd[rson])rot(lson);else rot(rson);
		int p=pa[k];son[p][ws(k)]=0;pa[k]=0;
		while(p)pushup(p),p=pa[p];
	}
}T;
map<char*,int> id;
int getint(char*s){
	int tmp=0;
	while(*s!='\0')tmp=tmp*10+*s-'0',++s;
	return tmp;
}

int main(){
	srand(time(0));
	scanf("%d\n",&m);
	for(int i=1;i<=m;++i){
		char op,s[10];
		scanf("%c",&op);
		if(op=='+'){
			int x;
			scanf("%s %d",s,&x);
			if(id.find(s)==id.end())T.ins(T.root,id[s]=T.newNode(x,s));
			else T.del(id[s]),T.key[id[s]]=x,T.ins(T.root,id[s]);
		}else if(op=='?'){
			scanf("%s",s);
			if(s[0]>='0'&&s[0]<='9'){
				int index=getint(s);
				
			}else{
				
			}
		}
	}
	return 0;
}
