//
//  main.cpp
//  Problem G (Bitmap)
//
//  Created by Ilyas Karimov on 16.12.20.
//

#include <iostream>
#include <string>
#include <cstring>
#include <deque>
#define INF 0x3F3F3F3F
#define MAX 1002
using namespace std;

int i, j, tests, n, m;
string g[MAX];
int dist[MAX][MAX];

deque<pair<int, int> > q; // (x, y)

void Add(int x, int y, int d)
{
  if ((x < 1) || (x > n) || (y < 1) || (y > m)) return;
  if (dist[x][y] != INF) return;
  dist[x][y] = d;
  q.push_back(make_pair(x, y));
}

void bfs(void)
{
  int x, y;
  while (!q.empty())
  {
    pair<int, int> temp = q.front();
    q.pop_front();
    x = temp.first; y = temp.second;
    Add(x + 1, y, dist[x][y] + 1); Add(x - 1, y, dist[x][y] + 1);
    Add(x, y + 1, dist[x][y] + 1); Add(x, y - 1, dist[x][y] + 1);
  }
}


int main(void)
{
  //freopen("1.dat", "r", stdin);
  cin >> tests;
  while (tests--)
  {
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
      cin >> g[i];
      g[i] = " " + g[i];
    }
    memset(dist, 0x3F, sizeof(dist));

    for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (g[i][j] == '1')
      {
        q.push_back(make_pair(i, j));
        dist[i][j] = 0;
      }

    bfs();

    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= m; j++)
        cout << dist[i][j] << " ";
      cout << endl;
    }
  }
  return 0;
}
