//
//  main.cpp
//  Problem N (Sort the points by coordinates)
//
//  Created by Ilyas Karimov on 17.10.20.
//  Sort the points by coordinates - HEAP SORT

#include <iostream>

using namespace std;
#define MAX 100001

using namespace std;

struct Point
{
  int x, y;
  Point() {};
  Point(int x, int y) : x(x), y(y) {};
};

Point lst[MAX];

int f(Point a, Point b)
{
    if(a.x == b.x){
        return a.y>b.y;
    }
    return a.x < b.x;
}

int left(int i)
{
  return 2 * i;
}

int right(int i)
{
  return 2 * i + 1;
}

void swap(Point &i, Point &j)
{
  Point temp = i;  i = j; j = temp;
}

// from max heap
void heapify(Point a[], int i, int n, int f(Point a, Point b))
{
  int largest = 0;
  int l = left(i);
  int r = right(i);

  if (l <= n && f(lst[i], lst[l])) largest = l;
  else largest = i;
  if (r <= n && f(lst[largest], lst[r])) largest = r;

  if (largest != i)
  {
    swap(lst[i], lst[largest]);
    heapify(a, largest, n,f );
  }
}

void BuildHeap(Point a[], int n, int f (Point a, Point b))
{
  for (int i = n / 2; i > 0; i--)
    heapify(a, i, n, f);
}

void HeapSort(Point a[], int n, int f(Point a, Point b))
{
  BuildHeap(a, n,f );
  for (int i = n; i >= 2; i--)
  {
    swap(a[1], a[i]);
    heapify(a, 1, i - 1, f);
  }
}

int main(void)
{
    int c=1;
    while(scanf("%d %d", &lst[c].x, &lst[c].y)==2)  c++;
    
    c--;
    HeapSort(lst, c, f);

    for (int i = 1; i <= c; i++)
        printf("%d %d\n", lst[i].x, lst[i].y);
}
