#include <stdio.h>
#include <string.h>
#define MAX 2001
#define INF 0x3F3F3F3F

int i, j, min, n, s, f, v;
int g[MAX][MAX], used[MAX], dist[MAX];

// Relaxation of the edge i -> j
void Relax(int i, int j)
{
  if (dist[i] + g[i][j] < dist[j])
    dist[j] = dist[i] + g[i][j];
}

int main(void)
{
  //freopen("2351.in","r",stdin);
  scanf("%d %d %d", &n, &s, &f);
    
  memset(g, 0x3F, sizeof(g));
  memset(used, 0, sizeof(used));
  memset(dist, 0x3F, sizeof(dist));
  dist[s] = 0;

  for (i = 1; i <= n; i++)
  for (j = 1; j <= n; j++)
    scanf("%d", &g[i][j]);

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

  if (dist[f] == INF) printf("-1\n");
  else printf("%d\n", dist[f]);
  return 0;
}
