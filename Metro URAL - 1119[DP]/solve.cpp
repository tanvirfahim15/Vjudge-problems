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
#define sz 1002
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
    float mem[sz][sz];
    int diag[sz][sz];

    loop(sz){
        loopj(sz)
        {
            mem[i][j]=0;
            diag[i][j]=0;
        }
    }
    int n,m,k;
    cin>>n>>m>>k;
    loop(k){
        int x,y;
        cin>>x>>y;
        diag[x][y]=1;
    }
    loop(sz){
        mem[i][0]=i*100;
        mem[0][i]=i*100;
    }

    for(int i=1;i<sz;i++){
        for(int j=1;j<sz;j++){
            mem[i][j]=mem[i-1][j]+100;
            if(mem[i][j]>mem[i][j-1]+100)
                mem[i][j]=mem[i][j-1]+100;
            if(diag[i][j]&&mem[i][j]>mem[i-1][j-1]+sqrt(20000)){
                mem[i][j]=mem[i-1][j-1]+sqrt(20000);
            }
        }
    }
    mem[n][m]+=.5;
    cout<<(int)mem[n][m]<<endl;






    return 0;
}
