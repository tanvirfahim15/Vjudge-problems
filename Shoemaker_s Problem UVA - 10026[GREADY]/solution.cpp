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
    int t,f,id;
    point(int _t,int _f,int _id)
    {
        t=_t;
        f=_f;
        id=_id;
    }
};
struct Xgreater
{
    bool operator()( const point& lx, const point& rx ) const
    {
        if(lx.t*rx.f==lx.f*rx.t)
            return lx.id<rx.id;
        return lx.t*rx.f<lx.f*rx.t;
    }
};
int main()
{
    //freopen ("input.txt","r",stdin);
    int t;
    cin>>t;
    loopj(t)
    {
        if(j)cout<<endl;
        int n;
        cin>>n;
        vector<point> v;
        loop(n)
        {
            int x,y;
            cin>>x>>y;
            v.pb(point(x,y,i+1));

        }
        sort(v.begin(),v.end(),Xgreater());
        loop(v.size()){
            if(i==0)cout<<v[i].id;
            else cout<<" "<<v[i].id;
        }
        cout<<endl;
        
    }





    return 0;
}
