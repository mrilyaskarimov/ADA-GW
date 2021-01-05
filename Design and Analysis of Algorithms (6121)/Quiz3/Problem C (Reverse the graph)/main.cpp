//
//  main.cpp
//  Problem C (Reverse the graph)
//
//  Created by Ilyas Karimov on 01.01.21.
//

#include <cstdio>
#include <deque>
#include <vector>
#define INF 0x3F3F3F3F
using namespace std;

int i, n, m, a, b, s, d, w;
vector<int> dist;
vector<vector<pair<int, int> > > g;

void bfs(int start)
{
  dist = vector<int>(n + 1, INF);
  dist[start] = 0;

  deque<int> q;
  q.push_back(start);

  while (!q.empty())
  {
    int v = q.front(); q.pop_front();
    for (int i = 0; i < g[v].size(); i++)
    {
      int to = g[v][i].first;
      int w = g[v][i].second;

      if (dist[to] > dist[v] + w)
      {
        dist[to] = dist[v] + w;
        if (w == 1)
          q.push_back(to);
        else
          q.push_front(to);
      }
    }
  }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    g.resize(n + 1);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a].push_back(make_pair(b, 0));
        g[b].push_back(make_pair(a, 1));
    }
    bfs(1);
    if(dist[n] == INF) printf("-1\n");
    else printf("%d\n", dist[n]);
    return 0;
}
