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

struct point
{
    int x,y;
    point() {}
    point(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
};
struct Xgreater
{
    bool operator()( const point& lx, const point& rx ) const
    {
        return lx.x < rx.x;
    }
};
int main()
{
    //freopen ("input.txt","r",stdin);

    int t;
    cin>>t;
    loopj(t)
    {
        if(j!=0)cout<<endl;
        int m;
        cin>>m;
        vector<point> v,ans;
        int x,y;
        while(true)
        {
            cin>>x>>y;
            if(!x&&!y)
                break;
            if(y>0&&x<m)
                v.pb(point(x,y));
        }
        sort(v.begin(),v.end(),Xgreater());
        int st=0,cov=0;
        bool b=true;
        point temp;
        loop(v.size())
        {
            if(v[i].x>st)
            {
                if(cov>=v[i].x)
                {
                    st=cov;
                    ans.pb(temp);
                }
                else
                {
                    break;
                }
            }
            if(v[i].y>cov)
            {
                cov=v[i].y;
                temp=v[i];
                if(cov>=m)
                {
                    ans.pb(temp);
                    break;
                }
            }

        }
        if(cov>=m)
        {
            sort(ans.begin(),ans.end(),Xgreater());
            cout<<ans.size()<<endl;
            loop(ans.size())
            {
                cout<<ans[i].x<<" "<<ans[i].y<<endl;
            }
        }
        else
        {
            cout<<"0"<<endl;
        }

    }




    return 0;
}
