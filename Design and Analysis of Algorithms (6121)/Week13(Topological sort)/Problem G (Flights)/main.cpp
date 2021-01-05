//
//  main.cpp
//  Problem G (Flights)
//
//  Created by Ilyas Karimov on 21.12.20.
//

#include <iostream>

#define MAX 1010
using namespace std;
int graph[MAX][MAX], g[MAX][MAX];
int used[MAX];
int n, L, R, Mid, i, j, flag; 
void dfs(int v, int type){
      used[v] = 1;
      for(int i = 0; i < n; i++)
if ((type ? g[i][v] : g[v][i]) && !used[i]) dfs(i,type); }

int AllVisited(void){
  for(int i = 0; i < n; i++)
    if (!used[i]) return 0;
    return 1;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
        scanf("%d",&graph[i][j]);
    L = 0; R = 2000000000;
    while(L < R){
        Mid = (L + R) / 2;
        for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            g[i][j] = (graph[i][j] <= Mid);
        
        memset(used,0,sizeof(used));
        
        dfs(0,0); flag = 0;
        
        if (AllVisited()){
            memset(used,0,sizeof(used));
            dfs(0,1);
            if (!AllVisited()) flag = 1;
        } else flag = 1;
        if (!flag) R = Mid; else L = Mid + 1;
    }
    printf("%d\n",L);
}
