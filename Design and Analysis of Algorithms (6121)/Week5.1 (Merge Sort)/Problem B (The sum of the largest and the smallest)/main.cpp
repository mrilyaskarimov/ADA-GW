//
//  main.cpp
//  Problem B (The sum of the largest and the smallest)
//
//  Created by Ilyas Karimov on 10/7/20.
//

#include <iostream>

int arr[1001];
int FindMin(int left, int right)
{
  if (left == right) return arr[left];
  int middle = (left + right) / 2;
  int u = FindMin(left, middle);
  int v = FindMin(middle + 1, right);
  return (u < v) ? u : v;
}
int FindMax(int left, int right)
{
  if (left == right) return arr[left];
  int middle = (left + right) / 2;
  int u = FindMax(left, middle);
  int v = FindMax(middle + 1, right);
  return (u < v) ? v : u;
}


int main(int argc, const char * argv[]) {
    int num;

    scanf("%d", &num);
    memset(arr, 0, sizeof(arr));
    for(int i =0; i<num;i++){
        scanf("%d", &arr[i]);
    }
    printf("%d", (FindMin(0, num-1) + FindMax(0, num-1)));

}
