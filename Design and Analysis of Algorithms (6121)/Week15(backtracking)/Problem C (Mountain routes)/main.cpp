//
//  main.cpp
//  Problem C (Mountain routes)
//
//  Created by Ilyas Karimov on 23.12.20.
//

#include <iostream>

#define MAX 51
using namespace std;
int d, res = 0, n, k, a, b, i, a1, a2;
int g[MAX][MAX], used[MAX];
void dfs(int v, int depth){
    if (depth > d) return;
    if (v == b){
        res++;
        return;
    }
    used[v] = 1;

    for(int i = 1; i <= n; i++)
        if (g[v][i] && !used[i]) dfs(i,depth+1);
    used[v] = 0;
}


int main(int argc, const char * argv[]) {
    scanf("%d %d %d %d %d",&n,&k,&a,&b,&d);
    memset(g,0,sizeof(g));
    memset(used,0,sizeof(used));

    for(i = 0; i < k; i++)
    {
      scanf("%d %d",&a1,&a2);
      g[a1][a2] = 1;
    }
     
    res = 0;
    dfs(a,0);

    printf("%d\n",res);

}
