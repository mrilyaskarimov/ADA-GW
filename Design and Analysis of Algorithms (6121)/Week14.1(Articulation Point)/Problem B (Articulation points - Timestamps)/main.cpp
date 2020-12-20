//
//  main.cpp
//  Problem B (Articulation points - Timestamps)
//
//  Created by Ilyas Karimov on 16.12.20.
//


#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define MAX 110
using namespace std;

int i, n, m, a, b, v, tm;
int g[MAX][MAX], used[MAX], d[MAX], up[MAX];

void dfs (int v, int p = -1)
{
    used[v] = 1;
    d[v] = up[v] = tm++;
    for (int i = 1; i <= n; i++){
        if (g[v][i] == 0)  continue;
        if (i == p) continue;
        if (used[i])
            up[v] = min(up[v], d[i]);
        else{
          dfs (i, v);
          up[v] = min(up[v], up[i]);
        }
    }
}

int main(void)
{
  scanf("%d %d",&n,&m);

  for(i = 0; i < m; i++)
  {
      scanf("%d %d", &a, &b);
      g[a][b] = g[b][a] = 1;
  }

    scanf("%d", &v);
    
    tm = 1;
    dfs(v);

    for(int i = 1; i<=n; i++)
    printf("%d %d\n", d[i], up[i]);
  return 0;
}
