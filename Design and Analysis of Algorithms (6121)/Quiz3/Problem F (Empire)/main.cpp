//
//  main.cpp
//  Problem F (Empire)
//
//  Created by Ilyas Karimov on 03.01.21.
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
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
