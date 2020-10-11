#include <stdio.h>
#define MAX 1001

int i, n;

struct Point
{
  int hour, min, sec;
  Point() {};
  Point(Point &a) : hour(a.hour), min(a.min), sec(a.sec) {};
};

Point lst[MAX];

int f(Point a, Point b)
{
  if ((a.hour == b.hour) && (a.min == b.min)) return a.sec < b.sec;
  if (a.hour == b.hour) return a.min < b.min;
  return a.hour < b.hou
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

// max - heap
void heapify(Point a[], int i, int n)
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
    heapify(a, largest, n);
  }
}

void BuildHeap(Point a[], int n)
{
  for (int i = n / 2; i > 0; i--)
    heapify(a, i, n);
}

void HeapSort(Point a[], int n)
{
  BuildHeap(a, n);
  for (int i = n; i >= 2; i--)
  {
    swap(a[1], a[i]);
    heapify(a, 1, i - 1);
  }
}

int main(void)
{
  //freopen("972.in", "r", stdin);
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d %d %d", &lst[i].hour, &lst[i].min, &lst[i].sec);

  HeapSort(lst, n);

  for (i = 1; i <= n; i++)
    printf("%d %d %d\n", lst[i].hour, lst[i].min, lst[i].sec);
  printf("\n");
  return 0;
}
