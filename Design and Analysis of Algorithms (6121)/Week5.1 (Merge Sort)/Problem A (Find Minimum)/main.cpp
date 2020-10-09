//
//  main.cpp
//  Problem A (Find Minimum)
//
//  Created by Ilyas Karimov on 10/7/20.
//

#include <iostream>

using namespace std;

int arr[1001];

int FindMin(int left, int right)
{
  if (left == right) return arr[left];
  int middle = (left + right) / 2;
  int u = FindMin(left, middle);
  int v = FindMin(middle + 1, right);
  return (u < v) ? u : v;
}

int main(int argc, const char * argv[]) {
    int n;
    memset(arr, 0, sizeof(arr));
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d", FindMin(1, n));
}
