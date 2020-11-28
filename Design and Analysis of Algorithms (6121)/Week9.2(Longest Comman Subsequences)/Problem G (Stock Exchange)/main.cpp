//
//  main.cpp
//  Problem G (Stock Exchange)
//
//  Created by Ilyas Karimov on 25.11.20.
//


#include <cstdio>
#include <algorithm>
#define MAX 100001
using namespace std;

int arr1[MAX], lis[MAX], L[MAX], res[MAX];
int i, n, len, pos;

void f(int pos){
    
}
int main(void)
{
    while(scanf("%d",&n)==1){
        for(i = 0; i < n; i++) scanf("%d",&arr1[i]);
        for (len = i = 0; i < n; i++){
            pos = lower_bound(lis,lis+len,arr1[i]) - lis;
            lis[pos] = arr1[i];
            L[i] = pos;
            if (pos == len) len++;
        }
        printf("%d\n",len);
    }
 
    
    
  return 0;
}

