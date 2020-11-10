//  main.cpp
//  Problem A (Minimum Sum)
//
//  Created by Ilyas Karimov on 28.10.20.
//

#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;
int m[MAX],n[MAX], i;

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
int PartitionDesc(int L, int R)
{
  int x = n[L], i = L - 1, j = R + 1;
  while (1)
  {
    do j--; while (n[j] < x);
    do i++; while (n[i] > x);
    if (i < j) swap(n[i], n[j]); else return j;
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
void QuickSortDesc(int L, int R)
{
  if (L < R)
  {
    int q = PartitionDesc(L, R);
    QuickSortDesc(L, q); QuickSortDesc(q + 1, R);
  }
}

int main(int argc, const char * argv[]) {
    int num;
    long long res = 0;
    scanf("%d", &num);
    for(int i=0;i<num;i++) scanf("%d", &m[i]);
    for(int i=0;i<num;i++) scanf("%d", &n[i]);
    
    QuickSort(0, num-1);
    QuickSortDesc(0, num-1);
    

    for(int i=0;i<num;i++) res += m[i]*n[i];
    printf("%lld", res);
    
}
