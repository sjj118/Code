#include<cstdio>
#include<vector>

using namespace std;

class Fenwick{
    vector<int> a;
    int n;
public:
    void init(int n){
        this->n=n;
        a.resize(n+1);
    }
    void modify(int x,int y){
        for(;x<=n;x+=x&-x)a[x]+=y;
    }
    int query(int x){
        int ret=0;
        for(;x;x-=x&-x)ret+=a[x];
        return ret;
    }
};

int main(){
    return 0;
}
