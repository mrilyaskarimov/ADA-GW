//
//  main.cpp
//  Problem E (Sort even and odd numbers)
//
//  Created by Ilyas Karimov on 30.10.20.
//

#include <iostream>
#define MAX 1001

int a[MAX], n;
int abs(int n)
{
    if(n>0) return n;
    else return -n;
}

int f(int a, int b){
    if(abs(a%2) != abs(b%2)) return abs(a%2) > abs(b%2);  // odd numbers come first, then even numbers
    if(abs(a%2 == 0)) return a>b; // if even numbers, decreasing order
    else return a < b;              // if odd numbers, increasing order.
}

void swap(int i, int j)
{
  int temp = i; i = j; j = temp;
}

int Partition(int m[], int L, int R)
{
  int x = m[R];
  int i = L - 1, j;
  for (j = L; j < R; j++)
    if (f(m[j], x))
    {
      i++;
      swap(m[i], m[j]);
    }
  swap(m[i + 1], m[R]);
  return i + 1;
}

void QuickSort(int a[], int L, int R)
{
  if (L < R)
  {
    int q = Partition(a, L, R);
    QuickSort(a, L, q - 1);
    QuickSort(a, q + 1, R);
  }
}
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    
    QuickSort(a, 1, n);
    for (int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    
    return 0;
}
