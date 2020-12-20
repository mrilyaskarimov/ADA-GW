//
//  main.cpp
//  Problem J (Depth first search on a disconnected graph)
//
//  Created by Ilyas Karimov on 11.12.20.
//

#include <iostream>
#include <vector>
#define MAX 101
using namespace std;
int g[MAX][MAX], used[MAX], d[MAX], f[MAX];
int t = 1,c , n, m, a, b, s, i, j, res = 0;
vector<int>arr;
void dfs(int v){
    d[v] = t++;
    used[v] = 1;
//    printf("%d ", v);
    arr.push_back(v);
    for (int c = 1; c <= n; c++)
        if ((g[v][c] == 1) && (used[c] == 0))
            dfs(c);
    f[v] = t++;
}
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    memset(g, 0, sizeof(g));
    memset(used, 0, sizeof(used));
    while(scanf("%d %d", &a, &b)==2) g[a][b] = g[b][a] = 1;
    
//    for(i = 1; i <=n; i++){
//        for(j = 1; j <=n;j++){
//            printf("%d ", g[i][j]);
//        }
//        puts("");
//    }
    for(i = 1; i <= n; i++)
        if (!used[i])
        {
          dfs(i);
          res++;
        }
    for(i = 1; i<=n ; i++){
        printf("Vertex: %d, Gray %d, Black %d \n",arr[i-1], d[arr[i-1]], f[arr[i-1]]);
    }
}


