//
//  main.cpp
//  Distance between vertices (Problem C)
//
//  Created by Ilyas Karimov on 19.11.20.
//
#include <stdio.h>
#include <string.h>
#define MAX 2001
#define INF 0x3F3F3F3F

int i, j, min, n, m, s, t, v, a, b, c;
int g[MAX][MAX], used[MAX], dist[MAX];

// Relaxation of the edge i -> j
void Relax(int i, int j)
{
  if (dist[i] + g[i][j] < dist[j])
    dist[j] = dist[i] + g[i][j];
}

int main(void)
{
  memset(g, 0x3F, sizeof(g));
  memset(used, 0, sizeof(used));
  memset(dist, 0x3F, sizeof(dist));
  

    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &t);
    
    for(i=1;i<= m; i++){
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = c;
        g[b][a] = c;
    }
   
    dist[s] = 0;
    for (i = 1; i < n; i++)
    {
      // find vertex w with minimum d[w] among not used vertices
      min = INF; v = -1;
      for (j = 1; j <= n; j++)
        if (used[j] == 0 && dist[j] < min) { min = dist[j]; v = j; }

      // no more vertices to add
      if (v < 0) break;

      // relax all edges outgoing from v
      // process edge v -> j
      for (j = 1; j <= n; j++)
        if (used[j] == 0 && g[v][j] != -1) Relax(v, j);

      // shortest distance to v is found
      used[v] = 1;
    }

    if (dist[t] == INF) printf("-1\n");
    else printf("%d\n", dist[t]);
    return 0;
}
