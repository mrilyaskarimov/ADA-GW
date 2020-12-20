//
//  main.cpp
//  Problem O (Bicoloring)
//
//  Created by Ilyas Karimov on 11.12.20.
//

#include <stdio.h>
#include <string.h>

int g[1001][1001];
int used[1001];
int Error;

int n;
void dfs(int v, int color){
    if (Error) return;
    used[v] = color;
    for (int i=1;i<=n;i++){
        if(g[v][i]==1){
            if(used[i]==0) dfs (i,3-color);
            else if (used[v]==used[i]) Error =1;
        }
    }
}
int main(void){
    int l,a,b;
    while(scanf("%d",&n),n){
        scanf("%d",&l);
        memset(g,0,sizeof(g));
        memset(used,0,sizeof(used));
    
    for(int i = 0; i < l; i++)
    {
        scanf("%d %d",&a,&b);
        g[a][b] = g[b][a] = 1;
    }
    Error = 0; dfs(1,1);
    
    if (Error) printf("NOT BICOLOURABLE.\n");
    else printf("BICOLOURABLE.\n");
    }
}
