//
//  main.cpp
//  Problem F (Dangerous route)
//
//  Created by Ilyas Karimov on 18.10.20.


// In order to sort them, I used Heapsort

#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 150001
using namespace std;

vector<int> parent, depth;
vector <string> answers;

int Repr(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = Repr(parent[v]);
}

void Union(int x, int y)
{
    x = Repr(x); y = Repr(y);
    if (x == y) return;
    if (depth[x] < depth[y]) parent[x] = y;
    else parent[y] = x;
    if (depth[x] == depth[y]) depth[x]++;
}

struct DPoint
{
    int a, b, c;
    DPoint() {};
    DPoint(int a, int b, int c) : a(a), b(b), c(c) {};
};
DPoint lst[MAX];

int f(DPoint x, DPoint y)
{
    if(x.c== y.c && x.a == y.a){
        return x.b<y.b;
    }
    if(x.c == y.c) {
        return x.a<y.a;
    }
    return x.c < y.c;
}

int left(int i)
{
  return 2 * i;
}

int right(int i)
{
  return 2 * i + 1;
}

void swap(DPoint &i, DPoint &j)
{
  DPoint temp = i;  i = j; j = temp;
}

// max - heap
void heapify(DPoint a[], int i, int n, int f(DPoint a, DPoint b))
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
      heapify(a, largest, n, f);
    }
}

void BuildHeap(DPoint a[], int n, int f(DPoint a, DPoint b))
{
  for (int i = n / 2; i > 0; i--)
    heapify(a, i, n, f);
}

void HeapSort(DPoint a[], int n, int f(DPoint a, DPoint b))
{
  BuildHeap(a, n, f);
  for (int i = n; i >= 2; i--)
  {
    swap(a[1], a[i]);
    heapify(a, 1, i - 1, f );
  }
}
int main(int argc, const char * argv[]) {
    int n, m;

    scanf("%d %d",&n,&m);
    
    parent.resize(n+1);
    depth.resize(n+1);
    
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        depth[i] = 0;
    }

    for (int i = 1; i <= m; i++){
        scanf("%d %d %d", &lst[i].a, &lst[i].b, &lst[i].c);
    }
    HeapSort(lst, m, f);
    printf("\n");
    for (int i = 1; i <= m; i++){
        printf("%d %d %d\n", lst[i].a, lst[i].b, lst[i].c);
        Union(lst[i].a, lst[i].b);
        if(Repr(1) == Repr(n)) {
            printf("%d", lst[i].c);
            return 0;
        }
    }

}
