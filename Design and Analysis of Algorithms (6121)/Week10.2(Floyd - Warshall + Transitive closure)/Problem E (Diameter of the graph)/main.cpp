//
//  main.cpp
//  Problem E (Diameter of the graph)
//
//  Created by Ilyas Karimov on 04.12.20.
//

#include <stdio.h>
#include <string.h>
#define MAX 101
#define INF 1000000000
int n, a, b, i, j, d= -10, r = INF, max;
int g[MAX][MAX];

using namespace std;
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
        max  = 0;
        for (j = 1; j <= n; j++){
            if((g[i][j]>max)) max = g[i][j];
        }
        if(max > d) d = max;
        if(max < r) r = max;
    }
    printf("%d\n", d);
    printf("%d\n", r);
  return 0;
}
