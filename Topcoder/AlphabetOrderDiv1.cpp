#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<cstdlib>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define cls(a) memset(a,0,sizeof(a))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
int n,w[30][30],deg[30],q[30],ql,qr;
class AlphabetOrderDiv1 {
public:
	string isOrdered(vector <string> words) {
		n=words.size();
		rep(i,0,n-1){
			rep(j,0,int(words[i].length())-2)w[words[i][j]-'a'][words[i][j+1]-'a']=1;
		}
		ql=qr=0;
		rep(i,0,25)rep(j,0,25){
			if(i==j)w[i][j]=0;
			else if(w[i][j])++deg[j];
		}
		rep(i,0,25)if(!deg[i])q[qr++]=i;
		while(ql!=qr){
			int k=q[ql++];
			rep(i,0,25)if(w[k][i]&&--deg[i]==0)q[qr++]=i;
		}
		if(qr==26)return "Possible";
		else return "Impossible";
	}
};
/*int main(){
	AlphabetOrderDiv1 a;
	int n;
	vector<string> s;
	scanf("%d",&n);
	rep(i,1,n)s.pb(""),cin>>s[i-1];
	cout<<a.isOrdered(s);
	return 0;
}*/
