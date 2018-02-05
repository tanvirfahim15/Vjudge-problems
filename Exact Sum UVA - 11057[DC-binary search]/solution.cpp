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
    point(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
};
int _binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        int mid = (low + high)/2; /*low + (high - low)/2;*/

        /* Check if arr[mid] is the first occurrence of x.
            arr[mid] is first occurrence if x is one of the following
            is true:
            (i) mid == 0 and arr[mid] == x
            (ii) arr[mid-1] < x and arr[mid] == x
        */
        if ( (mid == 0 || x > arr[mid-1]) && (arr[mid] == x) )
            return mid;
        else if (x > arr[mid])
            return _binarySearch(arr, (mid + 1), high, x);
        else
            return _binarySearch(arr, low, (mid -1), x);
    }

    return -1;
}
int main()
{
    //freopen ("input.txt","r",stdin);
    int n;
    while(cin>>n)
    {
        int a[sz];
        loop(n)
        {
            cin>>a[i];
        }
        int tot;
        cin>>tot;
        sort(a,a+n);
        vector<point> an;
        loop(n)
        {
            int f=tot-a[i];
            int x=_binarySearch(a,0,n-1,f);
            if(x!=-1)
            {
                if(f>a[i])
                {
                    an.pb(point(a[i],f));
                }
                else
                {
                    an.pb(point(f,a[i]));
                }
            }
        }
        int a1,a2,dif=intmax;
        loop(an.size())
        {
            if(an[i].y-an[i].x<dif)
            {
                dif=an[i].y-an[i].x;
                a1=an[i].x;
                a2=an[i].y;
            }
        }
        cout<<"Peter should buy books whose prices are "<<a1<<" and "<<a2<<"."<<endl;
cout<<endl;


    }



    return 0;
}
