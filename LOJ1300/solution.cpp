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
#define sz 100001
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);

vector<int>graph[sz];
vector<pair<int,int> >br;
int d[sz],c[sz],f[sz],p[sz],comp[sz],low[sz],cnt[sz];
int tim=0,cmp=0,bridge=0;
void gnew()
{
    loop(sz)
    {
        comp[i]=-1;

        graph[i].clear();
    }
    br.clear();
}
void gflush()
{
    loop(sz)
    {
        d[i]=-1;
        f[i]=-1;
        c[i]=0;
        p[i]=-1;
        cnt[i]=0;
        low[i]=intmax;
    }
    tim=0;
}
void dfs(int n)
{
    tim++;
    d[n]=tim;
    c[n]=1;
    low[n]=d[n];
    loop(graph[n].size())
    {
        int cur=graph[n][i];
        if(c[cur]==0)
        {
            p[cur]=n;
            dfs(cur);
            if(low[cur]>d[n])
            {
                br.push_back(make_pair(cur,n));
                 bridge++;
            }

            else if(low[cur]<low[n])
            {
                low[n]=low[cur];
            }
        }
        else if(p[n]!=cur)
        {
            if(d[cur]<low[n])
                low[n]=d[cur];
        }
    }
    tim++;
    f[n]=tim;
    c[n]=2;
}


void removebr()
{
    loop(br.size())
    {
        int n=br[i].first;
        int cur=br[i].second;
        graph[n].erase(std::remove(graph[n].begin(), graph[n].end(), cur), graph[n].end());
        graph[cur].erase(std::remove(graph[cur].begin(), graph[cur].end(), n), graph[cur].end());
    }
}
void dfs2(int n)
{
    tim++;
    d[n]=tim;
    c[n]=1;
    comp[n]=cmp;
    loop(graph[n].size())
    {
        int cur=graph[n][i];
        if(c[cur]==0)
        {
            p[cur]=n;
            dfs2(cur);

        }

    }
    tim++;
    f[n]=tim;
    c[n]=2;
}
int bfs(int s)
{

    queue<int>q;
    c[s]=1;
    d[s]=0;
    int cnt=1;
    q.push(s);
    bool b=false;
    while(!q.empty())
    {
        int cur=q.front();
        loop(graph[cur].size())
        {
            if(c[graph[cur][i]]==0)
            {
                cnt++;
                if(c[cur]==2)
                c[graph[cur][i]]=1;

                else if(c[cur]==1)
                c[graph[cur][i]]=2;
                d[graph[cur][i]]=d[cur]+1;
                q.push(graph[cur][i]);
            }
            else if(c[cur]==c[graph[cur][i]]){
                b=true;
            }
        }
        q.pop();
    }
    if(b){

        return cnt;
    }
    else return 0;
}


int main()
{

    //freopen ("input.txt","r",stdin);
    //LightOJ - 1300
    int t;
    scanf("%d",&t);
    loopj(t)
    {

        gflush();
        gnew();
        int n,m;
        scanf("%d %d",&n,&m);
        bridge=0;
        loop(m)
        {
            int x,y;

            scanf("%d %d",&x,&y);

            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        loop(n)
        {
            if(c[i]==0)
                dfs(i);
        }
        gflush();
        removebr();

        cmp=0;
        loop(n)
        {
            if(c[i]==0)
            {
                dfs2(i);
                cmp++;
            }
        }
            gflush();
        int ans=0;
        loop(n){
            if(c[i]==0){
                ans+=bfs(i);
            }
        }
        printf("Case %d: %d\n",j+1,ans);

    }

    return 0;
}
