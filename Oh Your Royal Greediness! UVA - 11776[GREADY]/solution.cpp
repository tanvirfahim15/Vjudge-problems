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
struct point{
    int time,type;
    point(int _x,int _y){
        time=_x;
        type=_y;
    }
};

struct Xgreater
{
    bool operator()( const point& lx, const point& rx ) const {
        if(lx.time==rx.time)return lx.type<rx.type;
        return lx.time<rx.time;
    }
};
int main()
{
    //freopen ("input.txt","r",stdin);
    int t=0;
    while(true){
        int n;
        cin>>n;
        if(n<0)break;
        vector<point> v;
        loop(n){
            int x,y;
            cin>>x>>y;
            v.pb(point(x,1));
            v.pb(point(y,2));
        }
        sort(v.begin(),v.end(),Xgreater());
        int ans=0,sum=0;
        loop(v.size()){
            if(v[i].type==1)sum++;
            else sum--;
            if(sum>ans)ans=sum;
        }
        cout<<"Case "<<t+1<<": "<<ans<<endl;
        t++;
    }





    return 0;
}
