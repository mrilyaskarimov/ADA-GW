//
//  main.cpp
//  Problem D (Palindromes)
//
//  Created by Ilyas Karimov on 24.11.20.
//

#include <stdio.h>
#include <string.h>
#define MAX 61

char s[MAX];
long long dp[MAX][MAX];
int i, j, len, n;
long long f(int i, int j)
{
    if (i > j) return 0;
    if (i == j) return dp[i][j] = 1;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j])
        dp[i][j] = f(i + 1, j) + f(i, j - 1) + 1;
    else
        dp[i][j] = f(i + 1, j) + f(i, j - 1) - f(i + 1, j - 1);
    return dp[i][j];
}
    
int main(int argc, const char * argv[]) {
    gets(s); n = strlen(s);
    memset(dp, -1, sizeof(dp));

    printf("%lld\n", f(0, n - 1));
    return 0;
}
