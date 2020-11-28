//
//  main.cpp
//  Problem C (Super palindromes)
//
//  Created by Ilyas Karimov on 24.11.20.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX 1010
using namespace std;
char s[MAX];
int dp[MAX][MAX], pal[MAX][MAX];

int IsPal(int i, int j){
    if (i >= j) return pal[i][j] = 1;
    if (pal[i][j] != -1) return pal[i][j];
return pal[i][j] = (s[i] == s[j]) && IsPal(i+1,j-1);
}
int f(int i, int j){
    if (i == j) return dp[i][j] = 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (IsPal(i,j)) return dp[i][j] = 1;
    for(int k = i + 1; k < j - 1; k++)
        if(IsPal(i,k) && f(k + 1,j)) return dp[i][j] = 1;
    return dp[i][j] = 0;
}
int main(int argc, const char * argv[]) {
    int n, res, i, j;
    gets(s); n = strlen(s);
    memset(dp,-1,sizeof(dp));
    memset(pal,-1,sizeof(pal));
    res = 0;
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            res += f(i,j);
    printf("%d\n",res);
    
}
