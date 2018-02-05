#include <bits/stdc++.h>
using namespace std;
int d[10001],c[10001];
vector<int> adjacent[10001];
void fresh(){
    int i;
    for(i=0;i<10001;i++)
    {
        c[i]=0;
        d[i]=0;
        adjacent[i].clear();
    }
}

main()
{
    int test,t;
    scanf("%d",&test);

    for(t=0;t<test;t++){
        if(t!=0)
        printf("\n");
        fresh();
        int p,dq;
        scanf("%d %d",&p,&dq);
        int i;
        for(i=0;i<dq;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            adjacent[x].push_back(y);
            adjacent[y].push_back(x);
        }
        int source=0;
        c[0]=1;
        queue<int> bfs;
        bfs.push(source);
        while(!bfs.empty())
        {
            int cur=bfs.front();
            bfs.pop();
            for(vector<int>::iterator it=adjacent[cur].begin(); it!=adjacent[cur].end(); ++it)
            {
                if(c[*it]==0)
                {
                    c[*it]=1;
                    d[*it]=d[cur]+1;
                    bfs.push(*it);
                }
            }
            c[cur]=2;
        }

        for(i=1;i<p;i++){
           printf("%d\n",d[i]);
        }


    }

}
