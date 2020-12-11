//
//  main.cpp
//  Problem I (Almost Shorted Path)
//
//  Created by Ilyas Karimov on 03.12.20.
//
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define INF 0x3F3F3F3F
#define MAX 1001

using namespace std;

int n, m, s, t, u, v, p;

int dist[MAX][MAX], Shortest[MAX], AlmostShortest[MAX];
bool mask[MAX][MAX], avoid[MAX];

queue<int> q;

void Dijkstra(int m[], bool useMask)
{
 memset(avoid, false, sizeof(avoid));
 
 for(int i = 0; i < n; i++)
 {
  int minV = -1;
  int minDist = INF;
  
  for (int j = 0; j < n; j++)
  {
   if (!avoid[j] && minDist > m[j])
   {
       minV = j;
       minDist = m[j];
   }
  }
  
  if (minV < 0) break;
  
  avoid[minV] = true;
  
  for (int j = 0; j < n; j++)
  {
      if (!avoid[j] && (!useMask || !mask[minV][j])) m[j] = min(m[j], m[minV] + dist[minV][j]);
  }
 }
}

void BackTrack()
{
 memset(avoid, false, sizeof(avoid));
 q.push(t);
 avoid[t] = true;
 
 while (!q.empty())
 {
     int temp = q.front();
     q.pop();
  
  for (int i = 0; i < n; i++)
  {
   if (Shortest[temp] == Shortest[i] + dist[i][temp])
   {
    mask[i][temp] = true;
    if (!avoid[i]) q.push(i);
    avoid[i] = true;
   }
  }
 }
}

int main()
{
 while (scanf("%d %d", &n, &m) == 2)
 {
      if (n == 0 || m == 0) break;
      scanf("%d %d", &s, &t);
     
      memset(mask, false, sizeof(mask));
      memset(dist, INF, sizeof(dist));
      memset(Shortest, INF, sizeof(Shortest));
      memset(AlmostShortest, INF, sizeof(AlmostShortest));
      Shortest[s] = 0;
      AlmostShortest[s] = 0;
      
      for (int i = 0; i < n; i++)
      {
       dist[i][i] = 0;
      }
      
      for (int i = 0; i < m; i++)
      {
       scanf("%d %d %d", &u, &v, &p);
       dist[u][v] = p;
      }
      
      Dijkstra(Shortest, false);
      BackTrack();
      Dijkstra(AlmostShortest, true);
      
      if(AlmostShortest[t] == INF) printf("-1\n");
      else printf("%d\n", AlmostShortest[t]);
     }
}
