//
//  main.cpp
//  Problem A (Minimum spanning tree)
//
//  Created by Ilyas Karimov on 22.11.20.
//
#include <cstdio>
#include <algorithm>
#define MAXV 20001
#define MAXE 100001
using namespace std;

struct Edge
{
  int u, v, dist;
} e[MAXE];

int mas[MAXV], size[MAXV], res;

void swap(int &x, int &y)
{
  int temp = x; x = y; y = temp;
}

int Repr(int n)
{
  if (n == mas[n]) return n;
  return mas[n] = Repr(mas[n]);
}

int Union(int x,int y)
{
  x = Repr(x); y = Repr(y);
  if(x == y) return 0;

  if (size[x] < size[y]) swap(x,y);
  mas[y] = x;
  size[x] += size[y];
  return 1;
}

int lt(Edge a, Edge b)
{
  return (a.dist < b.dist);
}

int main(void)
{
  //freopen("981.in","r",stdin);
  int i, n, m;
  scanf("%d %d", &n, &m);
  for(i = 0; i < n; i++)
  {
    mas[i] = i;
    size[i] = 1;
  }

  for(i = 0; i < m; i++)
    scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].dist);

  sort(e,e+m,lt);
  
  res = 0;
  for(i = 0; i < m; i++)
    if (Union(e[i].u,e[i].v)) {
        printf("%d %d\n",e[i].u, e[i].v);
        res += e[i].dist;
    }
  printf("%d\n",res);

  return 0;
}
