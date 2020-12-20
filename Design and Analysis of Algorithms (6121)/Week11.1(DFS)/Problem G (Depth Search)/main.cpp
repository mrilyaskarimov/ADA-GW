//
//  main.cpp
//  Problem G (Depth Search)
//
//  Created by Ilyas Karimov on 11.12.20.
//

#include <stdio.h>
#include <string.h>
#define MAX 101

int g[MAX][MAX], used[MAX];
int n, s,  c = 0, i, j, g;

void dfs(int v)
{
    used[v] = 1;
    c++;
    for (int i = 1; i <= n; i++)
        if ((g[v][i] == 1) && (used[i] == 0))
            dfs(i);
}

int main(void)
{
    scanf("%d %d\n", &n, &s);
    memset(g, 0, sizeof(g));
    memset(used, 0, sizeof(used));
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            scanf("%d", &g);
            g[i][j] = g;
        }
    }
    dfs(s);
    printf("%d\n", c);
}
