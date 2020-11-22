//
//  main.cpp
//  Distance betweeen the vertices (Problem F)
//
//  Created by Ilyas Karimov on 19.11.20.
//

#include <cstdio>
#include <vector>
#include <queue>
#define INF 0x3F3F3F3F
#define MAX 100001
using namespace std;

int b, e, w, v, j, i, tests;
int n, m, start, fin, parent[MAX], path[MAX], ptr;;

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

vector<vector<edge> > g;

void Dijkstra(vector<vector<edge> > &g, vector<int> &d, int start)
{
  priority_queue<edge> pq;
  pq.push(edge(start,0));

  d = vector<int>(n+1,INF);
  d[start] = 0;

  while(!pq.empty())
  {
    edge e = pq.top(); pq.pop();
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
          pq.push(edge(to,d[to]));
      }
    }
  }
}

int main(void)
{
  //freopen("2965.in","r",stdin);
    scanf("%d %d %d %d",&n,&m,&start,&fin);
    g.resize(n+1);
    for(i = 0; i < m; i++){
      scanf("%d %d %d",&b,&e,&w);
      g[b].push_back(edge(e,w));
      g[e].push_back(edge(b,w));
    }

      Dijkstra(g,dist,start);

      if (dist[fin] == INF)
          printf("-1\n");
      else{
          printf("%d\n",dist[fin]);
          ptr = 0;
          while(fin != start){
              path[ptr++] = fin;
              fin = parent[fin];
          }
          path[ptr] = start;
          
          for(int i= ptr ; i>= 0; i--){
              printf("%d ", path[i]);
          }
      }
  return 0;
}
