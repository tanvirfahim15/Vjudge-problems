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
using namespace std;
#define sz 1000001
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
vector<int>graph[sz];
int c[sz],d[sz],f[sz],p[sz];
int tim=0;
void gflush()
{
    loop(sz)
    {
        c[i]=0;
        d[i]=-1;
        f[i]=-1;
        p[i]=-1;
    }
    tim=0;
}
int cycle=0;
void dfs(int n)
{
    tim++;
    d[n]=tim;
    c[n]=1;
    sort(graph[n].begin(),graph[n].end());
    loop(graph[n].size())
    {
        if(c[graph[n][i]]==0)
        {
            p[graph[n][i]]=n;
            dfs(graph[n][i]);
        }
        else if(c[graph[n][i]]==1&&p[n]!=graph[n][i])
        {
           cycle=1;
        }

    }
    tim++;
    f[n]=tim;
    c[n]=2;
}
int main()
{

    freopen ("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    loop(m)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans=0;
    loop(n)
    {
        if(c[i]==0)
        {
            cycle=0;
            dfs(i);
            if(cycle==0)ans++;


        }
    }
    cout<<ans<<endl;

    return 0;
}
