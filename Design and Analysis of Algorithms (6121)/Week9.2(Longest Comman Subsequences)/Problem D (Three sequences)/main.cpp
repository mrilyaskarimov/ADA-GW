#include <stdio.h>
#include <string.h>
#include <algorithm>
#define SIZE 101

using namespace std;
int x[SIZE], y[SIZE], z[SIZE],mas[2][SIZE][SIZE], dp[SIZE][SIZE][SIZE];;
int n, m, l,  i, j, k;

int main(void)
{

    scanf("%d",&n);
    for(i = 1; i <= n; i++) scanf("%d",&x[i]);
    scanf("%d",&m);
    for(i = 1; i <= m; i++) scanf("%d",&y[i]);
    scanf("%d",&l);
    for(i = 1; i <= l; i++) scanf("%d",&z[i]);
    /*
     Let a, b, c be three input sequences. Let f(i, j, k) be the length of LCS of sequences a[1..i], b[1..j] and c[1..k]. The value f(i, j, k)
     we shall keep in dp[i][j][k].
      If a[i] = b[j] = c[k], then Otherwise
     f(i, j, k) = 1 + f(i – 1, j – 1, k – 1)
     f(i, j, k) = max( f(i – 1, j, k), f(i, j – 1, k), f(i, j, k – 1) )
     */
    memset(dp,0,sizeof(dp));

    for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++)
    for(k = 1; k <= l; k++)
    if (x[i] == y[j] && y[j] ==  z[k])  dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
    else  dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
    
   
//    while (i >= 1 && j >= 1 && k>=1)
//        if (x[i] == y[j] && x[i] == z[k])
//        {
//            v.push_back(x[i]);
//            printf("%d ",x[i]);
//            i--; j--; k--;
//        }
//        else
//        {
//            if ((dp[i - 1][j][k] > dp[i][j - 1][k] ) && (dp[i - 1][j][k] > dp[i][j][k-1]))  i--;
//            if ((dp[i][j][k-1] > dp[i-1][j][k] ) && (dp[i][j][k-1] > dp[i][j-1][k])) k--;
//            else  j--;
//        }
//    for(i = 0; i< v.size(); i++){
//        printf("%d ", v[i]);
//    }
    printf("%d ", dp[n][m][l]);
//    for(i = 1; i <= n; i++){
//        for(j = 1; j <= m; j++){
//            for(k = 1; k <= l; k++){
//                printf("%d ", dp[i][j][k]);
//            }
//            printf("\n");
//        }
//        printf("\n");
//    }
  return 0;
}
