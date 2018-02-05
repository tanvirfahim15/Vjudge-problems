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
#define sz 11
#define intmax 2147483647
#define loop(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
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
int mem[sz][sz];

int main()
{
    //freopen ("input.txt","r",stdin);
    int t;
    cin>>t;
    for(int tt=0; tt<t; tt++)
    {
        loop(sz)
        {
            loopj(sz)
            {
                mem[i][j]=0;
            }
        }
        int m,n;
        cin>>m>>n;
        vector<int> v;
        loop(m)
        {
            int x;
            cin>>x;
            v.pb(x);
            mem[x][1]=1;
        }
        for(int i=2; i<11; i++)
        {
            for(int j=0; j<v.size(); j++)
            {
                for(int k=0; k<11; k++)
                {
                    int dif=v[j]-k;
                    if(dif<0)
                        dif*=-1;
                    if(dif<=2)
                        mem[v[j]][i]+=mem[k][i-1];
                }
            }
        }
        int ans=0;
        loop(11)
        {
            ans+=mem[i][n];
        }
        cout<<"Case "<<tt+1<<": "<<ans<<endl;

    }






    return 0;
}

