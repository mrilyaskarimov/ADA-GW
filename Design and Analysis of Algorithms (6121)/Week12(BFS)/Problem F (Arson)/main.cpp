//
//  main.cpp
//  Problem F (Arson)
//
//  Created by Ilyas Karimov on 16.12.20.
//


#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int i, j, n, m, a, b, u, v, k, kel;
vector<int> dist, parent;
vector<vector<int> > g;
vector <int> sources;

void bfs(vector<int> sources)
{
    dist = vector<int>(n + 1, -1);
    parent = vector<int>(n + 1, -1);
    queue<int> q;
    for(int i = 0; i<sources.size(); i++){
        int start = sources[i];
        parent[start] = 1;
        dist[start] = 0;
        q.push(start);
    }

  while (!q.empty())
  {
    // remove vertex v from the queue
    int v = q.front(); q.pop();
    for (int i = 0; i < g[v].size(); i++)
    {
      // there is an edge v -> to
      int to = g[v][i];
      // if vertex v is not visited
      if (dist[to] == -1)
      {
        q.push(to); // push to into the queue
        dist[to] = dist[v] + 1; // recalculate the shortest distance
        parent[to] = v; // if v -> to, parent for to is v
      }
    }
  }
}

int main(void)
{
  //freopen("4853.in","r",stdin);
  scanf("%d %d", &n, &m);

  // construct adjacency list
  g.resize(n + 1);
    for(int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
  }
    int k;
    scanf("%d", &k);
    for(int i = 1; i<=k; i++){
        scanf("%d", &kel);
        sources.push_back(kel);
    }
    
    bfs(sources);
    int mx = -1 , mv = -1;
    for(i = 1; i<=n; i++){
        if(dist[i]>mx){
            mx = dist[i];
            mv = i;
        }
    }
    printf("%d\n",mx);
    printf("%d", mv);
  return 0;
}
