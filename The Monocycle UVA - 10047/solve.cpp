#include<cstdio>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
#include<map>
#include <iostream>
#include <cstring>
#include <utility>
#include <iomanip>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define sz 30
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
#define loopk(n) for(int k=0;k<n;k++)
typedef long long LL;
typedef unsigned long long ULL;
//cout << fixed;
//cout << setprecision(2);
//priority_queue<node, vector<node>, greater<node> > q;
/*
struct point{
    int x,y;
    point(int _x,int _y){
        x=_x;
        y=_y;
    }
};
struct Xgreater
{
    bool operator()( const point& lx, const point& rx ) const {
        return lx.x < rx.x;
    }
};

    priority_queue<point,vector<point> , Xgreater> pq;
*/
string graph[sz];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

struct node
{
    int x,y,dir,col,dist;
    node() {}
    node(int xx,int yy,int ddir,int ccol,int ddist)
    {
        x=xx;
        y=yy;
        dir=ddir;
        col=ccol;
        dist=ddist;
    }
};
int dp[sz][sz][4][5];
int main()
{
    //freopen ("input.txt","r",stdin);
    int ks=0;
    while(true)
    {
        ks++;
        memset(dp, 0, sizeof(dp));
        int n,m,stx,sty,ex,ey;
        cin>>n>>m;
        if(n==0&&m==0)break;
        if(ks>1)cout<<endl;
        getchar();
        loop(n)
        {
            getline(cin,graph[i]);
            loopj(m)
            {
                if(graph[i][j]=='S')
                {
                    stx=i;
                    sty=j;
                }
                if(graph[i][j]=='T')
                {
                    ex=i;
                    ey=j;
                }
            }
        }
        int ans=-1;
        queue<node> q;
        q.push(node(stx,sty,0,0,0));
        dp[stx][sty][0][0]=1;

        while(!q.empty())
        {
            node cur=q.front();
            q.pop();

            if(cur.x==ex&&cur.y==ey&&cur.col==0)
            {
                ans=cur.dist;
                break;
            }
            //next node
            node next=node(cur.x+dx[cur.dir],cur.y+dy[cur.dir],cur.dir,(cur.col+1)%5,cur.dist+1);
            if(next.x<0||next.x>=n||next.y<0||next.y>=m||graph[next.x][next.y]=='#') {}
            else if(!dp[next.x][next.y][next.dir][next.col])
            {
                dp[next.x][next.y][next.dir][next.col]=1;
                q.push(next);
            }

            next=node(cur.x,cur.y,(cur.dir+3)%4,cur.col,cur.dist+1);
            if(!dp[next.x][next.y][next.dir][next.col])
            {
                dp[next.x][next.y][next.dir][next.col]=1;
                q.push(next);
            }

            next=node(cur.x,cur.y,(cur.dir+1)%4,cur.col,cur.dist+1);
            if(!dp[next.x][next.y][next.dir][next.col])
            {
                dp[next.x][next.y][next.dir][next.col]=1;
                q.push(next);
            }
        }
        cout<<"Case #"<<ks<<endl;
        if(ans!=-1)
        {
            cout<<"minimum time = "<<ans<<" sec"<<endl;
        }
        else
            cout<<"destination not reachable"<<endl;




    }


    return 0;
}
