//
//  main.cpp
//  Problem E (Tram)
//
//  Created by Ilyas Karimov on 01.01.21.
//


#include <iostream>
#include <deque>
#include <vector>
#define INF 0x3F3F3F3F

using namespace std;

vector<vector<pair<int,int>>>g;
vector<int>dist;
int n,a,b,k,ki,w;

void bfs(int start){
  dist = vector<int>(n + 1, INF);
  dist[start] = 0;
  deque<int> q;
  q.push_back(start);
  while (!q.empty()){
    int v = q.front(); q.pop_front();
    for (int i = 0; i < g[v].size(); i++){
      int to = g[v][i].first;
      int w = g[v][i].second;

      if (dist[to] > dist[v] + w){
        dist[to] = dist[v] + w;
        if (w == 1)
          q.push_back(to);
        else
          q.push_front(to);
      }
    }
  }
}
int main(int argc, const char * argv[]) {
    scanf("%d %d %d", &n, &a, &b);
    g.resize((n+1));
    for(int i = 1; i<=n; i++){
        scanf("%d", &k);
        for(int j = 1; j <= k; j++){
            scanf("%d", &ki);
            if(j == 1) w = 0;
            else w = 1;
            g[i].push_back(make_pair(ki, w));
        }
    }
    bfs(a);
    if(dist[b] == INF) printf("-1");
    else printf("%d", dist[b]);
}
