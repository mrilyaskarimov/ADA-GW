//
//  main.cpp
//  Problem I (Depth First Search - Timestamps)
//
//  Created by Ilyas Karimov on 11.12.20.
//

#include <iostream>
#define MAX 101
int g[MAX][MAX], used[MAX], d[MAX], f[MAX];
int t = 1,c , n, m, a, b, s, i, j;

void dfs(int v){
    d[v] = t++;
    used[v] = 1;
    for (int c = 1; c <= n; c++)
        if ((g[v][c] == 1) && (used[c] == 0))
            dfs(c);
    f[v] = t++;
}
int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    memset(g, 0, sizeof(g));
    memset(used, 0, sizeof(used));
    for(i = 1; i <=m; i++){
        scanf("%d %d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }
//    for(i = 1; i <=n; i++){
//        for(j = 1; j <=n;j++){
//            printf("%d ", g[i][j]);
//        }
//        puts("");
//    }
    scanf("%d", &s);
    dfs(s);
    for(i = 1; i<=n ; i++){
        printf("%d %d\n", d[i], f[i]);
    }
}


