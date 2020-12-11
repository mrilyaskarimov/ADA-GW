#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#define MAX 1001
#define INF 0x3F3F3F3F
using namespace std;

int u, v, w, j, i, tests;
int n, m, start, fin;

set<int> avoid[MAX];

vector<int> dist;
vector<int> distR;

struct edge
{
  int node, dist;
  edge(int node, int dist ) : node(node), dist(dist) {}
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
        pq.push(edge(to,d[to]));
      }
    }
  }
}
int main(void)
{
  //freopen("2965.in","r",stdin);
    while(scanf("%d %d", &n, &m)==2){
        if(n == 0 && m == 0) break;
        scanf("%d %d", &start, &fin);
       
        g.resize(n+1);
        gR.resize(n+1);
        for(i = 0; i < m; i++){
              scanf("%d %d %d",&u,&v,&w);
              g[u].push_back(edge(v,w));
              gR[v].push_back(edge(u,w));
        }
        Dijkstra(g, dist, start);
        Dijkstra(gR,distR,fin);
        
        for(i = start; i< fin; i++){
            set<int>temp;
            for(j = 0; j< g[i].size(); j++){
                if((dist[i] + distR[g[i][j].node] + g[i][j].dist) == dist[fin]){
                    temp.insert(i);
                }
            }
            avoid[i] = temp;
        }
        Dijkstra(g, dist, start);
        if (dist[fin] == INF)
          printf("-1\n");
        else
          printf("%d\n",dist[fin]);
    }
   

 

  return 0;
}
