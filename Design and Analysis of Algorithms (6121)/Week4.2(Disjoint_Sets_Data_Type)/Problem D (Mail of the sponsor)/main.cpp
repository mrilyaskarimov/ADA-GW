//
//  main.cpp
//  Problem D (Mail of the sponsor)
//
//  Created by Ilyas Karimov on 10/8/20.
//

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> parent, depth;
int c, i, n, s, k, a, b;

int Repr(int v)
{
  if (v == parent[v]) return v;
  return parent[v] = Repr(parent[v]);
}

void Union(int x, int y)
{
  x = Repr(x); y = Repr(y);
  if (x == y) return;
  if (depth[x] < depth[y]) swap(x,y);
  parent[y] = x;
  if (depth[x] == depth[y]) depth[x]++;
}

int main(void)
{
  scanf("%d %d %d",&n,&s,&k);
  parent.resize(n+1);
  depth.resize(n+1);
  for(i = 0; i <= n; i++) parent[i] = i;

  for(i = 0; i < k; i++)
  {
    scanf("%d %d",&a,&b);
    Union(a,b);
  }

  for(c = 0, i = 1; i <= n; i++)
    if(parent[i] == i) c++;

  printf("%d\n",c-1);
  return 0;
}
