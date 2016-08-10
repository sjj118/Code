#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<vector<int> > m(n+1);
	for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        m[u].push_back(v);
        m[v].push_back(u);
    }
    int w[n+1];
    int max=0,sum=0;
    for(int i=1;i<n+1;++i)cin>>w[i];
    for(int i=1;i<n+1;++i){
        int ma=0,su=0,secm=0;
        for(int j=0;j<m[i].size();++j){
            if(w[m[i][j]]>ma){
                secm=ma;
                ma=w[m[i][j]];
            }else if(w[m[i][j]]>secm)secm=w[m[i][j]];
            su=10007+(su+w[m[i][j]])%10007;
        }
        if(ma*secm>max)max=ma*secm;
        for(int j=0;j<m[i].size();++j){
            sum=(sum+(su-w[m[i][j]]%10007)*w[m[i][j]])%10007;
        }
    }
    cout<<max<<' '<<sum;
}
