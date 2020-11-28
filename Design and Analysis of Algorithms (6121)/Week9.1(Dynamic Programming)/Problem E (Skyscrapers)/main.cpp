//
//  main.cpp
//  Problem E (Skyscrapers)
//
//  Created by Ilyas Karimov on 24.11.20.
//

#include <iostream>

#define MAX 101
int dp[MAX][MAX][MAX];

long long f(int n, int l, int r){
    if (n == 1) return (l == 1 && r == 1) ? 1 : 0;
    if ((l < 1) || (r < 1)) return 0;
    if (dp[n][l][r] != -1) return dp[n][l][r];
        dp[n][l][r] = (f(n - 1, l - 1, r) + f(n - 1, l, r - 1) + (n - 2)*f(n- 1, l, r)) % 1000000007;
    return dp[n][l][r];
}

int main(int argc, const char * argv[]) {
    int n, l, r, res;
    while (scanf("%d %d %d", &n, &l, &r) == 3){
        memset(dp, -1, sizeof(dp));
        res = f(n, l, r);
        printf("%d\n", res);
    }
}
