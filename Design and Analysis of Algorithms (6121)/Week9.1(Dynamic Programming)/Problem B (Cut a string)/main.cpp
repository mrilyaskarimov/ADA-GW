//
//  main.cpp
//  Problem B (Cut a string)
//
//  Created by Ilyas Karimov on 24.11.20.
//

#include <iostream>
#include <algorithm>
#include <string>
#define MAX 101
#define INF 0x3F3F3F3F
using namespace std;
int dp[MAX][MAX];
string s;

int f(int l, int r)
{
    if (l > r) return 0;
    if (l == r) return 1;
    if (dp[l][r] != INF) return dp[l][r];
    
    int &res = dp[l][r];
    if (s[l] == s[r])
    res = min(res, f(l + 1, r - 1));
    
    for (int i = l; i < r; i++)
    res = min(res, f(l, i) + f(i + 1, r));
    return res;
}
int main(int argc, const char * argv[]) {
    cin >> s;
    memset(dp,0x3F,sizeof(dp));
    printf("%d\n",f(0, s.size() - 1));
}

