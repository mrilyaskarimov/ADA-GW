//
//  main.cpp
//  Problem D (Kastenlauf)
//
//  Created by Ilyas Karimov on 08.12.20.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 101
using namespace std;
int x[MAX], y[MAX], g[MAX][MAX], used[MAX];
int i, n, j, res , cnt = 0 , tc;

void dfs(int v){
    used[v] = 1;
    for(int i = 1; i<=n; i++){
        if(g[v][i]&& !used[i]){
            dfs(i);
        }
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d", &tc);
    // 0 = Jo's house, start
    // 1 .. n - stores selling beer
    // n+1 - Bergkirchweih, finish
    while(tc--){
        memset(g, 0, sizeof(g));
        memset(used, 0, sizeof(used));
        scanf("%d", &n);
        for (i = 0; i < n + 2; i++)
            scanf("%d %d", &x[i], &y[i]);

        for (i = 0; i < n + 2; i++)
        for (j = i + 1; j < n + 2; j++)
          if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= 1000)
              g[i][j] = g[j][i] = 1;
        dfs(0);
        if(used[n]) puts("happy");
        else puts("sad");
    }
}
