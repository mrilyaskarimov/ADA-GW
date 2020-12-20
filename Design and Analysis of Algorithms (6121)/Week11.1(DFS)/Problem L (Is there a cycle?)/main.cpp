//
//  main.cpp
//  Problem L (Is there a cycle?)
//
//  Created by Ilyas Karimov on 11.12.20.
//
//

#include <iostream>
#define MAX 51
int g[MAX][MAX], used[MAX];
int n, i, j, flag;
using namespace std;

void dfs(int v){
    used[v] = 1;
    for (int i = 1; i <= n; i++)
      if (g[v][i]){
          if (used[i] == 1) flag = 1;
          else if (used[i] == 0) dfs(i);
      }
    used[v] = 2;
}

int main(void){
    scanf("%d", &n);
        for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
          scanf("%d", &g[i][j]);
    
    flag = 0;
    for (i = 1; i <= n; i++)
        if (used[i] == 0) dfs(i);
    printf("%d", flag);
}
