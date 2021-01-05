//
//  main.cpp
//  Problem H (Magnetic Cushions)
//
//  Created by Ilyas Karimov on 01.01.21.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define MAX 100001*2

using namespace std;

vector<int> graph[MAX];
int i, n, m, a, b, c, tm, flag;
int ArtPoints[MAX], up[MAX], used[MAX], d[MAX];

using namespace std;
void dfs (int v, int p = -1){
    int i, to, children;
    used[v] = 1;
    d[v] = up[v] = tm++;
    children = 0;
    for (i = 0; i < graph[v].size(); i++){
        to = graph[v][i];
        if (to == p)  continue;
        if (used[to])
            up[v] = min (up[v], d[to]);
        else
        {
            dfs (to, v);
            up[v] = min (up[v], up[to]);
            if ((up[to] >= d[v]) && (p != -1)) ArtPoints[v] = 1;
            children++;
        }
    }
  if ((p == -1) && (children > 1)) ArtPoints[v] = 1;
}
int main(int argc, const char * argv[]) {
  
    scanf("%d %d", &n, &m);
    memset(used, 0, sizeof(used)); memset(d, 0, sizeof(d));
    memset(up, 0, sizeof(up)); memset(ArtPoints, 0, sizeof(ArtPoints));

    for(i = 1; i <= m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        graph[n+i].push_back(a); graph[a].push_back(n+i);
        graph[n+i].push_back(b); graph[b].push_back(n+i);
        graph[n+i].push_back(c); graph[c].push_back(n+i);
    }
    tm = 1;
    for(i = 1; i <= n; i++)
      if (!used[i]) dfs(i);

    int cnt = flag = 0;
    for(i = n + 1; i<= n + m; i++)
    if(ArtPoints[i]) cnt++;
    
    printf("%d\n",cnt);
    if(cnt){
        for(i = n+1; i<= n+m; i++)
        if(ArtPoints[i]){
            if (flag) printf(" ");
            printf("%d", i-n);
            flag = 1;
        }
        puts("");
    }
    
}
