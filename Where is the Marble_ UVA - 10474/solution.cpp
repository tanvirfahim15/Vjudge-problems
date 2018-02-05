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
#define sz 10002
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


int main()
{
    //freopen ("input.txt","r",stdin);
    int t=0;
    while(true)
    {
        t++;
        int n,q;
        cin>>n>>q;
        if(n==0&&q==0)break;

        cout<<"CASE# "<<t<<":"<<endl;
        int a[sz];
        loop(sz)a[i]=0;
        loop(n)
        {
            int x;
            cin>>x;
            a[x]++;
        }
        loop(sz){
            if(i==0)continue;
            a[i]+=a[i-1];
        }
        loop(q)
        {
            int x;
            cin>>x;
            int an=-1;
            if(x==0&&a[0])an=0;
            else if(a[x]-a[x-1])an=a[x-1]+1;
            if(an>-1)
            {
                cout<<x<<" found at "<<an<<endl;
            }
            else
            {
                cout<<x<<" not found"<<endl;
            }
        }
    }




    return 0;
}
