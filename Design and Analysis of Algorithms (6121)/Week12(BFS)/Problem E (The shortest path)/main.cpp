//
//  main.cpp
//  Problem E (The shortest path)
//
//  Created by Ilyas Karimov on 16.12.20.
//

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int i, j, n, m, a, b, u, v;
vector<int> dist, parent;
vector<vector<int> > g;

void bfs(int start)
{
  // declare arrays
  parent = vector<int>(n + 1, -1);
  dist = vector<int>(n + 1, -1);
  dist[start] = 0;

  // initialize a queue
  queue<int> q;
  q.push(start);

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
  scanf("%d %d", &a, &b);

  // construct adjacency list
  g.resize(n + 1);
  while (scanf("%d %d", &u, &v) == 2)
  {
    g[u].push_back(v);
    g[v].push_back(u);
  }

  bfs(a); // run bfs from vertex a

  if (parent[b] == -1) // if vertex b is NOT reachable, print -1
    printf("-1\n");
  else
  {
    printf("%d\n", dist[b]); // print shortest distance from a to b
    vector<int> path(1,b); // construct a resulting path
    while (parent[b] != -1) // b, parent[b], parent[parent[b]], ..., source, -1
    {
      b = parent[b];
      path.push_back(b); // insert vertices on the path into vector path
    }

    // print the shortest path in the order from a to b
    for(i = path.size() - 1; i >= 0; i--)
      printf("%d ",path[i]);
    printf("\n");
  }

  return 0;
}
