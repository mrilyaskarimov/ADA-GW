#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#define INF 0x3F3F3F3F
#define MAX 10010
using namespace std;
 
int b, e, w, v, j, i, tests;
int n, m, start, fin;
vector<int> dist, distR;
set<int> avoid[MAX];
set<int>::iterator it;
 
struct edge
{
  int node, dist;
  edge(int node, int dist) : node(node), dist(dist) {}
};
 
bool operator< (edge a, edge b)
{
  return a.dist > b.dist;
}
 
void Dijkstra(vector<vector<edge> > &g, vector<int> &d, int start)
{
  priority_queue<edge> pq;
  pq.push(edge(start,0));
  d = vector<int>(n + 1,INF);
  d[start] = 0;
  
  while(!pq.empty())
  {
    edge e = pq.top(); pq.pop();
    int v = e.node;
    if (e.dist > d[v]) continue;
    for(int j = 0; j < g[v].size(); j++)
    {
      int flag = 0;
      int to = g[v][j].node;
      int cost = g[v][j].dist;
      for (it = avoid[v].begin(); it != avoid[v].end(); it++)
      {
        if (to == *it) flag = 1;
      }
      if (d[v] + cost < d[to] && flag == 0)
      {
        d[to] = d[v] + cost;
        pq.push(edge(to,d[to]));
      }
    }
  }
}


int main(void)
{
  while (true)
  {
    vector<vector<edge> > g;
    vector<vector<edge> > R;
    
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0) break;
    
    scanf("%d %d", &start, &fin);
    
    g.resize(n + 1);
    R.resize(n + 1);

    for(i = 0; i < m; i++)
    {
      scanf("%d %d %d",&b, &e, &w);
      g[b].push_back(edge(e,w));
      R[e].push_back(edge(b,w));
    }

    Dijkstra(g, dist, start);
    Dijkstra(R, distR, fin);

    for (i = 0; i < n; i++)
    {
      vector<edge> e = g[i];
      for (j = 0; j < e.size(); j++)
      {
        if ((dist[i] + e[j].dist + distR[e[j].node]) == dist[fin])
        {
          avoid[i].insert(e[j].node);
        }
      }
    }

    Dijkstra(g, dist, start);

    if (dist[fin] == INF) printf("-1\n");
    else printf("%d\n",dist[fin]);

    for (i = 0; i < n - 1; i++) avoid[i].clear();
  }

  return 0;
}
