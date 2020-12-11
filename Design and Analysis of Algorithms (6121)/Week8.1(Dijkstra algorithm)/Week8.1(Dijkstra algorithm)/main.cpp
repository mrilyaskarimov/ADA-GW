#include <cstdio>
#include <vector>
#include <queue>
#define INF 0x3F3F3F3F
#define MAX 100001
using namespace std;

int b, e, w, v, j, i, tests;
int n, m, start, fin, parent[MAX], path[MAX], ptr;;

vector<int> dist;
vector<int> distR;

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
vector<vector<edge>> gR;

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
        gR[e].push_back(edge(b,w));
    }

      Dijkstra(gR,distR,fin);

      if (distR[fin] == INF)
          printf("-1\n");
      else{
          printf("%d\n",distR[fin]);
          ptr = 0;
          while(fin != start){
              path[ptr++] = fin;
              start = parent[start];
          }
          path[ptr] = fin;
          
          for(int i= ptr ; i>= 0; i--){
              printf("%d ", path[i]);
          }
          
      }
  return 0;
}





//#include <iostream>
//#include <algorithm>
//#include <vector>
//#define MAX 2001
//#define INF 0x3F3F3F3F
//using namespace std;
//
//struct edge
//{
//  int node, dist;
//  edge(int node, int dist) : node(node), dist(dist) {}
//};
//
//
//
//int n, m, s, t, u, v, p;
//
//vector<vector<edge>>g;
//vector<vector<edge>>gr
//vector<int> dist;
//vector<int> distR;
//
//
//int main(int argc, const char * argv[]){
//
//    while(scanf("%d %d", &n, &m) == 2){
//        if( n == 0 || m == 0) break;
//        scanf("%d %d",&s, &t);
//        for(int i = 0; i<m;i++){
//            scanf("%d %d %d", &u, &v, &p);
//                 g[u].push_back(edge(v,p));
//                 gr[v].push_back(edge(v,p));
//        }
//
//    }
//}
