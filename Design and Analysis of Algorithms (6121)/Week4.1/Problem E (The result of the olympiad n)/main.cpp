//
//  main.cpp
//  Problem E (The result of the olympiad n)
//
//  Created by Ilyas Karimov on 10/11/20.
//

#include <iostream>
#include <stdio.h>
#define MAX 102

int i, n;

struct Member
{
    int id, score;
    Member(int id = 0, int score = 0) : id(id), score(score) {};
};

Member lst[MAX];

int f(Member a, Member b)
{
    if (a.score == b.score) return a.id < b.id;
    return a.score > b.score;
}

int left(int i)
{
  return 2 * i;
}

int right(int i)
{
  return 2 * i + 1;
}

void swap(Member &i, Member &j)
{
  Member temp = i;  i = j; j = temp;
}

// max - heap
void heapify(Member a[], int i, int n)
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

int f(int a, int b){
    if(a%2){
        if(b%2){
            return a<b;
        }else
            return 1;
    }else{
        if(b%2){
            return 0;
        }else{
            return a>b;
        }
    }
}

void BuildHeap(Member a[], int n)
{
  for (int i = n / 2; i > 0; i--)
    heapify(a, i, n);
}

void HeapSort(Member a[], int n)
{
  BuildHeap(a, n);
  for (int i = n; i >= 2; i--)
  {
    swap(a[1], a[i]);
    heapify(a, 1, i - 1);
  }
}
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &lst[i].score);
        lst[i].id = i;
    }
    
    HeapSort(lst, n);
    for (i = 1; i <= n; i++)
      printf("%d ", lst[i].id);
    printf("\n");
    return 0;
}
