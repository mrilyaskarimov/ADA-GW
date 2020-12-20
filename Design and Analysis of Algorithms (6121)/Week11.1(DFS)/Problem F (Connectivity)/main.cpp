//
//  main.cpp
//  Problem F (Connectivity)
//
//  Created by Ilyas Karimov on 25.11.20.
//

#include <stdio.h>
#include <string.h>
#define MAX 102
int n, i, j, res, m, count = 0, g, b;
int g[MAX][MAX], used[MAX];

void dfs(int v)
{
  used[v] = 1;
  for(int i = 0; i < n; i++)
    if (g[v][i] && !used[i]) dfs(i); count++;
}

int main(void){
    scanf("%d %d",&n,&m);
       for( i = 0 ; i < m; i++){
           scanf("%d %d",&g,&b);
           g[g][b]=g[b][g] = 1;
       }
       dfs(1);
    
       if(count==n-1) printf("YES\n");
       else printf("NO\n");
    
       return 0;
}
