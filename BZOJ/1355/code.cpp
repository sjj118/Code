#include<cstdio>
const int maxn=1e6+10;
using namespace std;

int n,next[maxn];
char s[maxn];

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	next[1]=0;
	for(int i=2,j=0;i<=n;++i){
		while(j&&s[i]!=s[j+1])j=next[j];
		if(s[i]==s[j+1])++j;
		next[i]=j;
	}
	printf("%d",n-next[n]);
	return 0;
}
