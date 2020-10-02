//
//  main.cpp
//  Problem A(Connected_components)
//
//  Created by Ilyas Karimov on 10/2/20.
//

#include <iostream>
#include <stdio.h>
#define MAX 101

int mas[MAX];

int Repr(int n)
{
  while (n != mas[n]) n = mas[n];
  return n;
}

void Union(int x, int y)
{
  int x1 = Repr(x), y1 = Repr(y);
  if (x1 == y1) return;
  mas[x1] = y1;
}

int i, j, v, n, count = 0;

int main(void)
{
  scanf("%d", &n);

  // put each vertex to a separate set
  for (i = 1; i <= n; i++) mas[i] = i;

  // read adjacency matrix
  for (i = 1; i <= n; i++)
  for (j = 1; j <= n; j++)
  {
    scanf("%d", &v);
    // for each edge (i, j) call Union(i,j)
    if (i < j && v == 1) Union(i, j);
  }

  // count the number of representatives
  for (i = 1; i <= n; i++)
    if (mas[i] == i) count++;
  printf("%d\n", count);
  return 0;
}
