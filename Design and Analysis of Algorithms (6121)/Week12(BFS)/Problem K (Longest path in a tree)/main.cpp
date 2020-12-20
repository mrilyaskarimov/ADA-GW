//
//  main.cpp
//  Problem K (Longest path in a tree)
//
//  Created by Ilyas Karimov on 16.12.20.
//

#include <cstdio>
#include <deque>
#include <vector>
#define INF 0x3F3F3F3F
using namespace std;

long long i, n, m, a, b, s, d, w;
vector<long long> dist;
vector<vector<pair<long long, long long> > > g;

void bfs(long long start)
{
  dist = vector<long long>(n + 1, INF);
  dist[start] = 0;

  deque<long long> q;
  q.push_back(start);

  while (!q.empty())
  {
    long long v = q.front(); q.pop_front();
    for (long long i = 0; i < g[v].size(); i++)
    {
      long long to = g[v][i].first;
      long long w = g[v][i].second;

      if (dist[to] > dist[v] + w)
      {
        dist[to] = dist[v] + w;
        if (w == 1)
          q.push_back(to);
        else
          q.push_front(to);
      }
    }
  }
}

int main(void)
{

  scanf("%lld", &n);
  g.resize(n + 1);
    for(long long j = 1; j<=n-1; j++){
        scanf("%lld %lld %lld", &a, &b, &w);
        g[a].push_back(make_pair(b, w));
        g[b].push_back(make_pair(a, w));
    }
    long long mx = -1, mv = -1;
    bfs(1);
    for(long long i = 1; i <=n; i++){
        if(dist[i]>mx){
            mx = dist[i];
            mv = i;
        }
    }
//    printf("%d %d\n",mv, mx);
    bfs(mv); 
    for(long long i = 1; i <=n; i++){
//        printf("real i and dist is: %d %d\n",i ,dist[i]);
        if(dist[i]>mx){
            mx = dist[i];
            mv = i;
        }
    }
    printf("%lld",mx);

 
  return 0;
}
