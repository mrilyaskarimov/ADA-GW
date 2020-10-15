//
//  main.cpp
//  Problem B (Sorting Time)
//
//  Created by Ilyas Karimov on 10/14/20.
//

#include <iostream>
#include <stdio.h>

int i, n, h, m, s;

struct MyTime
{
  int hour, min, sec;
};

MyTime lst[1000];

int f(MyTime a, MyTime b)
{
  if ((a.hour == b.hour) && (a.min == b.min)) return a.sec < b.sec;
  if (a.hour == b.hour) return a.min < b.min;
  return a.hour < b.hour;
}

void swap(MyTime &i, MyTime &j)
{
  MyTime temp = i; i = j; j = temp;
}

int Partition(MyTime m[], int L, int R)
{
  MyTime x = m[R];
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

void QuickSort(MyTime m[], int L, int R)
{
  if (L < R)
  {
    int q = Partition(m, L, R);
    QuickSort(m, L, q - 1);
    QuickSort(m, q + 1, R);
  }
}

int main(void)
{
  //freopen("972.in","r",stdin);
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d %d %d", &lst[i].hour, &lst[i].min, &lst[i].sec);

  QuickSort(lst, 0, n - 1);
  
  for (i = 0; i < n; i++)
    printf("%d %d %d\n", lst[i].hour, lst[i].min, lst[i].sec);

  return 0;
}
