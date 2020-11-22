//
//  main.cpp
//  Problem B (Floyd)
//
//  Created by Ilyas Karimov on 20.11.20.
//

#include <stdio.h>
#include <string.h>
#define MAX 101
#define INF 1000000000
int n, a, b, i, j, dist, max=-1;
int g[MAX][MAX];

void floyd(void)
{
  for (int k = 1; k <= n; k++)
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++)
    if (g[i][k] + g[k][j] < g[i][j]) g[i][j] = g[i][k] + g[k][j];
}

int main(void)
{
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++){
    scanf("%d", &g[i][j]);
    if(g[i][j]==-1) g[i][j] = INF;
    }
  floyd();

  for (i = 1; i <= n; i++){
      for (j = 1; j <= n; j++){
          if((g[i][j]>max) && (g[i][j] < INF)) max = g[i][j];
      }
  }
    printf("%d", max);
  return 0;
}
