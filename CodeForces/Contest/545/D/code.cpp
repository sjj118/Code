#include<cstdio>
#include<cassert>

using namespace std;

int pos[10];
int c=0,p=-1;
int f[10];

int main(){
    f[0]=1;
    for(int i=1;i<10;++i)f[i]=2*f[i-1]+3;
    while(p==-1){
        printf("next");
        assert(pos[9]<f[9]);
        for(int i=0;i<10;++i)if(pos[i]<f[i])printf(" %d",i),++pos[i];
        puts("");
        fflush(stdout);
        int k;scanf("%d",&k);
        int belong[10];
        for(int i=1;i<=k;++i){
            char c=getchar();
            while(c==' ')c=getchar();
            while(c>='0'&&c<='9')belong[c-'0']=i,c=getchar();
        }
        for(int i=0;i<9;++i)if(belong[i]==belong[9]&&pos[i]!=pos[9]){
            p=i;
            break;
        }
    }
    while(true){
        ++c;
        printf("next 9\n");
        ++pos[9];
        fflush(stdout);
        int k;scanf("%d",&k);
        int belong[10];
        for(int i=1;i<=k;++i){
            char c=getchar();
            while(c==' ')c=getchar();
            while(c>='0'&&c<='9')belong[c-'0']=i,c=getchar();
        }
        if(k==1){
            puts("done");
            return 0;
        }
        if(belong[p]==belong[9])break;
    }
    while(true){
        bool flag=false;
        for(int i=1;i<10;++i)if(pos[0]%c!=pos[i]%c)flag=true;
        if(!flag)break;
        printf("next");
        for(int i=1;i<10;++i)if(pos[0]%c!=pos[i]%c)printf(" %d",i),++pos[i];
        puts("");
        fflush(stdout);
        int k;scanf("%d",&k);
        int belong[10];
        for(int i=1;i<=k;++i){
            char c=getchar();
            while(c==' ')c=getchar();
            while(c>='0'&&c<='9')belong[c-'0']=i,c=getchar();
        }
        if(k==1){
            puts("done");
            return 0;
        }
    }
    while(true){
        printf("next");
        for(int i=0;i<10;++i)printf(" %d",i),++pos[i];
        puts("");
        fflush(stdout);
        int k;scanf("%d",&k);
        int belong[10];
        for(int i=1;i<=k;++i){
            char c=getchar();
            while(c==' ')c=getchar();
            while(c>='0'&&c<='9')belong[c-'0']=i,c=getchar();
        }
        if(k==1){
            puts("done");
            return 0;
        }
    }
    return 0;
}
