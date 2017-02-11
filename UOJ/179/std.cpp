#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
//--
char buf[1<<15], *fs, *ft;
inline char readc()
{
    //这行代码真nb%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%信息量好大...
    return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;
}
inline int fast_read()
{
    int r;
    char c;
    bool sig = false;
    while((c = readc()))
    {
        if(c >= '0' && c <= '9')
        {
            r = c^0x30;
            break;
        }else if(c == '-')sig = true;
    }
    while(isdigit(c = readc()))
        r = (r<<3)+(r<<1)+(c^0x30);
    return sig?-r:r;
}
//----------------
int n, m, tsk;
double A[23][23];
int base[23], unbase[23];
const double eps = 1e-9;
inline int dcmp(double x)
{
    if(x < -eps)return -1;
    else if(x > eps)return 1;
    else return 0;
}
void pivot(int x, int y)
{
    swap(base[x], unbase[y]);  //互换变量?
    double k = A[x][y];
    A[x][y] = 1;
    for(int i = 0; i <= n; i++)
        A[x][i] /= k;
    for(int i = 0; i <= m; i++)
    {
        if(i != x && dcmp(k = A[i][y]))
        {
            A[i][0] += (i?-1:1)*k*A[x][0];
            A[i][y] = 0;
            for(int j = 1; j <= n; j++)
                A[i][j] -= k*A[x][j];
        }
    }
}
bool init_simplex()
{
    for(int i = 1; i <= n; i++)unbase[i] = i;
    for(int i = 1; i <= m; i++)base[i] = n+i;  //多的m个变量
    for(int x = 0, y = 0; true; x = y = 0)
    {
        for(int i = 1; i <= m; i++)
           // if(dcmp(A[i][0]) < 0)) //mdzz就个这调了半个上午...
            if(dcmp(A[i][0]) < 0)  //负的
                x = i;
        if(!x)return true;
        for(int i = 1; i <= n; i++)
            if(dcmp(A[x][i]) < 0) //也是负的
                y = i;
        if(!y)return false;
        pivot(x, y);
    }
}
int simplex()
{
    if(!init_simplex())return 0;
    for(int x = 0, y = 0; true; x = y = 0)
    {
        for(int i = 1; i <= n; i++)
        {
            if(dcmp(A[0][i]) > 0)
            {
                y = i;
                break;
            }
        }
        if(!y)return 1;
        double large = 1e15;
        for(int i = 1; i <= m; i++)
        {
            if(dcmp(A[i][y]) > 0 && (!x || A[i][0]/A[i][y] < large))
            {
                large = A[i][0]/A[i][y];
                x = i;
            }
        }
        if(!x)return -1;
        pivot(x, y);
    }
}
void init()
{
   // freopen("simplex.in", "r", stdin);
    n = fast_read();
    m = fast_read();
    tsk = fast_read();
    for(int i = 1; i <= n; i++)
        A[0][i] = fast_read();  //最大化条件的系数c1,c2...cn
    for(int i = 1; i <= m; A[i++][0] = fast_read()) //A[i][0]为第i个约束条件要求的小于的数...
        for(int j = 1; j <= n; j++)
            A[i][j] = fast_read();
}
int main()
{
    init();
    switch(simplex())
    {
        case 1:
            printf("%.8lf", A[0][0]);  //目标函数最大值...
            if(tsk)
            {
                putchar('\n');
                for(int i = 1; i <= n; i++)unbase[i] = 0;
                for(int i = 1; i <= m; i++)
                    if(base[i] <= n)
                        unbase[base[i]] = i;
                for(int i = 1; i <= n; i++)
                    printf("%.8lf ", unbase[i]?A[unbase[i]][0]:0.0);
                    
            }
        break;
        case 0:
            puts("Infeasible");
        break;
        case -1:
            puts("Unbounded");
        break;
    }
    return 0;
}
