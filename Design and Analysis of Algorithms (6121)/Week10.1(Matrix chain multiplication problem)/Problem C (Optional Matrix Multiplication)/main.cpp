//
//  main.cpp
//  Problem D (Optimal Matrix Multiplication)
//
//  Created by Ilyas Karimov on 29.11.20.
//

#include <iostream>
#define INF 0x3F3F3F3F3F3F3F3FLL
#define MAX 11
long long dp[MAX][MAX], p[MAX];

long long Mult(int i, int j)
{
  if (dp[i][j] == INF)
    for (int k = i; k < j; k++)
    {
      long long temp = Mult(i, k) + Mult(k + 1, j) + p[i - 1] * p[k] * p[j];
      if (temp < dp[i][j]) dp[i][j] = temp;
  }
  return dp[i][j];
}

int main(){
    
    int n;
    scanf("%d", &n);
    memset(dp,0x3F,sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
      scanf("%lld %lld",&p[i-1],&p[i]);
      dp[i][i] = 0;
    }
    printf("%lld", Mult(1, n));
    return 0;
    
}
