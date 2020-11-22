//
//  main.cpp
//  Problem G (Transivity of a graph)
//
//  Created by Ilyas Karimov on 20.11.20.
//

#include <iostream>
#define MAX 101
bool g[MAX][MAX], flag = true;
int n,m, i, j, k, a,b;

//if there exists a path from i to k, and k to j, then check the edge
int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    
    for (int i=0; i<m;i++){
        scanf("%d %d", &a, &b);
        g[a][b] = g[b][a] = true;
        
    }
    for (k = 1; k <= n; k++)
        for (i = k+1; i <= n; i++)
            for (j = i+1; j <= n; j++){
                if(k==i || i == j) continue;
                if(g[i][k] && g[k][j] ) flag &= g[i][j];
            }
                
    if(flag) puts("YES");
    else puts("NO");
}
