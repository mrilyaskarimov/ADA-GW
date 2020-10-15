//
//  main.cpp
//  Problem A (Sorting)
//
//  Created by Ilyas Karimov on 10/14/20.
//

#include <iostream>
int m[1001];
int i, n;

void swap(int &i, int &j)
{
  int temp = i; i = j; j = temp;
}

int Partition(int L, int R)
{
  int x = m[L], i = L - 1, j = R + 1;
  while (1)
  {
    do j--; while (m[j] > x);
    do i++; while (m[i] < x);
    if (i < j) swap(m[i], m[j]); else return j;
  }
}

void QuickSort(int L, int R)
{
  if (L < R)
  {
    int q = Partition(L, R);
    QuickSort(L, q); QuickSort(q + 1, R);
  }
}

int main(void)
{
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &m[i]);

  QuickSort(0, n - 1);

  for (i = 0; i < n; i++) printf("%d ", m[i]);
  printf("\n");
  return 0;
}

