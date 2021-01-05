#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;
int i, j, a, b, n, m, s, f, optDistance, res = 0;
vector<int> distS, distF;
vector<vector<int>> g;
void bfs(int start, vector<int> &dist)
{
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int i = 0; i < g[v].size(); i++)
        {
            int to = g[v][i];
            if (dist[to] == -1)
            {
                q.push(to);
                dist[to] = dist[v] + 1;
            }
        }
    }
}
int main(void)
{
    scanf("%d %d %d %d", &n, &m, &s, &f);
    g.resize(n + 1);
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    distS.resize(n + 1);
    distF.resize(n + 1);
    for (i = 0; i < distS.size(); i++)
    {
        distS[i] = -1;
        distF[i] = -1;
    }
    bfs(s, distS);
    bfs(f, distF);
    optDistance = distS[f];
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (!(distS[i] + 1 + distF[j] < optDistance || distS[j] + 1 + distF[i] < optDistance)) res++;
        }
    }
    res = res - m;
    printf("%d ", res);
}
