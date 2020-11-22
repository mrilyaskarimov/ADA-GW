
#include <cstring>
#include <vector>
#include <queue>
#define INF 0x3F3F3F
using namespace std;
int parent[5001], path[5001], ptr;
int b, e, w, v, i;
int n, m, start, fin;
vector<int> dist;
struct edge
{
    int node, dist;
    edge(int node, int dist) : node(node), dist(dist) {}
};
bool operator< (edge a, edge b)
{
    return a.dist > b.dist;
}
vector<vector<edge>> g;
void Dijkstra(vector<vector<edge>> &g, vector<int> &d, int start)
{
    priority_queue<edge> pq;
    pq.push(edge(start, 0));
    d = vector<int>(n + 1, INF);
    d[start] = 0;
    while(!pq.empty())
    {
        edge e = pq.top();
        pq.pop();
        int v = e.node;
        if (e.dist > d[v]) continue;
        for(int j = 0; j < g[v].size(); j++)
        {
            int to = g[v][j].node;
            int cost = g[v][j].dist;
            if (d[v] + cost < d[to])
            {
                d[to] = d[v] + cost;
                parent[to] = v;
                pq.push(edge(to, d[to]));
            }
        }
    }
}
int main(void)
{
    memset(parent, -1, sizeof(parent));
    scanf("%d %d %d %d", &n, &m, &start, &fin);
    g.resize(n + 1);
    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d", &b, &e, &w);
        g[b].push_back(edge(e, w));
        g[e].push_back(edge(b, w));
    }
    Dijkstra(g, dist, start);
    if (dist[fin] == INF) printf("-1");
    else
    {
        printf("%d\n", dist[fin]);
        ptr = 0;
        while (fin != start)
        {
            path[ptr++] = fin;
            fin = parent[fin];
        }
        path[ptr] = start;
        for(i = ptr; i >= 0; i--)
        {
            printf("%d ", path[i]);
        }
    }
}
