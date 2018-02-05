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
int conq(int a[],int l,int mid,int h)
{
    vector<int> ret;
    int inv=0;
    int ll=l,hh=mid+1;
    while(ll<=mid&&hh<=h)
    {
        if(a[ll]<=a[hh])
        {
            ret.pb(a[ll]);
            ll++;
        }
        else
        {
            ret.pb(a[hh]);
            hh++;
            inv+=(mid-ll+1);
        }
    }
    while(ll<=mid)
    {
        ret.pb(a[ll]);
        ll++;
    }
    while(hh<=h)
    {
        ret.pb(a[hh]);
        hh++;
    }
    loop(ret.size())
    {
        a[l+i]=ret[i];
    }
    return inv;
}
int div(int a[], int l,int h)
{
    if(l==h)
    {
        return 0;
    }
    int mid=(l+h)/2;
    int x1=div(a,l,mid);
    int x2=div(a,mid+1,h);
    int x3=conq(a,l,mid,h);
    return x1+x2+x3;
}
int main()
{
    //freopen ("input.txt","r",stdin);
    int t;
    cin>>t;
    loop(t)
    {

        int n;
        cin>>n;
        map<string,int> mp;
        string s;
        vector<string> v;
        loop(n)
        {
            cin>>s;
            v.pb(s);
        }
        loop(n)
        {
            cin>>s;
            mp[s]=i+1;
        }
        vector<int> iv;
        loop(v.size())
        {
            iv.pb(mp[v[i]]);
        }
        int a[sz];
        loop(iv.size())
        {
            a[i]=iv[i];
        }
        cout<<div(a,0,n-1)<<endl;


    }



    return 0;
}
