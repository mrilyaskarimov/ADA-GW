#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int> > g;
vector<int> used;
int i, n, a, b;
void dfs(int v){
// We switch on the lamp in the room (in the vertex v of the graph)
    used[v] = 1;
// print the vertex v
    printf("%d ", v);
// looking for a tunnel, through which you can get to the room that is not
// visited
// g[v] contains list of vertices adjacent to v:
// g[v] = (to1, to2,..., tok) = (g[v][0], g[v][1],…, g[v][k]),k = g[v].size()
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
// We have an edge (v, to). If to is not visited, go there
        if (used[to] == 0) dfs(to);
    }
}
int main(void){
// vertices are numbered from 1 to n, initialize arrays
    int n, m, v;
    scanf("%d %d", &n, &m);
    g.resize(n + 1);
    used.resize(n + 1);
    // read the graph
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    scanf("%d", &v);
    // run dfs from the vertex 1
    dfs(v);
    printf("\n");
    return 0;
}
