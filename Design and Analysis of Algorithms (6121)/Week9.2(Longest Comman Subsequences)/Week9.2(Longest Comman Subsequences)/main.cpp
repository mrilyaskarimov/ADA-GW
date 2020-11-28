#include <stdio.h>
#include <string.h>
#include <vector>
#define SIZE 1002

using namespace std;
int arr1[SIZE], arr2[SIZE], arr3[SIZE], dp[SIZE][SIZE];
int n, m,l,  i, j, k;
vector<int>v;
int max(int i,int j)
{
  return (i > j) ? i : j;
}

int main(void)
{

    scanf("%d",&n);
    for(i = 1; i <= n; i++) scanf("%d",&arr1[i]);
    scanf("%d",&m);
    for(i = 1; i <= m; i++) scanf("%d",&arr2[i]);

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
    if (arr1[i] == arr2[j])  dp[i][j] = dp[i - 1][j - 1] + 1;
    else  dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

  i = n; j = m;
  while (i >= 1 && j >= 1)
    if (arr1[i] == arr2[j])
    {
        v.push_back(arr1[i]);
        i--; j--;
    }
    else
    {
        if (dp[i - 1][j] > dp[i][j - 1])  i--;
        else  j--;
    }

//  reverse(res.begin(), res.end());
//    cout << res << endl;
//    cout << dp[n%2][m];
    for(i = 0; i< v.size(); i++){
        printf("%d ", v[i]);
    }
  return 0;
}
