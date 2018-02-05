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
int main()
{
    //freopen ("input.txt","r",stdin);

    ULL mem[3][46];
    mem[0][0]=0;
    mem[1][0]=0;
    mem[2][0]=0;
    mem[0][1]=1;
    mem[1][1]=0;
    mem[2][1]=1;

    for(int i=2;i<46;i++){
        mem[0][i]=mem[2][i-1]+mem[2][i-2];
        mem[2][i]=mem[0][i-1]+mem[0][i-2];
        mem[1][i]=mem[0][i-1]+mem[2][i-1];
    }
    int n;
    cin>>n;
    cout<<mem[0][n]+mem[2][n]<<endl;





    return 0;
}

