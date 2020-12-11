//
//  main.cpp
//  Problem B (Get a tree)
//
//  Created by Ilyas Karimov on 25.11.20.
//

#include <iostream>
using namespace std;
int c = 0, n, m, v, a, b;
int g[101][101], used[101];
void dfs(int v){
    used[v] = 1;
    for (int i = 1; i <= n; i++){
        if ((g[v][i] == 1) && (used[i] == 0)){
            printf("%d %d\n", v, i);
            dfs(i);
        }
    }
        
}
int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
        memset(g,0,sizeof(g));
        memset(used,0,sizeof(used));
        for(int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            g[a][b]=g[b][a] =1;
        }
//        for(int i=0;i<n;i++){
//            for(int j = 0; j<n;j++){
//                printf("%d ",g[i][j]);
//            }
//            puts("");
//        }
        dfs(1);
}
