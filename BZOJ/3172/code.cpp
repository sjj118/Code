#include<iostream>
#include<cstdio>
#include<cstring>
#define maxp 2000010
#define maxn 1000010
#define alp 26

using namespace std;

struct SAM{
	int tot,last,son[maxp][alp],pa[maxp],step[maxp],right[maxp],du[maxp];
	void clear(){
		for(int i=1;i<=tot;++i){
			for(int j=0;j<alp;++j)son[i][j]=0;
			pa[i]=step[i]=right[i]=du[i]=0;
		}
		tot=last=1;
	}
	void ins(int c){
		int k=++tot;step[k]=step[last]+1;right[k]=1;
		while(last&&!son[last][c])son[last][c]=k,last=pa[last];
		if(last){
			int q=son[last][c];
			if(step[q]==step[last]+1)pa[k]=q;
			else{
				int nq=++tot;step[nq]=step[last]+1;
				memcpy(son[nq],son[q],sizeof(son[q]));
				pa[nq]=pa[q];
				pa[k]=pa[q]=nq;
				while(son[last][c]==q)son[last][c]=nq,last=pa[last];
			}
		}else pa[k]=1;
		last=k;
	}
	int q[maxp],ql,qr;
	void build(char *s){
		clear();int l=strlen(s);
		for(int i=0;i<l;++i)ins(s[i]-'a');
		for(int i=1;i<=tot;++i)++du[pa[i]];
		ql=1;qr=0;
		for(int i=1;i<=tot;++i)if(!du[i])q[++qr]=i;
		while(ql<=qr){
			int k=q[ql++];--du[pa[k]];
			right[pa[k]]+=right[k];
			if(!du[pa[k]])q[++qr]=pa[k];
		}
	}
	int find(char *s){
		int k=1,l=strlen(s);
		for(int i=0;i<l;++i){
			if(son[k][s[i]-'a'])k=son[k][s[i]-'a'];else return 0;
		}
		return right[k];
	}
}sam;
int n,ans[200];
char s[200][maxn];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%s",s[i]);
 	for(int i=0;i<n;++i){
		sam.build(s[i]);
		for(int j=0;j<n;++j)ans[j]+=sam.find(s[j]);
	}
	for(int i=0;i<n;++i)printf("%d\n",ans[i]);
	return 0;
}
