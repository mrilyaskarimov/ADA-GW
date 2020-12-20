//
//  main.cpp
//  Problem J (Beehives)
//
//  Created by Ilyas Karimov on 16.12.20.
//

#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#define INF 2000000000
using namespace std;

int cases, cs;
int n, m, i, j;
vector<vector<int> > g;

int bfs(int start)
{
  int res = INF;
  vector<int> d(n,INF);
  vector<int> prev(n,-1);

  queue<int> q;
  q.push(start);
  d[start] = 0;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    
    for (int i = 0; i < g[u].size(); i++)
    {
      int to = g[u][i];
      if (to == prev[u]) continue;

      if (d[to] == INF)
      {
        d[to] = d[u] + 1;
        prev[to] = u;
        q.push(to);
      }
      else
      {
        res = min(res, d[to] + d[u] + 1);
        if (res == 3) return 3;
      }
    }
  }
  return res;
}

int main(void)
{
  //freopen("6427.in", "r", stdin);
  scanf("%d", &cases);
  for (cs = 1; cs <= cases; cs++)
  {
    scanf("%d %d", &n, &m);
    g.clear();
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }

    int res = INF;
    for (i = 0; i < n; i++)
    {
      res = min(res, bfs(i));
      if (res == 3) break;
    }
    
    printf("Case %d: ", cs);
    if (res == INF) puts("impossible");
    else printf("%d\n", res);
  }
  return 0;
}
