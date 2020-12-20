//
//  main.cpp
//  Problem I (Breadth First Search 0-1-2)
//
//  Created by Ilyas Karimov on 16.12.20.
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
  //freopen("10056.in", "r", stdin);
  scanf("%d %d %d %d", &n, &m, &s, &d);
  g.resize(n + 1);
  for (i = 0; i < m; i++)
  {
    scanf("%d %d %d", &a, &b, &w);
    g[a].push_back(make_pair(b, w));
    g[b].push_back(make_pair(a, w));
  }

  bfs(s);
  printf("%d\n", dist[d]);
  return 0;
}

