//
//  main.cpp
//  Problem C (Strong Connectivity)
//
//  Created by Ilyas Karimov on 21.12.20.
//

#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > g, gr;
vector<int> used, top;
int i, j, n, m, a, b, v, c;

void dfs1(int v)
{
  used[v] = 1;
  for(int i = 0; i < g[v].size(); i++)
  {
    int to = g[v][i];
    if (!used[to]) dfs1(to);
  }
  top.push_back(v);
}

void dfs2(int v)
{
  used[v] = 1;
  for(int i = 0; i < gr[v].size(); i++)
  {
    int to = gr[v][i];
    if (!used[to]) dfs2(to);
  }
}

int main(void)
{
  //freopen("2403.in","r",stdin);
  scanf("%d %d",&n,&m);
  g.assign(n+1,vector<int>());
  gr.assign(n+1,vector<int>());
  for(i = 1; i <= m; i++)
  {
    scanf("%d %d",&a,&b);
    g[a].push_back(b);
    gr[b].push_back(a);
  }

  used.assign(n+1,0);
  for(i = 1; i <= n; i++)
    if (!used[i]) dfs1(i);

  used.assign(n+1,0);
  c = 0;
  for(i = n - 1; i >= 0; i--)
  {
    v = top[i];
    if (!used[v])
    {
      dfs2(v);
      c++;
    }
  }

  printf("%d\n",c);
  return 0;
}
