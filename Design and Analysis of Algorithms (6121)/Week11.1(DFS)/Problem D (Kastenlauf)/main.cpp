//
//  main.cpp
//  Problem D (Kastenlauf)
//
//  Created by Ilyas Karimov on 08.12.20.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 101
using namespace std;
int x[MAX], y[MAX], g[MAX][MAX], used[MAX];
int i, n, j, res;

void dfs(int v)
{
  // we entered the vertex v, print it
  printf("%d ", v);

  // mark vertex v visited
  used[v] = 1;

  // find an edge along which we can get into unvisited vertex i
  for (int i = 1; i <= n; i++)
    if ((g[v][i] == 1) && (used[i] == 0)) dfs(i);
}


int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    // 0 = Jo's house, start
    // 1 .. n - stores selling beer
    // n+1 - Bergkirchweih, finish
    for (i = 0; i < n + 2; i++)
        scanf("%d %d", &x[i], &y[i]);

    for (i = 0; i < n + 2; i++)
    for (j = i + 1; j < n + 2; j++)
      if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= 1000)
          g[i][j] = g[j][i] = 1;
    res = 0;
    for(i = 1; i <= n; i++)
      if (!used[i])
      {
        dfs(i);
        res++;
      }
    
}
