#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 1001
using namespace std;

int n, m, i, j;
int dp[MAX][MAX];
string arr1, arr2, res;

int main()
{

  cin >> arr1; n = arr1.length(); arr1 = " " + arr1;
  cin >> arr2; m = arr2.length(); arr2 = " " + arr2;

  for (i = 1; i <= n; i++)
  for (j = 1; j <= m; j++)
    if (arr1[i] == arr2[j])  dp[i][j] = dp[i - 1][j - 1] + 1;
    else  dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

  i = n; j = m;
  while (i >= 1 && j >= 1)
    if (arr1[i] == arr2[j])
    {
      res = res + arr1[i];
      i--; j--;
    }
    else
    {
      if (dp[i - 1][j] > dp[i][j - 1])  i--;
      else  j--;
    }

  reverse(res.begin(), res.end());
    cout << res << endl;
    cout << dp[n%2][m];

  return 0;
}
