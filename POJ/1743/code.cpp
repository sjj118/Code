#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 20010
#define maxp 40010
#define alp 200
#define inf 1e9

using namespace std;

int n,a[maxn];
struct SAM{
	int tot,pre[maxp],son[maxp][alp],step[maxp],minr[maxp],maxr[maxp];
	int newnode(int Step,int Minr,int Maxr){step[++tot]=Step;minr[tot]=Minr;maxr[tot]=Maxr;return tot;}
	void clear(){
		for(int i=1;i<=tot;++i){
			pre[i]=step[i]=minr[i]=maxr[i]=0;
			for(int j=0;j<alp;++j)son[i][j]=0;
		}
		tot=1;
	}
	int ins(int p,int c,int r){
		int np=newnode(step[p]+1,r,r);
		while(p&&!son[p][c])son[p][c]=np,p=pre[p];
		if(p){
			int q=son[p][c];
			if(step[q]==step[p]+1)pre[np]=q;
			else{
				int nq=newnode(step[p]+1,inf,-inf);
				memcpy(son[nq],son[q],sizeof(son[q]));
				pre[nq]=pre[q];
				pre[q]=pre[np]=nq;
				while(son[p][c]==q)son[p][c]=nq,p=pre[p];
			}
		}else pre[np]=1;
		return np;
	}
	int q[maxp],du[maxp];
	void build(int *a,int l){
		clear();
		int last=1,ql=1,qr=0;
		for(int i=0;i<l;++i)last=ins(last,a[i],i);
		for(int i=1;i<=tot;++i)++du[pre[i]];
		for(int i=1;i<=tot;++i)if(!du[i])q[++qr]=i;
		while(ql<=qr){
			int k=q[ql++];--du[pre[k]];
			minr[pre[k]]=min(minr[pre[k]],minr[k]);
			maxr[pre[k]]=max(maxr[pre[k]],maxr[k]);
			if(!du[pre[k]])q[++qr]=pre[k];
		}
	}
	int getans(){
		int ans=-1;
		for(int i=1;i<=tot;++i)ans=max(ans,min(maxr[i]-minr[i],step[i]));
		if(ans<4)ans=-1;
		return ans+1;
	}
}sam;

int main(){
	while(scanf("%d",&n)>0&&n){
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=n;i>=2;--i)a[i]=a[i]-a[i-1]+100;
		sam.build(a+2,n-1);
		printf("%d\n",sam.getans());
	}
	return 0;
}
