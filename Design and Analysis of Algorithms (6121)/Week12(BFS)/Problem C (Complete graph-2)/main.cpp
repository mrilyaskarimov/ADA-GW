//
//  main.cpp
//  Problem C (Complete graph-2)
//
//  Created by Ilyas Karimov on 16.12.20.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;
int i, j, n, m, f, a, finish, start;
int g[MAX][MAX], dist[MAX];

// breadth first search dtarts from the vertex `start`
void bfs(int start)
{
  // initialise array dist.
  // dist[i] = -1 means that vertex i is not visited
  memset(dist, -1, sizeof(dist));
  dist[start] = 0;
  // declare and initialize queue
  queue<int> q;
  q.push(start);
  // continue algorithm until queue is not empty
  while (!q.empty())
  {
    // take vertex v from the head of the queue
    // remove vertex v from the queue
    int v = q.front(); q.pop();
    // where can we go from v? Try an edge v -> to
    for (int to = 1; to <= n; to++)
      // if there exists an edge from v to to (g[v][to] == 1)
      // and vertex to is not visited yet (dist[to] = -1)
      if (g[v][to] && dist[to] == -1)
      {
        // push vertex to to queue, calculate dist[to]
          q.push(to);
          dist[to] = dist[v] + 1;
      }
  }
    
}

 int main(void)
{
// freopen("bfs.in", "r", stdin);
// read number of vertices n, starting s and final f vertex
    scanf("%d", &n);
// read adjacency matrix
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++){
        scanf("%d", &a);
        g[i][j] = g[j][i] = a;
    }
       
    scanf("%d %d", &start, &finish);
    bfs(start);
  // if dist[f] = -1, path is not found, set dist[f] = 0
    printf("%d", dist[finish]);
    return 0;
    
}

