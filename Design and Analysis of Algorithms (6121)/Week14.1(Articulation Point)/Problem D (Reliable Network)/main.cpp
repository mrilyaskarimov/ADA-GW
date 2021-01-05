//
//  main.cpp
//  Problem D (Reliable Network)
//
//  Created by Ilyas Karimov on 21.12.20.
//
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

#define INF 0x3F3F3F3F
#define MaxV 30
int g[MaxV][MaxV];
int used[MaxV], d[MaxV], up[MaxV];
int best[1<<20];
using namespace std;
int i, n, m, a, b, ti, IsBridge, TotLen, res, cs=1;

struct Edge {
      int u, v, dist;
    } E[21];
void dfs (int v, int p = -1){
    if (IsBridge) return;
    used[v] = 1;
    d[v] = up[v] = ti++;
    for (int to = 1; to <= n; to++){
        if ((to == p) || !g[v][to]) continue;
        if (used[to])
          up[v] = min (up[v], d[to]);
        else{
          dfs (to, v);
          up[v] = min (up[v], up[to]);
          if (up[to] > d[v]) IsBridge = 1;
        }
    }
}
int IsBiconnected(void){
    ti = 1; IsBridge = 0;
    memset(used,0,sizeof(used));
    memset(d,0,sizeof(d));
    memset(up,0,sizeof(used));
    for(int i = 1; i <= n; i++){
        if (!used[i]) dfs(i);
        if (IsBridge) break;
    }
    return !IsBridge;
}
int go(int mask, int CurLen){
    int i, opt;
    if(best[mask] != INF) return best[mask];
    if (!IsBiconnected()) return best[mask] = INF - 1; best[mask] = CurLen;
    for(i = 0; i < m; i++){
        if (mask & (1 << i)){
            g[E[i].u][E[i].v] = g[E[i].v][E[i].u] = 0;
            opt = go(mask ^ (1 << i), CurLen - E[i].dist);
            if (opt < best[mask]) best[mask] = opt;
            g[E[i].u][E[i].v] = g[E[i].v][E[i].u] = 1;
        }
    }
    return best[mask];
}

int main(void){
    while(scanf("%d %d",&n,&m), n + m){
        memset(best,0x3F,sizeof(best));
        memset(g,0,sizeof(g));
        res = INF;
        TotLen = 0;
        for(i = 0; i < m; i++){
                scanf("%d %d %d",&E[i].u ,&E[i].v,&E[i].dist); g[E[i].u][E[i].v] = g[E[i].v][E[i].u] = E[i].dist; TotLen += E[i].dist;
        }
        res = go((1 << m) - 1, TotLen);
        if (res >= INF - 1)
        printf("There is no reliable net possible for test case %d.\n",cs++);
        else printf("The minimal cost for test case %d is %d.\n",cs++, res);
      }
}
