#include<iostream>
#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
const int maxn=5010,mo=1e8;
using namespace std;
inline void ck(int&x){while(x<0)x+=mo;while(x>=mo)x-=mo;}
inline void ad(int&x,int y){x+=y;ck(x);}
int n,m,a[maxn],b[maxn],len[2][maxn],num[2][maxn];

int main(){
	char c=getchar();
	while(c<'A'||c>'Z')c=getchar();
	while(c!='.')a[++n]=c-'A',c=getchar();
	while(c<'A'||c>'Z')c=getchar();
	while(c!='.')b[++m]=c-'A',c=getchar();
	num[0][0]=num[1][0]=1;
	rep(j,1,m)num[0][j]=1;
	rep(i,1,n)rep(j,1,m){
		len[i&1][j]=max(len[i&1][j-1],len[i&1^1][j]);num[i&1][j]=0;
		if(a[i]==b[j]){
			len[i&1][j]=max(len[i&1][j],len[i&1^1][j-1]+1);
			if(len[i&1][j]==len[i&1^1][j-1]+1)ad(num[i&1][j],num[i&1^1][j-1]);
		}
		if(len[i&1][j-1]==len[i&1][j])ad(num[i&1][j],num[i&1][j-1]);
		if(len[i&1^1][j]==len[i&1][j])ad(num[i&1][j],num[i&1^1][j]);
		if(len[i&1][j-1]==len[i&1][j]&&len[i&1^1][j]==len[i&1][j]&&len[i&1][j]==len[i&1^1][j-1])ad(num[i&1][j],-num[i&1^1][j-1]);
	}
	printf("%d\n%d",len[n&1][m],num[n&1][m]);
	return 0;
}
