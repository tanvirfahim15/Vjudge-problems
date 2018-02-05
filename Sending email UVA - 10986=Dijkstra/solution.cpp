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
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define sz 1000001
#define inf 0x3f3f3f3f
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
typedef long long LL;
typedef unsigned long long ULL;
//priority_queue<int, std::vector<int>, decltype(&compare)> pq(&compare);
 //cout << fixed;
//cout << setprecision(2);
vector<pii>graph[sz];
int d[sz];
void dstr(int s){
    priority_queue<pii>pq;
    pq.push(mp(0,s));
    d[s]=0;
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();
        loop(graph[u].size()){
            int v=graph[u][i].first;
            int w=graph[u][i].second;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push(mp(-d[v],v));
            }
        }
    }

}
int main()
{

    freopen ("input.txt","r",stdin);
    int t;
    cin>>t;
    loopj(t)
    {
        int n,m,s,de;
        loop(sz){
            d[i]=inf;
            graph[i].clear();
        }
        cin>>n>>m>>s>>de;
        loop(m)
        {
            int x,y,w;
            cin>>x>>y>>w;
            graph[x].push_back(make_pair(y,w));
            graph[y].push_back(make_pair(x,w));

        }
        dstr(s);
        if(d[de]==inf)
        {
            cout<<"Case #"<<j+1<<": unreachable"<<endl;
        }
        else
            cout<<"Case #"<<j+1<<": "<<d[de]<<"\n";



    }


    return 0;
}
