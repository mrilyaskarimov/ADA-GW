//
//  main.cpp
//  Mathematical platforms (Problem E)
//
//  Created by Ilyas Karimov on 19.11.20.
//

#include <stdio.h>
#include <string.h>
#define MAX 4001
#define INF 0x3F3F3F3F3F3F

long long i, j, min, n, m,  s, v, a, b;
long long g[MAX][MAX], used[MAX], dist[MAX], Y[MAX];

// Relaxation of the edge i -> j
void Relax(long long i, long long j)
{
  if (dist[i] + g[i][j] < dist[j])    dist[j] = dist[i] + g[i][j];
}

int main(int argc, const char * argv[]) {
    memset(g, 0x3F, sizeof(g));
    memset(used, 0, sizeof(used));
    memset(dist, 0x3F, sizeof(dist));
    
    scanf("%lld", &n);
    for(i = 1; i<=n; i++) scanf("%lld",&Y[i]);
    
    for(i = 1; i<=n;i++){
        for(j = 1; j <= n; j++){
            g[i][j] = (i-j)*(i-j)*(Y[i]-Y[j])*(Y[i]-Y[j]);
        }
    }
    dist[1] = 0;

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

    if (dist[n] == INF) printf("-1\n");
    else printf("%lld\n", dist[n]);
    return 0;
}
