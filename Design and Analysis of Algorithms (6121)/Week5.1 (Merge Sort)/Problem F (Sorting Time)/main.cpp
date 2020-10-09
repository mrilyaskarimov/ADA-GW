//
//  main.cpp
//  Problem F (Sorting Time)
//
//  Created by Ilyas Karimov on 10/7/20.
//

#include <iostream>
#include <vector>

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

struct MyTime
{
  int hour, min, sec;
  MyTime() {};
  MyTime(MyTime &a) : hour(a.hour), min(a.min), sec(a.sec) {};
};

vector <MyTime> vectime;
int f(MyTime a, MyTime b)
{
if ((a.hour == b.hour) && (a.min == b.min)) return a.sec < b.sec;
if (a.hour == b.hour) return a.min < b.min;
return a.hour < b.hour;
}

int main(int argc, const char * argv[]) {
    int num;
    int hour, min, sec;
    scanf("%d", &num);
    for( int i =0; i< num; i++){
        scanf("%d %d %d", &hour, &min, &sec);
        MyTime t (hour, min, sec);
        
    }

