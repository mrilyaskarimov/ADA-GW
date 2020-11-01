//
//  main.cpp
//  Problem C (The results of the Olympiad)
//
//  Created by Ilyas Karimov on 30.10.20.
//

#include <iostream>
#include <stdio.h>
#define MAX 102

int i, n;

struct Member
{
    int id, score;
    Member(int id = 0, int score = 0):id(id), score(score) {};
};

Member lst[MAX];

int f(Member a, Member b)
{
    if (a.score == b.score) return a.id < b.id;
    return a.score > b.score;
}

void swap(Member &i, Member &j)
{
  Member temp = i; i = j; j = temp;
}

int Partition(Member m[], int L, int R)
{
  Member x = m[R];
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

void QuickSort(Member m[], int L, int R)
{
  if (L < R)
  {
    int q = Partition(m, L, R);
    QuickSort(m, L, q - 1);
    QuickSort(m, q + 1, R);
  }
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
        for (i = 1; i <= n; i++){
            scanf("%d", &lst[i].score);
            lst[i].id = i;
        }
    
    QuickSort(lst, 1, n );
        for (i = 1; i <= n; i++)
            printf("%d ", lst[i].id);
        printf("\n");
}
