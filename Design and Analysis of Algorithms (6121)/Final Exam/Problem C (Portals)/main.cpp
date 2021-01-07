//
//  main.cpp
//  Problem C (Portals)
//
//  Created by Ilyas Karimov on 06.01.21.
//

#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 1001

using namespace std;
vector<vector<int> > g;
int arr[MAX], cost[MAX], used[MAX];
 int i, n, m, a, b, res, c, temp;

void dfs(int v){
    used[v] = 1;
    arr[c] = min(arr[c], cost[v]);
    for (int i = 0; i < g[v].size(); i++){
         int to = g[v][i];
         if (used[to] == 0) dfs(to);
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    g.resize(n+1);
    memset(arr, 9999999, sizeof(arr));
    memset(used, 0, sizeof(used));
    for(i = 1; i<= n; i++) scanf("%d", &cost[i]);
    for(i = 1; i<= m; i++){
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    temp = 999999;
    res = c =  0;
    for (i = 1; i <= n; i++){
        if (!used[i]){
            dfs(i);
            c++;
        }
    }
    
    for(i = 0; i<c; i++){
        if(arr[i] < temp) temp = arr[i];
        res+= arr[i];
    }
    res += temp * (c - 2);
    printf("%d\n", res);

}
