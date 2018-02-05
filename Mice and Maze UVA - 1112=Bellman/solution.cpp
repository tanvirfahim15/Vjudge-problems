#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
#include<map>
#include <utility>
#include <iomanip>
using namespace std;
#define sz 200
#define intmax 2147483647
#define inf 0x3f3f3f3f
#define loop(n) for(int i=1;i<=n;i++)
#define loopj(n) for(int j=1;j<=n;j++)
#define loopk(n) for(int k=1;k<=n;k++)
typedef long long LL;
typedef unsigned long long ULL;
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
//cout << fixed;
//cout << setprecision(2);
int d[sz][sz];
void gflush()
{
    loop(sz)
    {
        loopj(sz)
        {
            if(i==j)
                d[i][j]=0;
            else
                d[i][j]=inf;
        }
    }
}
int main()
{

    freopen ("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n,e,tm,m;
        cin>>n>>e>>tm>>m;
        gflush();
        loop(m)
        {
            int x,y,w;
            cin>>x>>y>>w;
            d[x][y]=w;
        }

        loopk(n)
        {
            loopj(n)
            {
                loop(n)
                {
                    d[i][j]=min((d[i][k]+d[k][j]),d[i][j]);
                }
            }
        }
        int ans=0;
        loop(n){
            if(d[i][e]<=tm)
                ans++;
        }
        cout<<ans<<endl;
        if(t)cout<<endl;

    }
    return 0;
}
