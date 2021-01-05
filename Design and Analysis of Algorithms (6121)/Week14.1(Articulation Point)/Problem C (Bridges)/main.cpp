//
//  main.cpp
//  Problem C (Bridges)
//
//  Created by Ilyas Karimov on 21.12.20.
//

#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int> > graph;
vector<int> used, d, up;
int i, n, m, a, b, ti;
set<int> Bridges;
set<int>::iterator iter;
map<pair<int,int>, int> mp;

pair<int,int> Edge(int a, int b)
{
  if (a > b) swap(a,b);
  return make_pair(a,b);
}

void dfs (int v, int p = -1)
{
  used[v] = 1;
  d[v] = up[v] = ti++;
  for (int i = 0; i < graph[v].size(); i++)
  {
    int to = graph[v][i];
    if (to == p)  continue;
    if (used[to])
      up[v] = min (up[v], d[to]);
    else
    {
      dfs (to, v);
      up[v] = min (up[v], up[to]);
      if (up[to] > d[v]) Bridges.insert(mp[Edge(v,to)]);
    }
  }
}

void FindBridges(void)
{
  ti = 1;
  for(int i = 1; i <= n; i++)
    if (!used[i]) dfs(i);
}

int main(void)
{
  //freopen("1943.in","r",stdin);
  scanf("%d %d",&n,&m);
  graph.resize(n+1); used.resize(n+1);
  d.resize(n+1); up.resize(n+1);
  for(i = 1; i <= m; i++)
  {
    scanf("%d %d",&a,&b);
    graph[a].push_back(b); graph[b].push_back(a);
    mp[Edge(a,b)] = i;
  }
  
  FindBridges();

  printf("%d\n",Bridges.size());
  for(iter = Bridges.begin(); iter != Bridges.end(); iter++)
    printf("%d ",*iter);
  printf("\n");
  return 0;
}
