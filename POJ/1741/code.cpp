#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10005

using namespace std;

int n,q;
struct graph{
	int tot,head[maxn],to[maxn*2],next[maxn*2],len[maxn*2],size[maxn],depth[maxn];
	bool mark[maxn];
	void addedge(int a,int b,int l){
		to[++tot]=b;
		next[tot]=head[a];
		head[a]=tot;
		len[tot]=l;
	}
	void clear(){
		tot=0;
		memset(head,0,sizeof(head));
		memset(to,0,sizeof(to));
		memset(len,0,sizeof(len));
		memset(next,0,sizeof(next));
		memset(size,0,sizeof(size));
		memset(depth,0,sizeof(depth));
		memset(mark,0,sizeof(mark));
	}
	void findSize(int k,int pre){
		size[k]=1;
		for(int p=head[k];p;p=next[p])if((to[p]!=pre)&&!mark[to[p]]){
			findSize(to[p],k);
			size[k]+=size[to[p]];
		}
	}
	int findG(int k,int s,int pre){
		int flag=k;
		for(int p=head[k];p;p=next[p])if((to[p]!=pre)&&!mark[to[p]]){
			int t=findG(to[p],s,k);
			if(t)return t;
			if(size[to[p]]*2>s)flag=0;
		}
		if(2*(s-size[k])>s)flag=0;
		return flag;
	}
	int list[maxn],cnt;
	void findDepth(int k,int pre){
		list[cnt++]=depth[k];
		for(int p=head[k];p;p=next[p])if((to[p]!=pre)&&!mark[to[p]]){
			depth[to[p]]=depth[k]+len[p];
			findDepth(to[p],k);
		}
	}
	int solve(int k){
		mark[k]=1;
		depth[k]=0;
		cnt=1;
		int ans=0,last=1;
		depth[k]=0;
		list[0]=0;
		for(int p=head[k];p;p=next[p])if(!mark[to[p]]){
			depth[to[p]]=len[p];
			findDepth(to[p],k);
			sort(list+last,list+cnt);
			for(int i=last,j=cnt-1;i<cnt&&i<j;++i){
				while(j>i&&list[i]+list[j]>q)--j;
				if(list[i]+list[j]<=q)ans-=j-i;
			}
			last=cnt;
		}
		sort(list,list+cnt);
		for(int i=0,j=cnt-1;(i<cnt)&&(i<j);++i){
			while((j>i)&&list[i]+list[j]>q)--j;
			if(list[i]+list[j]<=q)ans+=j-i;
		}
		for(int p=head[k];p;p=next[p])if(!mark[to[p]]){
			findSize(to[p],0);
			ans+=solve(findG(to[p],size[to[p]],0));
		}
		return ans;
	}
} G;
int main(){
	while(scanf("%d%d",&n,&q)>0&&(n||q)){
		G.clear();
		for(int i=1;i<n;++i){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			G.addedge(a,b,c);
			G.addedge(b,a,c);
		}
		G.findSize(1,0);
		printf("%d\n",G.solve(G.findG(1,n,0)));
	}
	return 0;
}
