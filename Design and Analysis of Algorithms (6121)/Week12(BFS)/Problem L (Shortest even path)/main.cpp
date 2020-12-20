//
//  main.cpp
//  Problem L (Shortest even path)
//
//  Created by Ilyas Karimov on 16.12.20.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;
int i, j, u, v, u1, u2, v1, v2, n, m, s, f;
vector<vector<int>> g;
vector<int>dist;

void bfs(int start){
    dist[start] = 0;
    queue<int>q;
    q.push(start);
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int i = 0; i < g[v].size(); i++){
           int to = g[v][i];
           if (dist[to] == -1){
               q.push(to);
               dist[to] = dist[v] + 1;
           }
         }
    }
}

 int main(void){
     scanf("%d %d %d %d", &n,&m, &s, &f);
     
     g.resize(2*n+1);
     dist.resize(2*n+1);
     
     for(i = 1; i<=m; i++){
         scanf("%d %d", &u, &v);
         u1 = u*2 - 1;
         u2 = u*2;
         v1 = v*2 - 1;
         v2 = v*2;
         
         g[u1].push_back(v2);
         g[v2].push_back(u1);
         
         g[u2].push_back(v1);
         g[v1].push_back(u2);
     }
     for (i = 0; i < dist.size(); i++)
            dist[i] = -1;
     bfs(2*s-1);
     printf("%d", dist[2*f-1]);
}
