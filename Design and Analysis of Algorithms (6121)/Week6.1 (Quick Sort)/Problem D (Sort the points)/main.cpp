//
//  main.cpp
//  Problem D (Sort the points)
//
//  Created by Ilyas Karimov on 30.10.20.
//

#include <iostream>
#include <stdio.h>
#define MAX 100001

using namespace std;

int i, c=1;

struct Point
{
  int x, y;
  Point() {};
  Point(int x, int y) : x(x), y(y) {};
};

Point lst[MAX];

int f(Point a, Point b)
{
    if(a.x + a.y == b.x + b.y){
        return a.x<b.x;
    }
    return a.x+a.y < b.x + b.y;
}

void swap(Point &i, Point &j)
{
  Point temp = i; i = j; j = temp;
}

int Partition(Point m[], int L, int R)
{
  Point x = m[R];
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

void QuickSort(Point m[], int L, int R)
{
  if (L < R)
  {
    int q = Partition(m, L, R);
    QuickSort(m, L, q - 1);
    QuickSort(m, q + 1, R);
  }
}

int main(int argc, const char * argv[]) {
    int c=1;
    while(scanf("%d %d", &lst[c].x, &lst[c].y)==2){
        c++;
    }
    c--;

    QuickSort(lst, 1, c);
    for (i = 1; i <= c; i++)
        printf("%d %d\n", lst[i].x, lst[i].y);
    printf("\n");
    return 0;
}
