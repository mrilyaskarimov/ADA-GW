//
//  main.cpp
//  Problem B (Hello, Pie!)
//
//  Created by Ilyas Karimov on 03.01.21.
//


#include <stdio.h>
#include <string.h>
#define INF 0x3F3F3F3F
#define MAX 16
int dp[1<<MAX][MAX+1];

int xx, yy, i, j;
int x[21], y[21], m[21][21];
int total, tests, nuts;
char mas[21][21];

int max(int i, int j)
{
  return (i > j) ? i : j;
}

int min(int i, int j)
{
  return (i < j) ? i : j;
}

int abs(int x)
{
  return (x > 0) ? x : -x;
}

int solve(int mask, int last)
{
  int &res = dp[mask][last];
  if(res == INF)
  {
    mask ^= (1 << last);
    for(int i = 1; i < nuts; ++i)
      if(mask & (1 << i)) res = min(res,solve(mask,i) + m[i][last]);
  }
  return res;
}

int main(void)
{
    scanf("%d", &nuts);
    for(i < 0; i<nuts+1; i++){
        for( j = 0; j<nuts+1; j++)
        scanf("%d", &m[i][j]);
    }
    nuts++;
    
    for(int k = 0; k< nuts; k++)
    for(i = 0; i < nuts; i++)
    for(j = 0; j < nuts; j++)
    if(m[i][k] + m[k][j]  < m[i][j]) m[i][j] = m[i][k] + m[k][j];
    memset(dp,0x3F,sizeof(dp));
    dp[1][0] = 0; total = INF;
    for(i = 1; i < nuts; i++) dp[1 | (1 << i)][i] = m[0][i];

    for(i = 1; i < nuts; i++)
      total = min(total, solve((1 << nuts) - 1,i) + m[i][0]);

    printf("%d\n",total);
  return 0;
}
