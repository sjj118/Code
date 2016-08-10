#include<iostream>
#include<cstdio>
#include<cstring>
#define maxp 100000
#define alp 26

using namespace std;

struct SAM{
	int tot,pre[maxp],son[maxp][alp],step[maxp];
	void clear(){tot=1;}
	int ins(int p,int c){
		int np=++tot;step[np]=step[p]+1;
		while(p&&!son[p][c])son[p][c]=np,p=pre[p];
		if(p){
			int q=son[p][c];
			if(step[q]==step[p]+1)pre[np]=q;
			else{
				int nq=++tot;step[nq]=step[p]+1;
				memcpy(son[nq],son[q],sizeof(son[q]));
				pre[nq]=pre[q];
				pre[q]=pre[np]=nq;
				while(son[p][c]==q)son[p][c]=nq,p=pre[p];
			}
		}else pre[p]=1;
		return p;
	}
}sam;

int main(){
	
	return 0;
}
