//
//  main.cpp
//  Problem M (Transport system)
//
//  Created by Ilyas Karimov on 16.12.20.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000

using namespace std;
int i, j, u, v,cnt = 0, optDistance, n, m, s, f;
vector<vector<int>> g;
vector<int> distS;
vector<int> distF;
void bfs(int start, vector<int> &dist){
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
int main(int argc, const char * argv[]) {
    scanf("%d %d %d %d", &n, &m, &s, &f);
    g.resize(n+1);
    distF.resize(n+1);
    distS.resize(n+1);
    
    for( i = 1; i <=m; i++){
        scanf("%d %d", &u, &v);
        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for( i = 0; i<=n; i++)
        distF[i] = distS[i] = -1;

    bfs(s, distS);
    bfs(f, distF);
    optDistance = distS[f];
    
//    printf("%d\n", distS[f]);
//    for(i = 1; i<=n; i++)
//        printf("%d ", distS[i]);
//
//    puts("");
//    for(i = 1; i<=n; i++)
//        printf("%d ", distF[i]);
//    puts("");
    for(i = 1; i<=n; i++){
        for(j = i+1; j<=n; j++){
//            if(k == p) continue;
//            printf("S: %d F: %d\n", distS[i], distF[j]);
            if (!(distS[i] + 1 + distF[j] < optDistance || distS[j] + 1 + distF[i] < optDistance)) cnt++;
        }
    }

    printf("%d", cnt - m);
}
