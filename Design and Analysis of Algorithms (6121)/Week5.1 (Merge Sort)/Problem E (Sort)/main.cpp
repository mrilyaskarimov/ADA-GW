//
//  main.cpp
//  Problem E (Sort)
//
//  Created by Ilyas Karimov on 10/8/20.
//

#include <iostream>
using namespace std;

void merge(int *a, int bleft, int bright, int cleft, int cright)
{
  // a[bleft..bright] and a[cleft..cright]
  // are merged into a[bleft..cright]
  int i, left = bleft, len = cright - bleft + 1;
  int *res = new int[len];
  for (i = 0; i < len; i++)
  {
    if ((bleft > bright) || (cleft > cright)) break;
    if (a[bleft] <= a[cleft]) res[i] = a[bleft], bleft++;
    else res[i] = a[cleft], cleft++;
  }

  while (bleft <= bright) res[i++] = a[bleft++];
  while (cleft <= cright) res[i++] = a[cleft++];

  for (i = left; i < left + len; i++) a[i] = res[i - left];
  delete[] res;
}

void mergeSort(int *a, int left, int right)
{
  if (left >= right) return;
  int middle = (left + right) / 2;
  mergeSort(a, left, middle);
  mergeSort(a, middle + 1, right);
  merge(a, left, middle, middle + 1, right);
}

int m[1001], i, n;

int main(void)
{
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d", &m[i]);

  mergeSort(m, 1, n);

  for (i = 1; i <= n; i++)
    printf("%d ", m[i]);
  printf("\n");
  return 0;
}
