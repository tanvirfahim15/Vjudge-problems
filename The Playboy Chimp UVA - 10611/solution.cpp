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

int bnl(int v[],int st,int en, int key)
{
    if(st>=en)
    {
        if(v[st]<key)
            return st;
        return st-1;
    }
    int m=(st+en)/2;
    if(v[m]>=key)
    {
        return bnl(v,st,m-1,key);
    }
    return bnl(v,m+1,en,key);
}
int bnh(int v[],int st,int en, int key)
{
    if(st>=en)
    {
        if(v[st]>key)
            return st;
        return st+1;
    }
    int m=(st+en)/2;
    if(v[m]>key)
    {
        return bnh(v,st,m-1,key);
    }
    return bnh(v,m+1,en,key);
}
int main()
{
    //freopen ("input.txt","r",stdin);
    int n;
    cin>>n;
    int v[sz];
    loop(n){
        cin>>v[i];
        cout<<i<<" "<<v[i]<<endl;
    }
    int q;
    cin>>q;
    loop(q){
        int x;
        cin>>x;
        int l=bnl(v,0,n-1,x);
        int h=bnh(v,0,n-1,x);
        cout<<l<<" "<<h<<endl;
    }





    return 0;
}
