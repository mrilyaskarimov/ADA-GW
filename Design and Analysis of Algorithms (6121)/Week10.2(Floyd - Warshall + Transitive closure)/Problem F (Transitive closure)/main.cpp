//
//  main.cpp
//  Problem F (Transitive closure)
//
//  Created by Ilyas Karimov on 20.11.20.
//

#include <iostream>
#define MAX 101
bool g[MAX][MAX];
int n, i, j, k, a,b;
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    while (scanf("%d %d", &a, &b) == 2) g[a][b] = true;

    for (k = 1; k <= n; k++)
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    if (g[i][k] && g[k][j]) g[i][j] = true;
    
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++) printf("%d ", g[i][j]);
    printf("\n");
    }
}
