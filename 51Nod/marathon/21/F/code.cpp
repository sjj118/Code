#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a) memset(a,0,sizeof(a))
#include<assert.h>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
using namespace std;
typedef long long LL;
const int N=2e5+10,alp=30;
const LL inf=1e18+10;
inline void ad(LL&x,LL y){x=min(x+y,inf);}
struct LinkMap{
	int tot,head[N<<1],next[N*alp*2],to[N*alp*2];
	void ins(int a,int b){to[++tot]=b;next[tot]=head[a];head[a]=tot;}
};
LL sumst[N<<1];
struct World{
	int n,tson[N][alp],sg[N<<1];
	LL pathcount[N<<1],sumsg[alp+5],sumwithoutsg[alp+5];
	int nid[N];
	int tot,son[N<<1][alp],pr[N<<1],step[N<<1];
	LinkMap fson;
	World(){tot=1;}
	int ins(int c,int lst){
		//if(son[lst][c]){
		//	int q=son[lst][c];
		//	if(step[q]==step[lst]+1)return son[lst][c];
		//	else{
		//		int nq=++tot;step[nq]=step[lst]+1;
		//		memcpy(son[nq],son[q],sizeof(son[q]));
		//		pr[nq]=pr[q];
		//		pr[q]=nq;
		//		while(lst&&son[lst][c]==q)son[lst][c]=nq,lst=pr[lst];
		//		return nq;
		//	}
		//}
		int k=++tot;step[k]=step[lst]+1;
		while(lst&&son[lst][c]==0)son[lst][c]=k,lst=pr[lst];
		if(lst){
			int q=son[lst][c];
			if(step[q]==step[lst]+1)pr[k]=q;
			else{
				int nq=++tot;step[nq]=step[lst]+1;
				memcpy(son[nq],son[q],sizeof(son[q]));
				pr[nq]=pr[q];
				pr[q]=pr[k]=nq;
				while(lst&&son[lst][c]==q)son[lst][c]=nq,lst=pr[lst];
			}
		}else pr[k]=1;
		return k;
	}
	void input(){
		scanf("%d",&n);
		nid[1]=1;
		rep(i,2,n+1){
			int pre;char event;scanf("%d %c",&pre,&event);
			nid[i]=ins(event-'a',nid[pre+1]);
			//if(tson[nid[pre+1]][event-'a'])nid[i]=tson[nid[pre+1]][event-'a'];
			//else nid[i]=i,tson[nid[pre+1]][event-'a']=i;
		}
	}
	void buildfson(){
		rep(i,1,tot)rep(j,0,alp-1)if(son[i][j])fson.ins(son[i][j],i);
	}
	void getsg(){
		static int q[N<<1],ql,qr,deg[N<<1];
		cls(deg);
		ql=qr=0;
		rep(i,1,tot)for(int p=fson.head[i];p;p=fson.next[p])++deg[fson.to[p]];
		rep(i,1,tot)if(deg[i]==0)q[qr++]=i;
		static int hash[alp+5];
		cls(hash);
		while(ql!=qr){
			int k=q[ql++];
			rep(i,0,alp-1)if(son[k][i])hash[sg[son[k][i]]]=1;
			rep(i,0,alp)if(!hash[i]){sg[k]=i;break;}
			rep(i,0,alp-1)if(son[k][i])hash[sg[son[k][i]]]=0;
			for(int p=fson.head[k];p;p=fson.next[p]){
				if(--deg[fson.to[p]]==0)q[qr++]=fson.to[p];
			}
		}
	}
	void getsumsg(){
		rep(i,1,tot)ad(sumsg[sg[i]],pathcount[i]);
		rep(i,0,alp)rep(j,0,alp)if(i!=j)ad(sumwithoutsg[i],sumsg[j]);
	}
	void getpathcount(){
		static int q[N<<1],ql,qr,deg[N<<1];
		cls(deg);
		ql=qr=0;
		rep(i,1,tot)rep(j,0,alp-1)if(son[i][j])++deg[son[i][j]];
		rep(i,1,tot)if(deg[i]==0)q[qr++]=i;
		pathcount[1]=1;
		while(ql!=qr){
			int k=q[ql++];
			rep(i,0,alp-1)if(son[k][i]){
				ad(pathcount[son[k][i]],pathcount[k]);
				if(--deg[son[k][i]]==0)q[qr++]=son[k][i];
			}
		}
	}
	LL sumstwithoutsg[N<<1];
	void getNth(LL n,int nsg){
		static int q[N<<1],ql,qr,deg[N<<1];
		cls(deg);
		ql=qr=0;
		rep(i,1,tot)for(int p=fson.head[i];p;p=fson.next[p])++deg[fson.to[p]];
		rep(i,1,tot)if(deg[i]==0)q[qr++]=i;
		while(ql!=qr){
			int k=q[ql++];
			if(sg[k]!=nsg)++sumstwithoutsg[k];
			rep(i,0,alp-1)if(son[k][i])ad(sumstwithoutsg[k],sumstwithoutsg[son[k][i]]);
			for(int p=fson.head[k];p;p=fson.next[p]){
				if(--deg[fson.to[p]]==0)q[qr++]=fson.to[p];
			}
		}

		int k=1;
		while(1){
			if(sg[k]!=nsg){
				if(--n==0){
					return;
				}
			}
			rep(i,0,alp-1)if(son[k][i]){
				if(n<=sumstwithoutsg[son[k][i]]){
					printf("%c",i+'a');
					k=son[k][i];
					break;
				}else n-=sumstwithoutsg[son[k][i]];
			}
		}
	}
}A,B;
void getsumst(){
	static int q[N<<1],ql,qr,deg[N<<1];
	ql=qr=0;
	rep(i,1,A.tot)for(int p=A.fson.head[i];p;p=A.fson.next[p])++deg[A.fson.to[p]];
	rep(i,1,A.tot)if(deg[i]==0)q[qr++]=i;
	while(ql!=qr){
		int k=q[ql++];
		sumst[k]=B.sumwithoutsg[A.sg[k]];
		rep(i,0,alp-1)if(A.son[k][i])ad(sumst[k],sumst[A.son[k][i]]);
		for(int p=A.fson.head[k];p;p=A.fson.next[p]){
			if(--deg[A.fson.to[p]]==0)q[qr++]=A.fson.to[p];
		}
	}
}
int main(){
	LL QK;scanf("%lld",&QK);
	A.input();
	B.input();
	//A.build(1,1);
	//B.build(1,1);
	A.buildfson();
	B.buildfson();
	A.getsg();
	B.getsg();
	A.getpathcount();
	B.getpathcount();
	A.getsumsg();
	B.getsumsg();
	getsumst();
	if(QK>sumst[1]){puts("K is too large!");return 0;}
	int k=1;
	while(1){
		if(B.sumwithoutsg[A.sg[k]]>=QK){
			puts("");B.getNth(QK,A.sg[k]);
			break;
		}else QK-=B.sumwithoutsg[A.sg[k]];
		rep(i,0,alp-1)if(A.son[k][i]){
			if(QK<=sumst[A.son[k][i]]){
				k=A.son[k][i];
				printf("%c",i+'a');
				break;
			}else QK-=sumst[A.son[k][i]];
		}
	}
	return 0;
}
