//
//  main.cpp
//  Problem F (Increasing subsequence)
//
//  Created by Ilyas Karimov on 25.11.20.
//

#include <cstdio>
#include <algorithm>
#define MAX 6
using namespace std;

int arr1[MAX], lis[MAX], L[MAX], res[MAX];
int i, n, len, pos;

void f(int pos){
    
}
int main(void)
{
    scanf("%d",&n);
    for(i = 0; i < n; i++) scanf("%d",&arr1[i]);

    for (len = i = 0; i < n; i++){
        pos = lower_bound(lis,lis+len,arr1[i]) - lis;
        lis[pos] = arr1[i];
        L[i] = pos;
        if (pos == len) len++;
    }

    printf("%d\n",len);
    /*
     For each element xi (1 ≤ i ≤ n), find the length of the LIS that ends at xi. Store these
     values in array L. This information is enough to find the LIS itself in linear time. The
     length of the LIS equals to the maximum number k in array L. Let this largest number k
     be in the index pos. Decrease pos until L[pos] becomes equal to k – 1. The current x[pos] will be the penultimate element in the LIS.
     And so on, we continue to move the pos index to the start of array L, stopping at the first
    positions for which L[pos] = k – 2, …, L[pos] = 0.*/
    int k = -1;
    for(i = 0; i < n; i++)
        if (L[i]>k) k = L[i];
    int m = n-1;
    int ptr = 0;
    while(true){
        if(k<0) break;
        while(L[m] != k ) m--;
        res[ptr++]= arr1[m];
        k--;
    }
    for (i = len-1; i >= 0 ;i--) printf("%d ", res[i]);
  return 0;
}
