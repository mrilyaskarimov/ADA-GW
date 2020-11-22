#include <stdio.h>
#include <string.h>
#define MAX 2010
#define INF 0x3F3F3F3F

int i, j, min, n, m, s, f;
int b, e, len, w, mx;
int g[MAX][MAX], used[MAX], dist[MAX], parent[MAX];
int path[MAX], ptr;

int main(void)
{
  //freopen("4856.in", "r", stdin);
  scanf("%d %d", &n, &m);
  scanf("%d %d", &s, &f);

  memset(g, 0x3F, sizeof(g));
  memset(used, 0, sizeof(used));
  for (i = 1; i <= m; i++)
  {
    scanf("%d %d %d", &b, &e, &len);
    g[b][e] = g[e][b] = len;
  }

  memset(dist, 0x3F, sizeof(dist));
  dist[s] = 0;

  memset(parent, -1, sizeof(parent));

  for (i = 1; i < n; i++)
  {
    min = INF;
    w = -1;
    for (j = 1; j <= n; j++)
      if (!used[j] && dist[j] < min) { min = dist[j]; w = j; }

    if (w == -1) break;

    for (j = 1; j <= n; j++)
      if (!used[j] && dist[w] + g[w][j] < dist[j])
      {
        dist[j] = dist[w] + g[w][j];
        parent[j] = w;
      }

    used[w] = 1;
  }

  if (dist[f] == INF) printf("-1\n");
  else
  {
    printf("%d\n", dist[f]);
    ptr = 0;
    while (f != s)
    {
      path[ptr++] = f;
      f = parent[f];
    }
    path[ptr] = s;

    for(i = ptr; i >= 0; i--)
      printf("%d ",path[i]);
    printf("\n");
  }
  return 0;
}
