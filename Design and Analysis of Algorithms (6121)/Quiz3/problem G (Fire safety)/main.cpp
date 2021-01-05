//
//  main.cpp
//  problem G (Fire safety)
//
//  Created by Ilyas Karimov on 01.01.21.
//

#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

vector<vector<int> > g, gr;
vector<int> used, top, color, ag;
set<pair<int,int> > s;
int n, m, a, b, i, j, c, v, to, flag;
void dfs1(int v){
      used[v] = 1;
      for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if (!used[to]) dfs1(to);
      }
      top.push_back(v);
}

void dfs2(int v, int c){
      color[v] = c;
      ag[c] = v;
      for(int i = 0; i < gr[v].size(); i++){
        int to = gr[v][i];
        if (color[to] == -1) dfs2(to,c);
      }
}

int main(int argc, const char * argv[]){
    scanf("%d", &n);
    scanf("%d", &m);
    g.assign(n + 1, vector<int>());
    gr.assign(n + 1, vector<int>());
    for(i = 0; i<m; i++){
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    
    used.assign(n + 1, 0);
    for (i = 1; i <= n; i++)
    if (!used[i]) dfs1(i);
    
    color.assign(n + 1, -1);
    ag.assign(n + 1, -1);

    c = 0;
    for (i = 1; i <= n; i++)
    {
     v = top[n - i];
     if (color[v] == -1) dfs2(v, c++);
    }
    
    used.assign(c, 1);
    for (i = 1; i < g.size(); i++){
        for (j = 0; j < g[i].size(); j++){
            to = g[i][j];
            if (color[i] != color[to]) used[color[i]] = 0;
         }
    }
    c = flag = 0;
    for (i = 0; i < used.size(); i++)
    if (used[i]) c++;

    printf("%d\n", c);
    for (i = used.size() - 1; i >=0; i--)
    {
        if (used[i]){
            if(flag) printf(" ");
            printf("%d", ag[i]);
            flag = 1;
        }
    }
}
