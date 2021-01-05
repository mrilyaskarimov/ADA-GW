//
//  main.cpp
//  Problem B (Ordering tasks)
//
//  Created by Ilyas Karimov on 20.12.20.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int> > graph;
vector<int> InDegree, top;
deque<int> q;
int i, j, a, b, n, m, v, to;

int main(int argc, const char * argv[]) {
 
    while(scanf("%d %d",&n,&m) == 2){
        if( n == 0 && m == 0) break;
        graph.assign(n+1,vector<int>());
        InDegree.assign(n+1,0);
        for(i = 0; i < m; i++){
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
        }
        
        for(i = 1; i < graph.size(); i++)
        for(j = 0; j < graph[i].size(); j++)
        {
        to = graph[i][j];
        InDegree[to]++;
        }
        
        for(i = 1; i < InDegree.size(); i++)
        if (!InDegree[i]) q.push_back(i);
        
        while(!q.empty()){
            v = q.front(); q.pop_front();
            top.push_back(v);
            for(i = 0; i < graph[v].size(); i++)
            {
            to = graph[v][i];
            InDegree[to]--;
            if(!InDegree[to]) q.push_back(to);
            }
        }
        if (top.size() < n)
        printf("-1\n");
        
        else
        {
            for(i = 0; i < top.size(); i++) printf("%d ",top[i]);
            printf("\n");
        }
        top.clear();
    }
}

