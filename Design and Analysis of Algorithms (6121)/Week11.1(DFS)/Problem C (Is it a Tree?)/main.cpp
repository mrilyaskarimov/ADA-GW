//
//  main.cpp
//  Problem C (Is it a Tree?)
//
//  Created by Ilyas Karimov on 08.12.20.
//

#include <iostream>
#define MAX 101
using namespace std;
int g[MAX][MAX], used[MAX];
int n, cnt = 0, sum = 0;

void dfs(int v){
    used[v] = 1;
    for(int i = 1; i<=n; i++){
        if(g[v][i]&& !used[i]){
            cnt++;
            dfs(i);
        }
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    memset(g, 0, sizeof(g));
    memset(used, 0, sizeof(used));
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            scanf("%d",&g[i][j]);
            sum+= g[i][j];
            if((i==j) && (g[i][j]==1)){
                puts("NO");
                return 0;
               }
        }
    }
    dfs(1);
    if(( sum/2 +1==n)&&(cnt==n-1))  puts("YES");
    else puts("NO");
}
//



