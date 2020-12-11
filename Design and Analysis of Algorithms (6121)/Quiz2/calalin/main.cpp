#include <stdio.h>
#include <string.h>
#define MAX 2010
#define INF 0x3F3F3F3F

int i, j, min, n, m, s, f,ff;
int u, v, len, w, mx;
int g[MAX][MAX],gR[MAX][MAX], used[MAX], usedR[MAX], dist[MAX],distR[MAX], parent[MAX],parentR[MAX];
int path[MAX], ptr;


int main(void)
{
//  freopen("in.txt", "r", stdin);
  while(scanf("%d %d", &n, &m)){
  if(n==0) return 0;
  
  
  scanf("%d %d", &s, &f);
  ff=f;
  memset(g, 0x3F, sizeof(g));
  memset(used, 0, sizeof(used));
  memset(gR, 0x3F, sizeof(gR));
  memset(usedR, 0, sizeof(usedR));

  for (i = 1; i <= m; i++)
  {
    scanf("%d %d %d", &u, &v, &len);
    g[u][v] = gR[v][u] = len;
  }

  memset(dist, 0x3F, sizeof(dist));
  memset(distR, 0x3F, sizeof(distR));

  dist[s] = 0;
  distR[f] = 0;

  memset(parent, -1, sizeof(parent));
  memset(parent, -1, sizeof(parentR));

  for (i = 0; i < n; i++)
  {
    min = INF;
    w = -1;
    for (j = 0; j < n; j++)
      if (!used[j] && dist[j] < min) { min = dist[j]; w = j; }

    if (w == -1) break;

    for (j = 0; j < n; j++)
      if (!used[j] && dist[w] + g[w][j] < dist[j])
      {
        dist[j] = dist[w] + g[w][j];
        parent[j] = w;
      }

    used[w] = 1;
  }

  for (i = 0; i < n; i++)
  {
    min = INF;
    w = -1;
    for (j = 0; j < n; j++)
      if (!usedR[j] && distR[j] < min) { min = distR[j]; w = j; }

    if (w == -1) break;

    for (j = 0; j < n; j++)
      if (!usedR[j] && distR[w] + gR[w][j] < distR[j])
      {
        distR[j] = distR[w] + gR[w][j];
        parentR[j] = w;
      }

    usedR[w] = 1;
  }
  
  for (i=0;i<n;i++){
//      printf("%d %d %d\n",i,dist[i],distR[i]);
      if(g[s][i]+distR[i]==dist[f]){
            g[s][i]=INF;
      }

  }

  
  memset(used, 0, sizeof(used));
  memset(dist, 0x3F, sizeof(dist));
  memset(parent, -1, sizeof(parent));
  dist[s] = 0;
  f=ff;

    for (i = 0; i < n; i++)
  {
    min = INF;
    w = -1;
    for (j = 0; j < n; j++)
      if (!used[j] && dist[j] < min) { min = dist[j]; w = j; }

    if (w == -1) break;

    for (j = 0; j < n; j++)
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
  }

}  return 0;

}
